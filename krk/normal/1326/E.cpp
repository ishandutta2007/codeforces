#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxm = 2097152;

int n;
int inp[Maxn];
int q;
int rem[Maxm], add[Maxm];

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    rem[v] = rem[lc] + max(0, rem[rc] - add[lc]);
    add[v] = max(0, add[lc] - rem[rc]) + add[rc];
}

void Add(int v, int l, int r, int x, int val)
{
    if (l == r)
        if (val > 0)
            if (rem[v] > 0) rem[v]--;
            else add[v]++;
        else if (add[v] > 0) add[v]--;
             else rem[v]++;
    else {
        int m = l + r >> 1;
        if (x <= m) Add(2 * v, l, m, x, val);
        else Add(2 * v + 1, m + 1, r, x, val);
        Union(v);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p; scanf("%d", &p);
        inp[p] = i;
    }
    int cur = n; Add(1, 1, n, inp[cur], 1);
    vector <int> res;
    for (int i = 1; i <= n; i++) {
        while (add[1] <= 0) {
            cur--;
            Add(1, 1, n, inp[cur], 1);
        }
        res.push_back(cur);
        int q; scanf("%d", &q);
        Add(1, 1, n, q, -1);
    }
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}