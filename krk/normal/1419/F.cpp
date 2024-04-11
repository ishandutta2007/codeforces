#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1005;
const ll Inf = 2000000007;

int n;
int X[Maxn], Y[Maxn];
vector <int> unX, unY;
int par[Maxn], siz[Maxn];
int comp;
vector <ii> mem;
int L[Maxn][Maxn], R[Maxn][Maxn];
int U[Maxn][Maxn], D[Maxn][Maxn];
bool globalprint;

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

void unionSet(int a, int b, bool sav)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    comp--;
    if (sav) mem.push_back(ii(a, b));
}

void Undo()
{
    while (!mem.empty()) {
        int a = mem.back().first;
        int b = mem.back().second;
        mem.pop_back();
        siz[a] -= siz[b]; par[b] = b;
        comp++;
    }
}

bool Dist(const ii &a, const ii &b, ll d)
{
    if (a.first == b.first)
        return abs(unY[a.second] - unY[b.second]) <= d;
    if (a.second == b.second)
        return abs(unX[a.first] - unX[b.first]) <= d;
    return false;
}

bool Solve(ll dist)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i; siz[i] = 1;
    }
    comp = n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (Dist(ii(X[i], Y[i]), ii(X[j], Y[j]), dist))
                unionSet(i, j, false);
    if (comp == 1) return true;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (X[i] == X[j] || Y[i] == Y[j])
                if (Dist(ii(X[i], Y[i]), ii(X[j], Y[j]), 2ll * dist)) {
                    unionSet(i, j, true);
                    bool ok = comp == 1;
                    Undo();
                    if (ok) return true;
                }
    par[n + 1] = n + 1; siz[n + 1] = 1;
    comp++;
    for (int i = 0; i < unX.size(); i++)
        for (int j = 0; j < unY.size(); j++) {
            int a = L[i][j];
            if (a && Dist(ii(X[a], Y[a]), ii(i, j), dist))
                unionSet(a, n + 1, true);
            a = R[i][j];
            if (a && Dist(ii(X[a], Y[a]), ii(i, j), dist))
                unionSet(a, n + 1, true);
            a = U[i][j];
            if (a && Dist(ii(X[a], Y[a]), ii(i, j), dist))
                unionSet(a, n + 1, true);
            a = D[i][j];
            if (a && Dist(ii(X[a], Y[a]), ii(i, j), dist))
                unionSet(a, n + 1, true);
            bool ok = comp == 1;
            Undo();
            if (ok) return true;
        }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        unX.push_back(X[i]);
        unY.push_back(Y[i]);
    }
    sort(unX.begin(), unX.end()); unX.erase(unique(unX.begin(), unX.end()), unX.end());
    sort(unY.begin(), unY.end()); unY.erase(unique(unY.begin(), unY.end()), unY.end());
    for (int i = 1; i <= n; i++) {
        X[i] = lower_bound(unX.begin(), unX.end(), X[i]) - unX.begin();
        Y[i] = lower_bound(unY.begin(), unY.end(), Y[i]) - unY.begin();
        L[X[i]][Y[i]] = R[X[i]][Y[i]] = U[X[i]][Y[i]] = D[X[i]][Y[i]] = i;
    }
    for (int i = 0; i < unX.size(); i++) {
        for (int j = 1; j < unY.size(); j++)
            if (!L[i][j]) L[i][j] = L[i][j - 1];
        for (int j = int(unY.size()) - 2; j >= 0; j--)
            if (!R[i][j]) R[i][j] = R[i][j + 1];
    }
    for (int j = 0; j < unY.size(); j++) {
        for (int i = 1; i < unX.size(); i++)
            if (!U[i][j]) U[i][j] = U[i - 1][j];
        for (int i = int(unX.size()) - 2; i >= 0; i--)
            if (!D[i][j]) D[i][j] = D[i + 1][j];
    }
    ll lef = 0, rig = Inf;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Solve(mid)) rig = mid - 1ll;
        else lef = mid + 1ll;
    }
    printf("%I64d\n", lef > Inf? -1ll: lef);
    return 0;
}