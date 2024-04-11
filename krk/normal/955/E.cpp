#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 300015;
const int Maxs = 2097152;
const int Inf = 2000000000;

int n;
int a[Maxn];
map <int, int> st[Maxs];
int res = Inf;
int rigind[Maxn], rigval[Maxn];
int lefval[Maxn];

void Clear(int v, int l, int r)
{
    st[v].clear();
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void addMap(map <int, int> &M, int key, int val)
{
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        if (it->second <= val) return;
    }
    it = M.lower_bound(key);
    while (it != M.end() && val <= it->second) M.erase(it++);
    M.insert(make_pair(key, val));
}

int getMin(int v, int l, int r, int a, int b, bool val)
{
    if (l == a && r == b)
        return st[v].empty()? Inf: (val? st[v].rbegin()->second: st[v].begin()->first);
    else {
        int res = Inf;
        int m = l + r >> 1;
        if (a <= m) res = min(res, getMin(2 * v, l, m, a, min(m, b), val));
        if (m + 1 <= b) res = min(res, getMin(2 * v + 1, m + 1, r, max(m + 1, a), b, val));
        return res;
    }
}

int getSmaller(int v, int l, int r, int a, int b, int ind)
{
    if (l == a && r == b) {
        auto it = st[v].lower_bound(ind);
        if (it == st[v].begin()) return Inf;
        it--;
        return it->second;
    } else {
        int res = Inf;
        int m = l + r >> 1;
        if (a <= m) res = min(res, getSmaller(2 * v, l, m, a, min(m, b), ind));
        if (m + 1 <= b) res = min(res, getSmaller(2 * v + 1, m + 1, r, max(m + 1, a), b, ind));
        return res;
    }
}

void Update(int v, int l, int r, int x, int key, int val)
{
    addMap(st[v], key, val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, key, val);
        else Update(2 * v + 1, m + 1, r, x, key, val);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i > 0; i--) {
        Update(1, 0, Maxm, a[i], i, a[i] + i);
        rigval[i] = getMin(1, 0, Maxm, 0, i - 1, true);
        if (rigval[i] < Inf) {
            rigval[i] -= i;
            rigind[i] = getMin(1, 0, Maxm, 0, i - 1, false);
            lefval[i] = getSmaller(1, 0, Maxm, i, Maxm, rigind[i]);
            if (lefval[i] < Inf) lefval[i] -= i;
        }
    }
    Clear(1, 0, Maxm);
    for (int i = 1; i <= n; i++) {
        int nrigval = getMin(1, 0, Maxm, i + 1 + Maxn, Maxm, true);
        if (nrigval < Inf) {
            rigval[i] = min(rigval[i], nrigval + i);
            rigind[i] = getMin(1, 0, Maxm, i + 1 + Maxn, Maxm, false);
            lefval[i] = getSmaller(1, 0, Maxm, 0, i + Maxn, rigind[i]);
            if (lefval[i] < Inf) lefval[i] += i;
        } else if (rigval[i] < Inf) {
            int nlefval = getSmaller(1, 0, Maxm, 0, i + Maxn, rigind[i]);
            if (nlefval < Inf) nlefval += i;
            lefval[i] = min(lefval[i], nlefval);
        }
        res = min(res, max(lefval[i], rigval[i]));
        Update(1, 0, Maxm, 2 * i - a[i] + Maxn, i, a[i] - i);
    }
    printf("%d\n", res < Inf? res: -1);
    return 0;
}