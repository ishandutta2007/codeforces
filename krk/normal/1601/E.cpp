#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

struct node {
    ll sum, fl;
    int cnt;
};

int n, q, k;
int a[Maxn];
int m;
vector <node> st[Maxn];
vector <ii> S;
vector <ii> bylef[Maxn];
ll res[Maxn];

void downOn(int t, int v, ll f)
{
    st[t][v].sum += ll(st[t][v].cnt) * f;
    st[t][v].fl += f;
}

void Down(int t, int v)
{
    if (st[t][v].fl) {
        downOn(t, 2 * v, st[t][v].fl);
        downOn(t, 2 * v + 1, st[t][v].fl);
        st[t][v].fl = 0;
    }
}

void Union(int t, int v)
{
    st[t][v].sum = st[t][2 * v].sum + st[t][2 * v + 1].sum;
}

void Create(int t, int v, int l, int r)
{
    st[t][v].cnt = r - l + 1;
    st[t][v].fl = st[t][v].sum = 0;
    if (l < r) {
        int m = l + r >> 1;
        Create(t, 2 * v, l, m);
        Create(t, 2 * v + 1, m + 1, r);
    }
}

void Add(int t, int v, int l, int r, int a, int b, ll val)
{
    if (l == a && r == b) downOn(t, v, val);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (a <= m) Add(t, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Add(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(t, v);
    }
}

ll Get(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[t][v].sum;
    else {
        Down(t, v);
        ll res = 0;
        int m = l + r >> 1;
        if (a <= m) res += Get(t, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += Get(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

void Add(int row, int l, int r, ll val)
{
    for (int i = row + 1; i <= k; i += i & -i)
        Add(i, 1, 0, m, l, r, val);
}

ll Get(int row, int l, int r)
{
    ll res = 0;
    for (int i = row + 1; i > 0; i -= i & -i)
        res += Get(i, 1, 0, m, l, r);
    return res;
}

void Update(int l, int r, ll delt)
{
    int c1 = l / k, c2 = r / k;
    if (c1 == c2) {
        Add(l % k, c1, c2, delt);
        Add(r % k + 1, c1, c2, -delt);
    } else {
        Add(l % k, c1, c1, delt);
        if (c1 + 1 < c2)
            Add(0, c1 + 1, c2 - 1, delt);
        Add(0, c2, c2, delt);
        Add(r % k + 1, c2, c2, -delt);
    }
}

ll Solve(int lef, int rig)
{
   rig -= (rig % k - lef % k + k) % k;
   return Get(lef % k, lef / k, rig / k);
}

int main()
{
    scanf("%d %d %d", &n, &q, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    m = (n - 1) / k;
    int sz = 1;
    while (sz <= 4 * (m + 1)) sz <<= 1;
    for (int i = 1; i <= k; i++) {
        st[i].resize(sz);
        Create(i, 1, 0, m);
    }
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        l--; r--;
        bylef[l].push_back(ii(r, i));
    }
    for (int i = n - 1; i >= 0; i--) {
        int lst = i;
        while (!S.empty() && a[i] < a[S.back().first]) {
            Update(S.back().first, S.back().second, -a[S.back().first]);
            lst = S.back().second;
            S.pop_back();
        }
        Update(i, lst, a[i]);
        S.push_back(ii(i, lst));
        for (int j = 0; j < bylef[i].size(); j++)
            res[bylef[i][j].second] = Solve(i, bylef[i][j].first);
    }
    for (int i = 0; i < q; i++)
        printf("%I64d\n", res[i]);
    return 0;
}