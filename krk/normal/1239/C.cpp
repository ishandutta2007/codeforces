#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;
const int Maxm = 524288;
const ll Inf = 1000000000000000000ll;

int n, p;
int T[Maxn];
ll st[Maxm];
ll res[Maxn];
ll cur, nxt;
vector <int> Q;
int pnt;
set <int> S;

void Union(int v) { st[v] = min(st[2 * v], st[2 * v + 1]); }

void Create(int v, int l, int r)
{
    if (l == r) st[v] = T[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

int Get(int v, int l, int r, ll tim)
{
    if (l == r) { st[v] = Inf; return l; }
    else {
        int m = l + r >> 1;
        int res = 0;
        if (st[2 * v] <= tim) res = Get(2 * v, l, m, tim);
        else res = Get(2 * v + 1, m + 1, r, tim);
        Union(v);
        return res;
    }
}

ll getMin(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        ll res = Inf;
        if (a <= m) res = min(res, getMin(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = min(res, getMin(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &T[i]);
    Create(1, 0, n - 1);
    while (pnt < n)
        if (pnt == Q.size()) {
            cur = max(cur, getMin(1, 0, n - 1, 0, n - 1));
            int ind = Get(1, 0, n - 1, cur);
            nxt = cur + p;
            Q.push_back(ind); S.insert(ind);
        } else {
            ll oth = *S.begin() > 0? getMin(1, 0, n - 1, 0, *S.begin() - 1): Inf;
            if (nxt <= oth) {
                int ind = Q[pnt++]; S.erase(ind);
                res[ind] = nxt;
                cur = nxt; nxt += p;
            } else {
                int ind = Get(1, 0, n - 1, max(oth, cur));
                Q.push_back(ind); S.insert(ind);
            }
        }
    for (int i = 0; i < n; i++)
        printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}