#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int n;
vector <int> neigh[Maxn];
int P[Maxn];
vector <int> seq;
vector <int> V[Maxn];
int par[Maxn];
bool ok[Maxn];
ii myhash[Maxn];
int mylen[Maxn];
vector <ii> H;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii Extend(ii old, int siz)
{
    return ii((ll(old.first) * arg1 + ll(siz)) % mod1,
              (ll(old.second) * arg2 + ll(siz)) % mod2);
}

ii getMax(int v, int p = 0)
{
    P[v] = p;
    ii res = ii(0, v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii cand = getMax(u, v);
        cand.first++;
        if (cand > res) res = cand;
    }
    return res;
}

bool Merge(int a, int b)
{
    int dif = int(V[par[a]].size()) - int(V[par[b]].size());
    for (int i = 0; i < V[par[b]].size(); i++)
        if (V[par[a]][i + dif] != V[par[b]][i]) return false;
    par[b] = par[a];
    return true;
}

void Presolve(int v, int p = 0)
{
    par[v] = v;
    ok[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Presolve(u, v);
        if (ok[v]) {
            if (!ok[u]) ok[v] = false;
            if (V[par[v]].size() < V[par[u]].size())
                if (!Merge(u, v)) ok[v] = false;
                else myhash[v] = myhash[u];
            else if (!Merge(v, u)) ok[v] = false;
        }
    }
    if (ok[v]) {
        myhash[v] = V[par[v]].empty()? myhash[v]: Extend(myhash[v], V[par[v]].back());
        mylen[v] = V[par[v]].size();
        V[par[v]].push_back(neigh[v].size());
    }
}

ii Get(const vector <ii> &H, int len)
{
    int r = int(H.size()) - 1;
    int l = r - len + 1;
    ii res = H[r];
    if (l > 0) {
        l--;
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

int Solve(int v, int p, vector <ii> &H)
{
    if (ok[v] && Get(H, mylen[v]) == myhash[v]) return v;
    vector <int> bad;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii h = Extend(myhash[u], neigh[u].size());
        if (Get(H, mylen[u] + 1) != h) bad.push_back(u);
    }
    if (bad.size() >= 2) return -1;
    H.push_back(Extend(H.back(), neigh[v].size()));
    return Solve(bad[0], v, H);
    H.pop_back();
}

int main()
{
    srand(time(0));
    arg1 = rand() % 1000 + 50000;
    arg2 = rand() % 1000 + 500000;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &n);
    if (n == 1) { printf("1\n"); return 0; }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int b = getMax(1).second;
    int a = getMax(b).second;
    seq.push_back(a);
    while (a != b) {
        a = P[a];
        seq.push_back(a);
    }
    int mid = (int(seq.size()) - 2) / 2;
    Presolve(seq[mid], seq[mid + 1]);
    Presolve(seq[mid + 1], seq[mid]);
    if (ok[seq[mid]]) {
        H.clear(); H.push_back(ii(0, 0));
        ii h = ii(0, 0);
        for (int i = 0; i < V[par[seq[mid]]].size(); i++) {
            h = Extend(h, V[par[seq[mid]]][i]);
            H.push_back(h);
        }
        int res = Solve(seq[mid + 1], seq[mid], H);
        if (res != -1) { printf("%d\n", res); return 0; }
    }
    if (ok[seq[mid + 1]]) {
        H.clear(); H.push_back(ii(0, 0));
        ii h = ii(0, 0);
        for (int i = 0; i < V[par[seq[mid + 1]]].size(); i++) {
            h = Extend(h, V[par[seq[mid + 1]]][i]);
            H.push_back(h);
        }
        int res = Solve(seq[mid], seq[mid + 1], H);
        if (res != -1) { printf("%d\n", res); return 0; }
    }
    printf("-1\n");
    return 0;
}