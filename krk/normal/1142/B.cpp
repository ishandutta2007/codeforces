#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxk = 21;

int n, m, q;
int p[Maxn];
int nxt[Maxn];
int lst[Maxn];
int P[Maxn][Maxk];
int a[Maxn];
int ql[Maxn], qr[Maxn];
vector <int> quer[Maxn];
char qres[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        nxt[p[i]] = p[ni];
    }
    fill(lst, lst + n + 1, m);
    for (int j = 0; j < Maxk; j++)
        P[m][j] = m;
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &ql[i], &qr[i]); ql[i]--; qr[i]--;
        quer[ql[i]].push_back(i);
    }
    int mn = m;
    for (int i = m - 1; i >= 0; i--) {
        P[i][0] = lst[nxt[a[i]]];
        for (int j = 1; j < Maxk; j++)
            P[i][j] = P[P[i][j - 1]][j - 1];
        lst[a[i]] = i;
        int lvl = n - 1;
        int cur = i;
        for (int j = Maxk - 1; j >= 0; j--) if (1 << j <= lvl) {
            cur = P[cur][j];
            lvl -= 1 << j;
        }
        mn = min(mn, cur);
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            qres[ind] = qr[ind] >= mn? '1': '0';
        }
    }
    qres[q] = '\0';
    printf("%s\n", qres);
    return 0;
}