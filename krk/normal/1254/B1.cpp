#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n;
int a[Maxn];
int s;
ll res = Inf;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 2; i <= s; i++) if (s % i == 0) {
        ll cand = 0;
        int got = 0;
        for (int j = 0; j + 1 < n; j++) {
            got += a[j];
            cand += min(got % i, (s - got) % i);
        }
        res = min(res, cand);
    }
    printf("%I64d\n", res >= Inf? -1ll: res);
    return 0;
}