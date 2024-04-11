#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxm = 405;
const int Maxn = 30005;
const int Inf = 1000000000;

int n, k;
int m;
int D[Maxm][Maxn];
int id[Maxm];
vector <int> neigh[Maxn];
int dist[Maxn];

void Impossible()
{
    printf("-1\n");
}

bool hasId(int v)
{
    for (int i = 0; i < m; i++)
        if (id[i] == v) return true;
    return false;
}

bool Check(vector <ii> &V)
{
    if (V.empty()) return true;
    sort(V.begin(), V.end());
    if (V[0].first == 0) return false;
    int lst = 0;
    for (int i = 0; i < V.size(); i++) {
        if (V[i].first > lst + 1) return false;
        lst = V[i].first;
    }
    return true;
}

void buildAny(const vector <ii> &V, int p)
{
    int lst = 0;
    int nxt = p;
    for (int i = 0; i < V.size(); i++) {
        if (V[i].first == lst + 1) {
            p = nxt; nxt = V[i].second;
            lst++;
        }
        neigh[p].push_back(V[i].second);
        neigh[V[i].second].push_back(p);
    }
}

bool Solve(const vector <int> &all, const vector <int> &imp)
{
    int a = -1, b = -1, best = -1;
    for (int i = 0; i < imp.size(); i++)
        for (int j = i + 1; j < imp.size(); j++) {
            int mx = D[imp[i]][id[imp[j]]];
            if (mx > best) {
                best = mx;
                a = imp[i];
                b = imp[j];
            }
        }
    if (best == 0) return false;
    if (best < 0) {
        a = imp[0], b = imp[0];
        best = 0;
    }
    vector <int> seq;
    vector <vector <ii> > inseq;
    vector <vector <int> > spec;
    if (best > 0) {
        seq.resize(best - 1);
        inseq.resize(best - 1);
        spec.resize(best - 1);
    }
    vector <ii> lef, rig;
    for (int i = 0; i < imp.size(); i++) if (imp[i] != a && imp[i] != b) {
        int x = D[a][id[imp[i]]] + D[b][id[imp[i]]] - D[a][id[b]];
        if (x < 0 || x % 2) return false;
        x /= 2;
        int froma = D[a][id[imp[i]]] - x;
        if (froma <= 0 || froma >= best) return false;
        spec[froma - 1].push_back(imp[i]);
    }
    for (int i = 0; i < all.size(); i++) if (all[i] != id[a] && all[i] != id[b]) {
        int x = D[a][all[i]] + D[b][all[i]] - D[a][id[b]];
        if (x < 0 || x % 2) return false;
        x /= 2;
        int froma = D[a][all[i]] - x;
        if (froma < 0 || froma > best) return false;
        if (froma == 0) lef.push_back(ii(D[a][all[i]], all[i]));
        else if (froma == best) rig.push_back(ii(D[b][all[i]], all[i]));
        else if (x == 0) 
                if (seq[froma - 1]) return false;
                else seq[froma - 1] = all[i];
            else inseq[froma - 1].push_back(ii(x, all[i]));
    }
    if (Check(lef)) buildAny(lef, id[a]);
    else return false;
    if (Check(rig)) buildAny(rig, id[b]);
    else return false;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i] == 0 || !Check(inseq[i])) return false;
        else if (spec[i].empty()) buildAny(inseq[i], seq[i]);
        else {
            if (!hasId(seq[i])) {
                id[m] = seq[i];
                for (int j = 0; j < inseq[i].size(); j++)
                    D[m][inseq[i][j].second] = inseq[i][j].first;
                spec[i].push_back(m);
                m++;
            }
            vector <int> nall;
            nall.push_back(seq[i]);
            for (int j = 0; j < inseq[i].size(); j++)
                nall.push_back(inseq[i][j].second);
            if (!Solve(nall, spec[i]))
                return false;
        }
    int lst = id[a];
    for (int i = 0; i < seq.size(); i++) {
        neigh[lst].push_back(seq[i]);
        neigh[seq[i]].push_back(lst);
        lst = seq[i];
    }
    if (lst != id[b]) {
        neigh[lst].push_back(id[b]);
        neigh[id[b]].push_back(lst);
    }
    return true;
}

bool verifyDistances(int v, int D[])
{
    fill(dist, dist + n + 1, Inf);
    dist[v] = 0;
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (D[i] != dist[i]) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &k);
    m = k;
    vector <int> imp, all;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &D[i][j]);
            if (D[i][j] == 0)
                if (id[i]) {
                    Impossible();
                    return 0;
                } else id[i] = j;
        }
        if (!id[i]) {
            Impossible();
            return 0;
        }
        imp.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        all.push_back(i);
    if (!Solve(all, imp)) {
        Impossible();
        return 0;
    }
    for (int i = 0; i < k; i++)
        if (!verifyDistances(id[i], D[i])) {
            Impossible();
            return 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (i < u) printf("%d %d\n", i, u);
        }
    return 0;
}