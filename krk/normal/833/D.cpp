#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;
const int mod = 1000000007;

struct BIT {
    vector <int> un;
    vector <int> vals;
    void Clear() { un.clear(); }
    void clearVals() { fill(vals.begin(), vals.end(), 0); }
    void addUn(int x) 
    {
        if (un.empty() || un.back() != x)
            un.push_back(x);
    }
    void prepareVals() 
    {
        vals.resize(un.size() + 1);
        fill(vals.begin(), vals.end(), 0);
    }
    int Get(int x)
    {
        int res = 0;
        int ind = lower_bound(un.begin(), un.end(), -x) - un.begin();
        for (int i = ind + 1; i < vals.size(); i += i & -i)
            res += vals[i];
        return res;
    }
    void Insert(int x)
    {
        int ind = lower_bound(un.begin(), un.end(), x) - un.begin();
        for (int i = ind + 1; i > 0; i -= i & -i)
            vals[i]++;
    }
};

int n;
vector <iii> neigh[Maxn];
bool er[Maxn];
int cnt[Maxn];
vector <int> un;
vector <ii> un2;
vector <BIT> st;
int res = 1;

void clearSt()
{
    for (int i = 0; i < st.size(); i++)
        st[i].clearVals();
}

void prepareSt()
{
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    sort(un2.begin(), un2.end());
    st.resize(un.size() + 1);
    for (int i = 1; i < st.size(); i++)
        st[i].Clear();
    for (int i = 0; i < un2.size(); i++) {
        int ind = lower_bound(un.begin(), un.end(), un2[i].second) - un.begin();
        for (int j = ind + 1; j > 0; j -= j & -j)
            st[j].addUn(un2[i].first);
    }
    for (int i = 1; i < st.size(); i++)
        st[i].prepareVals();
}

int Get(int x, int y)
{
    int res = 0;
    int ind = lower_bound(un.begin(), un.end(), -x) - un.begin();
    for (int i = ind + 1; i < st.size(); i += i & -i)
        res += st[i].Get(y);
    return res;
}

void Insert(int x, int y)
{
    int ind = lower_bound(un.begin(), un.end(), x) - un.begin();
    for (int i = ind + 1; i > 0; i -= i & -i)
        st[i].Insert(y);
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int lim)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        if (cnt[u] > lim) return getCentroid(u, v, lim);
    }
    return v;
}

ii getNext(const ii &st, int wh)
{
    return wh == 0? ii(st.first - 1, st.second + 2): ii(st.first + 2, st.second - 1);
}

void Precompute(int v, int p, const ii &st)
{
    un.push_back(st.first);
    un2.push_back(ii(st.second, st.first));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        Precompute(u, v, getNext(st, neigh[v][i].second.second));
    }
}

void Give(int v, int p, const ii &st)
{
    Insert(st.first, st.second);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        Give(u, v, getNext(st, neigh[v][i].second.second));
    }
}

void Take(int v, int p, const ii &st, int val)
{
    res = ll(res) * toPower(val, Get(st.first, st.second)) % mod;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        Take(u, v, getNext(st, neigh[v][i].second.second), ll(val) * neigh[v][i].second.first % mod);
    }
}

void Solve(int v)
{
    Count(v, 0);
    int C = getCentroid(v, 0, cnt[v] / 2);
    un.clear();
    un2.clear();
    auto zer = ii(0, 0);
    Precompute(C, 0, zer);
    prepareSt();
    Insert(0, 0);
    for (int i = 0; i < neigh[C].size(); i++) {
        int u = neigh[C][i].first;
        if (er[u]) continue;
        Take(u, C, getNext(zer, neigh[C][i].second.second), neigh[C][i].second.first);
        Give(u, C, getNext(zer, neigh[C][i].second.second));
    }
    clearSt();
    for (int i = int(neigh[C].size()) - 1; i >= 0; i--) {
        int u = neigh[C][i].first;
        if (er[u]) continue;
        Take(u, C, getNext(zer, neigh[C][i].second.second), neigh[C][i].second.first);
        Give(u, C, getNext(zer, neigh[C][i].second.second));
    }
    er[C] = true;
    for (int i = 0; i < neigh[C].size(); i++) {
        int u = neigh[C][i].first;
        if (er[u]) continue;
        Solve(u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        neigh[a].push_back(iii(b, ii(c, d)));
        neigh[b].push_back(iii(a, ii(c, d)));
    }
    Solve(1);
    printf("%d\n", res);
    return 0;
}