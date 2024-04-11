#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n, q;
int a[Maxn];
int cnt[Maxn];
set <int> hascnt[Maxn];
int BIT[Maxn];
vector <int> neigh[Maxn];
int qv[Maxn], ql[Maxn], qk[Maxn];
vector <int> quer[Maxn];
int res[Maxn];

void Add(int x, int delt)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] += delt;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Inc(int x)
{
    if (cnt[x] != 0) {
        Add(cnt[x], -1);
        hascnt[cnt[x]].erase(x);
    }
    cnt[x]++;
    Add(cnt[x], 1);
    hascnt[cnt[x]].insert(x);
}

void Dec(int x)
{
    Add(cnt[x], -1);
    hascnt[cnt[x]].erase(x);
    cnt[x]--;
    if (cnt[x] != 0) {
        Add(cnt[x], 1);
        hascnt[cnt[x]].insert(x);
    }
}

int Answer(int l, int k)
{
    k += Get(l - 1);
    int lef = l, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Get(mid) < k) lef = mid + 1;
        else rig = mid - 1;
    }
    int got = lef;
    if (got > n) return -1;
    return *hascnt[got].begin();
}

void Traverse(int v)
{
    Inc(a[v]);
    for (int i = 0; i < quer[v].size(); i++) {
        int ind = quer[v][i];
        res[ind] = Answer(ql[ind], qk[ind]);
    }
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
    Dec(a[v]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[i] = 0;
            hascnt[i].clear();
            BIT[i] = 0;
            neigh[i].clear();
            quer[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int p; scanf("%d", &p);
            neigh[p].push_back(i);
        }
        for (int i = 1; i <= q; i++) {
            scanf("%d %d %d", &qv[i], &ql[i], &qk[i]);
            quer[qv[i]].push_back(i);
        }
        Traverse(1);
        for (int i = 1; i <= q; i++)
            printf("%d%c", res[i], i + 1 <= q? ' ': '\n');
    }
    return 0;
}