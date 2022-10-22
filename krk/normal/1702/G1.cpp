#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 20;

int n;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int P[Maxn][Maxm], L[Maxn];

void Traverse(int v)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        P[u][0] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
    rig[v] = cur;
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

bool Less(const int &a, const int &b)
{
    return lef[a] < lef[b];
}

bool Solve()
{
    vector <int> seq;
    int cnt; scanf("%d", &cnt);
    seq.resize(cnt);
    for (int i = 0; i < cnt; i++)
        scanf("%d", &seq[i]);
    sort(seq.begin(), seq.end(), Less);
    int lim = seq.size();
    for (int i = 0; i + 1 < lim; i++)
        seq.push_back(getLCA(seq[i], seq[i + 1]));
    sort(seq.begin(), seq.end());
    seq.erase(unique(seq.begin(), seq.end()), seq.end());
    sort(seq.begin(), seq.end(), Less);
    vector <ii> S;
    for (int i = 0; i < seq.size(); i++) {
        while (!S.empty() && rig[S.back().first] < lef[seq[i]])
            S.pop_back();
        int cur = 2;
        if (!S.empty()) {
            if (S.back().second == 0) return false;
            S.back().second--;
            cur--;
        }
        S.push_back(ii(seq[i], cur));
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    int q; scanf("%d", &q);
    while (q--)
        printf("%s\n", Solve()? "YES": "NO");
    return 0;
}