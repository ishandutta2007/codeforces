#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Inf = 2000000007;
const int Maxn = 152;
const int Maxb = 60;
const int Maxk = 3;

struct Row {
    ll val[Maxk];
    Row() { fill(val, val + Maxk, 0ll); }
    void Set(int ind) { val[ind / Maxb] |= 1ll << ll(ind % Maxb); }
    bool Get(int ind) { return bool(val[ind / Maxb] & 1ll << ll(ind % Maxb)); }
    bool operator*(const Row &oth) {
        for (int i = 0; i < Maxk; i++)
            if (val[i] & oth.val[i]) return true;
        return false;
    }
};

struct Matrix {
    Row R[Maxn], C[Maxn];
    void setDiag() {
        for (int i = 0; i < Maxn; i++) {
            R[i].Set(i);
            C[i].Set(i);
        }
    }
    Matrix operator*(const Matrix &oth) {
        Matrix res;
        for (int i = 0; i < Maxn; i++)
            for (int j = 0; j < Maxn; j++)
                if (R[i] * oth.C[j]) {
                    res.R[i].Set(j);
                    res.C[j].Set(i);
                }
        return res;
    }
    Row operator*(const Row &oth) {
        Row res;
        for (int i = 0; i < Maxn; i++)
            if (R[i] * oth)
                res.Set(i);
        return res;
    }
};

int n, m;
iii E[Maxn];
vector <int> neigh[Maxn];
int dist[Maxn];
Row cur;
Matrix A;
int res = Inf;

void Traverse(Matrix A, int steps)
{
    Matrix R; R.setDiag();
    while (steps) {
        if (steps & 1) R = R * A;
        steps >>= 1; A = A * A;
    }
    cur = R * cur;
}

void checkBFS(int d)
{
    int v = n - 1;
    fill(dist, dist + n, Inf); dist[v] = d;
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
    for (int i = 0; i < n; i++) if (cur.Get(i))
        res = min(res, dist[i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
        E[i].second.first--; E[i].second.second--;
    }
    sort(E, E + m);
    cur.Set(0);
    int lst = 0;
    for (int i = 0; i < m; i++) {
        Traverse(A, E[i].first - lst);
        lst = E[i].first;
        int a = E[i].second.first, b = E[i].second.second;
        neigh[b].push_back(a);
        A.R[b].Set(a);
        A.C[a].Set(b);
        checkBFS(lst);
    }
    if (res >= Inf) printf("Impossible\n");
    else printf("%d\n", res);
    return 0;
}