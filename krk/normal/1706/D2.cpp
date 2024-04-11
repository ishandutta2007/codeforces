#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, k;
int mn, mx;
int a[Maxn];
int cur[Maxn];
list <int> inds[Maxn];
int res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i <= mx; i++)
            inds[i].clear();
        mn = Maxn, mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cur[i] = 1;
            int val = a[i] / cur[i];
            mn = min(mn, val);
            mx = max(mx, val);
            inds[val].insert(inds[val].begin(), i);
        }
        res = Maxn;
        while (mn <= mx) {
            while (inds[mx].empty()) mx--;
            res = min(res, mx - mn);
            if (mn == mx) break;
            bool fall = false;
            while (!inds[mx].empty()) {
                int me = *inds[mx].begin(); inds[mx].erase(inds[mx].begin());
                cur[me] = a[me] / (a[me] / cur[me]) + 1;
                if (cur[me] > k) { fall = true; break; }
                int val = a[me] / cur[me];
                mn = min(mn, val);
                inds[val].insert(inds[val].begin(), me);
            }
            if (fall) break;
        }
        printf("%d\n", res);
    }
    return 0;
}