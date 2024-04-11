#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int k[Maxn];
ll sumk[Maxn];
map <int, ll> M;
ll st[Maxm], flag[Maxm];

void downOn(int v, int siz, ll f)
{
    st[v] += ll(siz) * f; flag[v] += f;
}

void Down(int v, int l, int m, int r)
{
    if (flag[v]) {
        downOn(2 * v, m + 1 - l, flag[v]);
        downOn(2 * v + 1, r - m, flag[v]);
        flag[v] = 0;
    }
}

void Union(int v)
{
    st[v] = st[2 * v] + st[2 * v + 1];
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = a[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Add(int v, int l, int r, int a, int b, ll val)
{
    if (l == a && r == b) downOn(v, r - l + 1, val);
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

ll Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        ll res = 0;
        if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

void Add(int ind, int x)
{
    if (x == 0) return;
    map <int, ll>::iterator it = M.upper_bound(ind), it2;
    it--;
    ll my = it->second + sumk[ind - 1] - sumk[it->first - 1];
    ll all = my + x;
    M[ind] = all;
    it = M.lower_bound(ind);
    it2 = it; it2++;
    int orig = ind;
    while (true) {
        if (it2 == M.end()) { Add(1, 1, n, ind, n, x); break; }
        int ind2 = it2->first;
        Add(1, 1, n, ind, ind2 - 1, x);
        x = all + sumk[ind2 - 1] - sumk[orig - 1] - it2->second;
        if (x <= 0) break;
        else { ind = ind2; M.erase(it2++); }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        M[i] = a[i];
    }
    Create(1, 1, n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &k[i]);
        sumk[i] = sumk[i - 1] + k[i];
    }
    int q; scanf("%d", &q);
    while (q--) {
        char typ; int a, b;
        scanf(" %c %d %d", &typ, &a, &b);
        if (typ == '+') Add(a, b);
        else printf("%I64d\n", Get(1, 1, n, a, b));
    }
    return 0;
}