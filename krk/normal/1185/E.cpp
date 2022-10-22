#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxl = 26;

int T;
int n, m;
char B[Maxn][Maxn];
vector <ii> my[Maxl];
ii res1[Maxl], res2[Maxl];

int getRes()
{
    int pnt = Maxl - 1;
    while (pnt >= 0 && my[pnt].empty()) pnt--;
    for (int i = pnt; i >= 0; i--) {
        int mnr = Maxn, mnc = Maxn;
        int mxr = -Maxn, mxc = -Maxn;
        if (my[i].empty()) {
            res1[i] = res1[i + 1];
            res2[i] = res2[i + 1];
        } else {
            for (int j = 0; j < my[i].size(); j++) {
                mnr = min(mnr, my[i][j].first);
                mxr = max(mxr, my[i][j].first);
                mnc = min(mnc, my[i][j].second);
                mxc = max(mxc, my[i][j].second);
            }
            if (mnr == mxr || mnc == mxc) {
                res1[i] = ii(mnr, mnc);
                res2[i] = ii(mxr, mxc);
                for (int r = mnr; r <= mxr; r++)
                    for (int c = mnc; c <= mxc; c++)
                        if (B[r][c] == i + 'a' || B[r][c] == '?')
                            B[r][c] = '?';
                        else return -1;
            } else return -1;
        }
    }
    return pnt + 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < Maxl; i++)
            my[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%s", B[i] + 1);
            for (int j = 1; j <= m; j++)
                if (islower(B[i][j]))
                    my[B[i][j] - 'a'].push_back(ii(i, j));
        }
        int mx = getRes();
        if (mx == -1) printf("NO\n");
        else {
            printf("YES\n");
            printf("%d\n", mx);
            for (int i = 0; i < mx; i++)
                printf("%d %d %d %d\n", res1[i].first, res1[i].second,
                                        res2[i].first, res2[i].second);
        }
    }
    return 0;
}