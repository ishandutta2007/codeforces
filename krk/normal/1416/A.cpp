#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Inf = 1000000000;

int T;
int n;
vector <int> inds[Maxn];
int a[Maxn], mn[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            inds[i].clear();
            mn[i] = Inf;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            inds[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int lst = -1, res = 0;
            for (int j = 0; j < inds[i].size(); j++) {
                int cur = inds[i][j];
                res = max(res, cur - lst);
                lst = cur;
            }
            res = max(res, n - lst);
            if (res <= n && mn[res] == Inf)
                mn[res] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) mn[i] = min(mn[i], mn[i - 1]);
            printf("%d%c", mn[i] == Inf? -1: mn[i], i + 1 <= n? ' ': '\n');
        }
    }
    return 0;
}