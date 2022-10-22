#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <int, char> ic;

const int Maxn = 100005;
const int Maxm = 20;
const int Maxk = 103;

struct Hsh {
    int a, b, len;
    Hsh(int a = 0, int b = 0, int len = 0): a(a), b(b), len(len) {}
    bool operator==(const Hsh &oth) const {
        return a == oth.a && b == oth.b && len == oth.len;
    }
};

struct Query {
    int ind, delt;
    ii wh;
    Query(int ind = 0, int delt = 0, ii wh = ii(0, 0)): ind(ind), delt(delt), wh(wh) {}
};

char tmp[Maxk];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int iarg1, iarg2;
int pw1[Maxn], pw2[Maxn];
int ipw1[Maxn], ipw2[Maxn];
int n;
vector <ic> neigh[Maxn];
Hsh H[Maxn], R[Maxn];
int L[Maxn], P[Maxn][Maxm];
int q;
int qa[Maxn], qb[Maxn];
Hsh qH[Maxn], qR[Maxn];
int qres[Maxn];
int tmpA[Maxk], tmpB[Maxk];
vector <ii> un[Maxk];
vector <int> cnt[Maxk];
Hsh my[Maxn][Maxk];
int f[Maxn][Maxk];
vector <Query> quer[Maxn];

int toPower(int a, int p, int mod)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x, int mod) { return toPower(x, mod - 2, mod); }

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

Hsh toHash(char let) { return Hsh(let - 'a' + 1, let - 'a' + 1, 1); }

Hsh Join(const Hsh &A, const Hsh &B)
{
    Hsh C;
    C.a = (ll(A.a) * pw1[B.len] + ll(B.a)) % mod1;
    C.b = (ll(A.b) * pw2[B.len] + ll(B.b)) % mod2;
    C.len = A.len + B.len;
    return C;
}

Hsh removeFront(const Hsh &A, const Hsh &B)
{
    Hsh C;
    C.a = (ll(A.a) - ll(pw1[A.len - B.len]) * B.a % mod1 + mod1) % mod1;
    C.b = (ll(A.b) - ll(pw2[A.len - B.len]) * B.b % mod2 + mod2) % mod2;
    C.len = A.len - B.len;
    return C;
}

Hsh removeBack(const Hsh &A, const Hsh &B)
{
    Hsh C;
    C.a = (ll(A.a) - ll(B.a) + ll(mod1)) * ipw1[B.len] % mod1;
    C.b = (ll(A.b) - ll(B.b) + ll(mod2)) * ipw2[B.len] % mod2;
    C.len = A.len - B.len;
    return C;
}

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (P[v][0] == u) continue;
        P[u][0] = v; L[u] = L[v] + 1;
        auto h = toHash(neigh[v][i].second);
        H[u] = Join(h, H[v]);
        R[u] = Join(R[v], h);
        Traverse(u);
    }
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int goUp(int a, int by)
{
    for (int i = Maxm - 1; i >= 0; i--)
        if ((1 << i) <= by) {
            by -= 1 << i;
            a = P[a][i];
        }
    return a;
}

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void Precompute(int v, int lca, int len, int arr[])
{
    int nxt = v;
    if (L[v] - L[lca] > len)
        nxt = goUp(nxt, L[v] - L[lca] - len);
    while (nxt != lca) {
        arr[L[nxt] - L[lca]] = nxt;
        nxt = P[nxt][0];
    }
}

void addPath(int qind, int v, int lca, int len, const ii &p)
{
    if (L[v] - L[lca] >= len) {
        int ind = lower_bound(un[len].begin(), un[len].end(), p) - un[len].begin();
        quer[v].push_back(Query(qind, 1, ii(len, ind)));
        int u = goUp(v, L[v] - (L[lca] + len - 1));
        quer[u].push_back(Query(qind, -1, ii(len, ind)));
    }
}

void Solve(int v)
{
    for (int i = 0; i < Maxk; i++) {
        auto nd = ii(my[v][i].a, my[v][i].b);
        f[v][i] = lower_bound(un[i].begin(), un[i].end(), nd) - un[i].begin();
        if (f[v][i] >= un[i].size() || un[i][f[v][i]] != nd)
            f[v][i] = -1;
        else cnt[i][f[v][i]]++;
    }
    for (int i = 0; i < quer[v].size(); i++)
        qres[quer[v][i].ind] += quer[v][i].delt * cnt[quer[v][i].wh.first][quer[v][i].wh.second];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (P[v][0] == u) continue;
        auto h = toHash(neigh[v][i].second);
        for (int j = 1; j < Maxk; j++)
            my[u][j] = Join(h, my[v][j - 1]);
        Solve(u);
    }
    for (int i = 0; i < Maxk; i++)
        if (f[v][i] != -1)
            cnt[i][f[v][i]]--;
}

int main()
{
    mod1 = uniform_int_distribution<int>(1000000000, 1100000000)(rng);
    mod2 = uniform_int_distribution<int>(1000000000, 1100000000)(rng);
    arg1 = uniform_int_distribution<int>(1000000, 1100000)(rng);
    arg2 = uniform_int_distribution<int>(1000000, 1100000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    iarg1 = Inv(arg1, mod1);
    iarg2 = Inv(arg2, mod2);
    pw1[0] = pw2[0] = ipw1[0] = ipw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
        ipw1[i] = ll(ipw1[i - 1]) * iarg1 % mod1;
        ipw2[i] = ll(ipw2[i - 1]) * iarg2 % mod2;
    }
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; char ch;
        scanf("%d %d %c", &a, &b, &ch);
        neigh[a].push_back(ic(b, ch));
        neigh[b].push_back(ic(a, ch));
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        string str; Read(str);
        for (int j = 0; j < str.length(); j++) {
            auto h = toHash(str[j]);
            qH[i] = Join(qH[i], h);
            qR[i] = Join(h, qR[i]);
        }
        int lca = getLCA(qa[i], qb[i]);
        Precompute(qa[i], lca, str.length(), tmpA);
        Precompute(qb[i], lca, str.length(), tmpB);
        int alen = L[qa[i]] - L[lca];
        int blen = L[qb[i]] - L[lca];
        for (int a = 1; a <= alen && a < str.length(); a++) {
            int b = int(str.length()) - a;
            if (b < 1 || b > blen) continue;
            if (Join(removeBack(H[tmpA[a]], H[lca]), removeFront(R[tmpB[b]], R[lca])) == qH[i])
                qres[i]++;
        }
        un[str.length()].push_back(ii(qH[i].a, qH[i].b));
        un[str.length()].push_back(ii(qR[i].a, qR[i].b));
    }
    for (int i = 0; i < Maxk; i++) {
        sort(un[i].begin(), un[i].end());
        un[i].erase(unique(un[i].begin(), un[i].end()), un[i].end());
        cnt[i].resize(un[i].size(), 0);
    }
    for (int i = 0; i < q; i++) {
        int lca = getLCA(qa[i], qb[i]);
        addPath(i, qa[i], lca, qH[i].len, ii(qH[i].a, qH[i].b));
        addPath(i, qb[i], lca, qR[i].len, ii(qR[i].a, qR[i].b));
    }
    Solve(1);
    for (int i = 0; i < q; i++)
        printf("%d\n", qres[i]);
    return 0;
}