#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 1000000007;

int n, t;
int H[Maxn], L[Maxn], R[Maxn];
int res[Maxn];
vector <int> un;
vector <ii> seq;
map <ii, int> M;
ii my[Maxm], st[Maxm];

void Update(int v, int l, int r, int a, int b, ii mx)
{
    if (l == a && r == b) {
        my[v] = max(my[v], mx);
        st[v] = max(st[v], mx);
    } else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), mx);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, mx);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
}

ii Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        ii res = my[v];
        int m = l + r >> 1;
        if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

int Get(int a, int b)
{
    return min(min(un[R[a]], un[R[b]]) - max(un[L[a]], un[L[b]]), res[b]);
}

void Add(const ii &key, int val)
{
    auto it = M.lower_bound(ii(key.first, 0));
    if (it != M.begin()) {
        it--;
        if (it->first.second >= key.first) {
            res[val] = max(res[val], Get(val, it->second));
            M.erase(it++);
        } else it++;
    }
    while (it != M.end() && it->first.first <= key.second) {
        res[val] = max(res[val], Get(val, it->second));
        M.erase(it++);
    }
    M.insert(make_pair(key, val));
}

int main()
{
    scanf("%d %d", &n, &t);
    un.push_back(-Inf);
    un.push_back(Inf);
    res[0] = 2 * Inf;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &H[i], &L[i], &R[i]);
        un.push_back(L[i]);
        un.push_back(R[i]);
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    L[0] = 0, R[0] = un.size() - 1;
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
        seq.push_back(ii(H[i], i));
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        Add(ii(L[ind], R[ind] - 1), ind);
        ii got = Get(1, 0, int(un.size()) - 1, L[ind], L[ind]);
        int lef = max(L[ind], L[got.second]), rig = min(R[ind] - 1, R[got.second] - 1);
        if (Get(1, 0, int(un.size()) - 1, lef, rig) == got)
            res[ind] = max(res[ind], Get(ind, got.second));
        got = Get(1, 0, int(un.size()) - 1, R[ind] - 1, R[ind] - 1);
        lef = max(L[ind], L[got.second]), rig = min(R[ind] - 1, R[got.second] - 1);
        if (Get(1, 0, int(un.size()) - 1, lef, rig) == got)
            res[ind] = max(res[ind], Get(ind, got.second));
        Update(1, 0, int(un.size()) - 1, L[ind], R[ind] - 1, ii(H[ind], ind));
    }
    int ans = 0;
    for (auto it: M)
        ans = max(ans, res[it.second]);
    printf("%d\n", ans);
    return 0;
}