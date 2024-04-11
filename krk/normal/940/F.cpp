#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int Maxs = 2715;
const int Maxp = 100;

int n, q;
int a[Maxn];
vector <int> un;
vector <iii> mods;
int my[Maxn], has[Maxn];
int qt[Maxn], qa[Maxn], qb[Maxn], qc[Maxn];
int res[Maxn];
vector <ii> group[Maxp][Maxp];

void Add(int x, int delt)
{
    if (my[x]) has[my[x]]--;
    my[x] += delt;
    if (my[x]) has[my[x]]++;
}

int Get()
{
    for (int i = 1; ; i++)
        if (!has[i]) return i;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &qt[i], &qa[i], &qb[i]);
        if (qt[i] == 2) un.push_back(qb[i]);
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
    for (int i = 1; i <= q; i++) {
        qc[i] = mods.size();
        if (qt[i] == 1)
            if (qa[i] / Maxs == qb[i] / Maxs) {
                for (int j = qa[i]; j <= qb[i]; j++)
                    Add(a[j], 1);
                res[i] = Get();
                for (int j = qa[i]; j <= qb[i]; j++)
                    Add(a[j], -1);
            } else group[qa[i] / Maxs][qb[i] / Maxs].push_back(ii(qc[i], i));
        else {
            qb[i] = lower_bound(un.begin(), un.end(), qb[i]) - un.begin();
            mods.push_back(iii(qa[i], ii(a[qa[i]], qb[i])));
            a[qa[i]] = qb[i];
        }
    }
    int pnt = mods.size();
    for (int i = 0; i < Maxp; i++) {
        int L = (i + 1) * Maxs;
        int R = (i + 1) * Maxs;
        for (int j = i + 1; j < Maxp; j++)
            for (int l = 0; l < group[i][j].size(); l++) {
                int ind = group[i][j][l].second;
                while (R <= qb[ind]) Add(a[R++], 1);
                while (qb[ind] + 1 < R) Add(a[--R], -1);
                while (qa[ind] < L) Add(a[--L], 1);
                while (L < qa[ind]) Add(a[L++], -1);
                while (pnt > qc[ind]) {
                    pnt--;
                    if (L <= mods[pnt].first && mods[pnt].first < R)
                        Add(a[mods[pnt].first], -1);
                    a[mods[pnt].first] = mods[pnt].second.first;
                    if (L <= mods[pnt].first && mods[pnt].first < R)
                        Add(a[mods[pnt].first], 1);
                }
                while (pnt < qc[ind]) {
                    if (L <= mods[pnt].first && mods[pnt].first < R)
                        Add(a[mods[pnt].first], -1);
                    a[mods[pnt].first] = mods[pnt].second.second;
                    if (L <= mods[pnt].first && mods[pnt].first < R)
                        Add(a[mods[pnt].first], 1);
                    pnt++;
                }
                res[ind] = Get();
            }
        while (L < R)
            Add(a[L++], -1);
    }
    for (int i = 1; i <= q; i++) if (qt[i] == 1)
        printf("%d\n", res[i]);
    return 0;
}