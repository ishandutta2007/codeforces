#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

vector <int> add[Maxn], rem[Maxn];
int n, m;
int a[Maxn];
int l[Maxn], r[Maxn];
int best = -1, bi = 1;
vector <int> res;

void Update(int l, int r, int delt)
{
    for (int i = l; i <= r; i++)
        a[i] += delt;
}

int getRes()
{
    int mn = 1000000000, mx = -1000000000;
    for (int i = 1; i <= n; i++) {
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }
    return mx - mn;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r[i]);
        if (l[i] != 1) {
            add[1].push_back(i);
            rem[l[i]].push_back(i);
        }
        add[r[i] + 1].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < add[i].size(); j++) {
            int ind = add[i][j];
            Update(l[ind], r[ind], -1);
        }
        for (int j = 0; j < rem[i].size(); j++) {
            int ind = rem[i][j];
            Update(l[ind], r[ind], 1);
        }
        if (i == 1 || (!add[i].empty() || !rem[i].empty())) {
            int cand = getRes();
            if (cand > best) {
                best = cand; bi = i;
            }
        }
    }
    printf("%d\n", best);
    for (int i = 1; i <= m; i++)
        if (bi < l[i] || bi > r[i]) res.push_back(i);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}