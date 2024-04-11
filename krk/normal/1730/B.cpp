#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;
const int Inf = 1000000000;

int T;
int n;
int x[Maxn];
int t[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        int mn = Inf, mx = -Inf;
        for (int i = 0; i < n; i++) {
            mn = min(mn, x[i] - t[i]);
            mx = max(mx, x[i] + t[i]);
        }
        ld res = (mn + mx) / 2.0l;
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}