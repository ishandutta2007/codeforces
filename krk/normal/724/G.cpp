#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ll> iill;
typedef pair <int, ll> ill;

const int Maxn = 100005;
const int Maxb = 60;
const int mod = 1000000007;

int n, m;
int par[Maxn], siz[Maxn];
vector <ill> neigh[Maxn];
vector <iill> oth;
int ones[Maxn][Maxb], zers[Maxn][Maxb];
int pones[Maxn][Maxb], pzers[Maxn][Maxb];
int rones[Maxn][Maxb], rzers[Maxn][Maxb];
ll bas[Maxn][Maxb];
ll my[Maxn];
int res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void Traverse(int v, int p, ll mask)
{
    my[v] = mask;
    for (int i = 0; i < neigh[v].size(); i++) {
        ill u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v, (mask ^ u.second));
        for (int j = 0; j < Maxb; j++) {
            pones[u.first][j] = ones[u.first][j];
            pzers[u.first][j] = zers[u.first][j] + 1;
            if (u.second & 1ll << ll(j))
                swap(pones[u.first][j], pzers[u.first][j]);
            ones[v][j] += pones[u.first][j];
            zers[v][j] += pzers[u.first][j];
        }
    }
}

void Traverse2(int v, int p, int tzers[], int tones[])
{
    for (int i = 0; i < Maxb; i++) {
        zers[v][i] += tzers[i] + 1;
        ones[v][i] += tones[i];
        rzers[getPar(v)][i] = (rzers[getPar(v)][i] + zers[v][i] - 1) % mod;
        rones[getPar(v)][i] = (rones[getPar(v)][i] + ones[v][i]) % mod;
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        ill u = neigh[v][i];
        if (u.first == p) continue;
        for (int j = 0; j < Maxb; j++) {
            tzers[j] = zers[v][j] - pzers[u.first][j];
            tones[j] = ones[v][j] - pones[u.first][j];
            if (u.second & 1ll << ll(j))
                swap(tzers[j], tones[j]);
        }
        Traverse2(u.first, v, tzers, tones);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b; ll c; scanf("%d %d %I64d", &a, &b, &c);
        if (unionSet(a, b)) {
            neigh[a].push_back(ill(b, c));
            neigh[b].push_back(ill(a, c));
        } else oth.push_back(iill(ii(a, b), c));
    }
    for (int i = 1; i <= n; i++) if (getPar(i) == i) {
        Traverse(i, 0, 0);
        int ones[Maxb] = {}, zers[Maxb] = {};
        Traverse2(i, 0, zers, ones);
    }
    for (int i = 0; i < oth.size(); i++) {
        int a = oth[i].first.first;
        int b = oth[i].first.second;
        ll c = oth[i].second;
        ll add = (my[a] ^ my[b] ^ c);
        if (add) {
            int r = getPar(a);
            for (int i = Maxb - 1; i >= 0; i--)
                if (add & 1ll << ll(i))
                    if (bas[r][i]) add ^= bas[r][i];
                    else { bas[r][i] = add; break; }
        }
    }
    for (int i = 1; i <= n; i++) if (getPar(i) == i) {
        ll gmask = 0;
        int cnt = 0;
        for (int j = Maxb - 1; j >= 0; j--) if (bas[i][j]) {
            cnt++;
            gmask |= bas[i][j];
        }
        for (int j = 0; j < Maxb; j++)
            if (cnt == 0) res = (res + (1ll << ll(j)) % mod * rones[i][j]) % mod;
            else if (gmask & 1ll << ll(j)) {
                int hlf = (1ll << ll(cnt - 1)) % mod;
                res = (res + (1ll << j) % mod * (rones[i][j] + rzers[i][j]) % mod * hlf) % mod;
            } else {
                int all = (1ll << ll(cnt)) % mod;
                res = (res + (1ll << j) % mod * rones[i][j] % mod * all) % mod;
            }
    }
    res = ll(mod + 1) / 2ll * ll(res) % mod;
    printf("%d\n", res);
    return 0;
}