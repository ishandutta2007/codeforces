#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205 * 205;

int T;
int a, b, q;
int sum[Maxn];

ll Count(ll r)
{
    ll res = 0;
    res += r / (a * b) * ll(sum[a * b - 1]);
    res += sum[r % (a * b)];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &q);
        for (int i = 0; i < a * b; i++) {
            if (i % a % b != i % b % a)
                sum[i] = 1;
            else sum[i] = 0;
            if (i > 0) sum[i] += sum[i - 1];
        }
        for (int i = 0; i < q; i++) {
            ll l, r; scanf("%I64d %I64d", &l, &r);
            printf("%I64d%c", Count(r) - Count(l - 1), i + 1 < q? ' ': '\n');
        }
    }
    return 0;
}