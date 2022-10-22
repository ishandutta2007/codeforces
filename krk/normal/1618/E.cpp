#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int b[Maxn];
ll sum;
int res[Maxn];

ll Sum(ll x, ll y) { return (x + y) * (y - x + 1) / 2; }

bool Solve()
{
    ll s = Sum(1, n);
    if (sum % s) return false;
    sum /= s;
    for (int i = 0; i < n; i++) {
        int val = b[i] - b[(i - 1 + n) % n];
        if ((sum - val) % n) return false;
        ll got = (sum - val) / n;
        if (got < 1 || got > 1000000000) return false;
        res[i] = got;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            sum += b[i];
        }
        if (Solve()) {
            printf("YES\n");
            for (int i = 0; i < n; i++)
                printf("%d%c", res[i], i + 1 < n? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}