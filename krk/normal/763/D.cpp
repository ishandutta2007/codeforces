#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int n;
vector <int> neigh[Maxn];
map <ii, int> ID;
map <int, int> M;
int val[Maxn];
vector <int> my[Maxn];
vector <ii> L[Maxn], R[Maxn];
ii res;

int getID(const ii &p)
{
    auto it = ID.find(p);
    if (it == ID.end()) {
        int res = ID.size() + 1;
        ID.insert(make_pair(p, res));
        return res;
    }
    return it->second;
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Add(int id)
{
    auto it = M.find(id);
    if (it == M.end())
        M.insert(make_pair(id, 1));
    else it->second++;
}

void Rem(int id)
{
    auto it = M.find(id);
    if (--it->second == 0)
        M.erase(it);
}

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        my[v].push_back(val[u]);
    }
    sort(my[v].begin(), my[v].end());
    ii h = ii(0, 0);
    for (int i = 0; i < my[v].size(); i++) {
        h.first = (ll(h.first) * arg1 + ll(my[v][i])) % mod1;
        h.second = (ll(h.second) * arg2 + ll(my[v][i])) % mod2;
    }
    val[v] = getID(h);
    Add(val[v]);
}

void Solve(int v, int p, int tp);

void solveChildren(int v, int p)
{
    L[v].resize(my[v].size());
    R[v].resize(my[v].size());
    ii h = ii(0, 0);
    for (int i = 0; i < my[v].size(); i++) {
        h.first = (ll(h.first) * arg1 + ll(my[v][i])) % mod1;
        h.second = (ll(h.second) * arg2 + ll(my[v][i])) % mod2;
        L[v][i] = h;
    }
    h = ii(0, 0);
    for (int i = int(my[v].size()) - 1; i >= 0; i--) {
        int hm = int(my[v].size()) - 1 - i;
        h.first = (ll(h.first) + ll(pw1[hm]) * my[v][i]) % mod1;
        h.second = (ll(h.second) + ll(pw2[hm]) * my[v][i]) % mod2;
        R[v][i] = h;
    }
    int mem = val[v];
    Rem(val[v]);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        int ind = lower_bound(my[v].begin(), my[v].end(), val[u]) - my[v].begin();
        int hm = int(my[v].size()) - 1 - ind;
        h = ii(0, 0);
        if (ind > 0) {
            h.first = (ll(h.first) + ll(L[v][ind - 1].first) * pw1[hm]) % mod1;
            h.second = (ll(h.second) + ll(L[v][ind - 1].second) * pw2[hm]) % mod2;
        }
        if (hm > 0) {
            h.first = (ll(h.first) + R[v][ind + 1].first) % mod1;
            h.second = (ll(h.second) + R[v][ind + 1].second) % mod2;
        }
        val[v] = getID(h);
        Add(val[v]);
        Solve(u, v, val[v]);
        Rem(val[v]);
    }
    val[v] = mem;
    Add(val[v]);
}

void Solve(int v, int p, int tp)
{
    int mem = val[v];
    Rem(val[v]);
    int pnt = lower_bound(my[v].begin(), my[v].end(), tp) - my[v].begin();
    my[v].insert(my[v].begin() + pnt, tp);
    ii h = ii(0, 0);
    for (int i = 0; i < my[v].size(); i++) {
        h.first = (ll(h.first) * arg1 + ll(my[v][i])) % mod1;
        h.second = (ll(h.second) * arg2 + ll(my[v][i])) % mod2;
    }
    val[v] = getID(h);
    Add(val[v]);
    res = max(res, ii(M.size(), v));
    solveChildren(v, p);
    Rem(val[v]);
    val[v] = mem;
    Add(val[v]);
}

int main()
{
    mod1 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    arg1 = uniform_int_distribution<int>(100000, 1000000)(rng);
    arg2 = uniform_int_distribution<int>(100000, 1000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    res = ii(M.size(), 1);
    solveChildren(1, 0);
    printf("%d\n", res.second);
    return 0;
}