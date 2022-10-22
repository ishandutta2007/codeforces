#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxm = 1000001;
const int Maxv = 289;
const int Maxa = 1274;
const int Maxb = 1500;

int mx[Maxm];
int prime[Maxm], plen;
map <vector <int>, int> unval;
vector <vector <int> > un;
map <int, int> vert;
int dist[Maxv][Maxa + Maxb];
vector <ii> neigh[Maxa];
int best[Maxv][Maxv];

int Get(vector <int> V)
{
    sort(V.rbegin(), V.rend());
    while (!V.empty() && V.back() == 0) V.pop_back();
    auto it = vert.find(unval[V]);
    return it != vert.end()? it->second: -1;
}

void getDist(int v, int dist[])
{
    fill(dist, dist + Maxa + Maxb, Inf); dist[v] = 0;
    priority_queue <ii> Q; Q.push(ii(-0, v));
    while (!Q.empty()) {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        if (v < Maxa)
            for (int i = 0; i < neigh[v].size(); i++) {
                ii u = neigh[v][i];
                if (d + u.second < dist[u.first]) {
                    dist[u.first] = d + u.second;
                    Q.push(ii(-dist[u.first], u.first));
                }
            }
    }
}

vector <int> getC(int num)
{
    vector <int> res;
    while (num > 1) {
        int cur = mx[num], cnt = 0;
        while (mx[num] == cur) {
            num /= cur; cnt++;
        }
        res.push_back(cnt);
    }
    sort(res.rbegin(), res.rend());
    return res;
}

void Gen(int lvl, int val, vector <int> &C)
{
    unval[C] = val;
    un.push_back(C);
    int lst = C.empty()? Inf: C.back();
    C.push_back(0);
    for (C.back() = 1; C.back() <= lst && val <= Inf / prime[lvl]; C.back()++) {
        val *= prime[lvl];
        Gen(lvl + 1, val, C);
    }
    C.pop_back();
}

bool Less(const vector <int> &A, const vector <int> &B)
{
    return unval[A] < unval[B];
}

int main()
{
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0) {
        prime[plen++] = i;
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    }
    vector <int> tmp;
    Gen(0, 1, tmp);
    sort(un.begin(), un.end(), Less);
    for (int i = 0; i < un.size(); i++)
        vert[unval[un[i]]] = i;
    for (int i = 0; i < un.size(); i++) {
        auto V = un[i];
        int dvs = 1;
        for (int j = 0; j < V.size(); j++)
            dvs *= (V[j] + 1);
        neigh[i].push_back(ii(Maxa + dvs, 0));
        set <int> S;
        for (int j = 0; j < V.size(); j++) {
            V[j]++;
            int u = Get(V);
            if (u != -1) S.insert(u);
            V[j] -= 2;
            u = Get(V);
            if (u != -1) S.insert(u);
            V[j]++;
        }
        V.push_back(1);
        int u = Get(V);
        if (u != -1) S.insert(u);
        for (auto u: S)
            neigh[i].push_back(ii(u, 1));
    }
    for (int i = 0; i < Maxv; i++)
        getDist(i, dist[i]);
    for (int i = 0; i < Maxv; i++)
        for (int j = i; j < Maxv; j++) {
            int cur = Inf;
            for (int k = Maxa; k < Maxa + Maxb; k++)
                cur = min(cur, dist[i][k] + dist[j][k]);
            best[i][j] = best[j][i] = cur;
        }
    int q; scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", best[Get(getC(a))][Get(getC(b))]);
    }
    return 0;
}