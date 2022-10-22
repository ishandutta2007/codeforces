#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef pair <ll, int> lli;

const int Maxn = 500005;
const int Maxm = 2097152;
const int lim = 1000000000;
const ll Inf = 1000000000000000000ll;

int nil = 2 * lim;
int n;
iii p[Maxn];
vector <int> un;
lli st[Maxm];
ll fl[Maxm];
ll best = 0;
int by = 2000000000, ba = 0;

void downOn(int v, ll f)
{
    st[v].first += f; fl[v] += f;
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
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = lli(nil - un[l], un[l]);
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, ll delt)
{
    if (l == a && r == b) downOn(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

lli Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        lli res = lli(-Inf, -1);
        int m = l + r >> 1;
        if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

bool Less(const iii &a, const iii &b)
{
    return a.first.second > b.first.second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i].first.first, &p[i].first.second, &p[i].second);
        if (p[i].first.first < p[i].first.second)
            swap(p[i].first.first, p[i].first.second);
        un.push_back(p[i].first.first);
        nil = min(nil, p[i].first.first);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    Create(1, 0, int(un.size()) - 1);
    sort(p, p + n, Less);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && p[j].first.second == p[i].first.second) {
            int ind = lower_bound(un.begin(), un.end(), p[j].first.first) - un.begin();
            Update(1, 0, int(un.size()) - 1, ind, int(un.size()) - 1, p[j].second);
            j++;
        }
        int ind = lower_bound(un.begin(), un.end(), p[i].first.second) - un.begin();
        lli cand = Get(1, 0, int(un.size()) - 1, ind, int(un.size()) - 1);
        if (cand.first + p[i].first.second - nil > best) {
            best = cand.first + p[i].first.second - nil;
            by = p[i].first.second;
            ba = cand.second - p[i].first.second;
        }
    }
    printf("%I64d\n", best);
    printf("%d %d %d %d\n", by, by, by + ba, by + ba);
    return 0;
}