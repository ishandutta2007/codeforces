#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 405;
const int MAXA = 160005;

int n, m, mat[MAXN][MAXN], last[MAXN][MAXN], nxt[MAXN][MAXN];
int ma[MAXN], ins[MAXN];
vector<pii> v[MAXA];
pii stk[MAXA]; int stksze;
pii dq[MAXN]; int lt, rt;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d", &mat[i][j]);

    int ans = 0;
    for (int lc=0; lc<m; lc++) {
        for (int i=0; i<MAXA; i++) v[i].clear();
        for (int i=0; i<n; i++)
            for (int j=lc; j<m; j++) {
                v[mat[i][j]].push_back(pii(i, j));
            }

        for (int i=0; i<MAXA; i++)
            if (!v[i].empty()) {
                stksze = 0;
                for (int j=0; j<v[i].size(); j++) {
                    int r = v[i][j].first, c = v[i][j].second;
                    while (stksze && c < stk[stksze-1].second) --stksze;
                    if (!stksze) last[r][c] = -1;
                    else last[r][c] = stk[stksze-1].first;
                    stk[stksze++] = v[i][j];
                }
                stksze = 0;
                for (int j=v[i].size()-1; j>=0; j--) {
                    int r = v[i][j].first, c = v[i][j].second;
                    while (stksze && c < stk[stksze-1].second) --stksze;
                    if (!stksze) nxt[r][c] = n;
                    else nxt[r][c] = stk[stksze-1].first;
                    stk[stksze++] = v[i][j];
                }
            }

        for (int i=0; i<n; i++) ma[i] = n;
        for (int rc=lc; rc<m; rc++) {
            for (int i=0; i<n; i++) ins[i] = n;
            for (int i=0; i<n; i++) {
                int p = last[i][rc];
                if (p != -1)
                    ins[p] = min(ins[p], i);
                p = nxt[i][rc];
                if (p != n)
                    ins[i] = min(ins[i], p);
            }
            lt = rt = 0;
            for (int i=0; i<n; i++) {
                while (lt != rt && ins[i] <= dq[rt-1].second) --rt;
                dq[rt++] = pii(i, ins[i]);
            }
            for (int i=0; i<n; i++) {
                ma[i] = min(ma[i], dq[lt].second);
                ans = max(ans, (rc-lc+1)*(ma[i]-i));
                if (dq[lt].first == i) ++lt;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}