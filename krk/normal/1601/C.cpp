#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;
const int Maxm = 8388608;

int T;
int n, m;
int a[Maxn], b[Maxn];
vector <int> un;
int BIT[Maxn];
int st[Maxm], fl[Maxm];
vector <int> inds[Maxn];
int cnt[Maxn];
ll res;

void Insert(int x)
{
    for (int i = x + 1; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x + 1; i <= un.size(); i += i & -i)
        res += BIT[i];
    return res;
}

void downOn(int v, int add)
{
    st[v] += add;
    fl[v] += add;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    fl[v] = 0;
    if (l == r) st[v] = l;
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Add(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        un.clear();
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        fill(BIT + 1, BIT + int(un.size()) + 2, 0);
        res = 0;
        for (int i = 1; i <= n; i++) {
            int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            res += Get(ind + 1);
            Insert(ind);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            un.push_back(b[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        for (int i = 0; i < un.size(); i++) {
            inds[i].clear();
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            inds[a[i]].push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            b[i] = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
            cnt[b[i]]++;
        }
        Create(1, 0, n);
        for (int i = 0; i < un.size(); i++) {
            for (int j = 0; j < inds[i].size(); j++) {
                int ind = inds[i][j];
                Add(1, 0, n, ind, n, -1);
            }
            res += ll(cnt[i]) * st[1];
            for (int j = 0; j < inds[i].size(); j++) {
                int ind = inds[i][j];
                Add(1, 0, n, 0, ind - 1, 1);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}