#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
vector <ii> seq;

ii Get(int v)
{
    if (tk[v]) return ii(v, v);
    tk[v] = true;
    ii res = ii(v, v);
    for (int i = 0; i < neigh[v].size(); i++) {
        ii got = Get(neigh[v][i]);
        res.first = min(res.first, got.first);
        res.second = max(res.second, got.second);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        seq.push_back(Get(i));
    sort(seq.begin(), seq.end());
    vector <ii> S;
    for (int i = 0; i < seq.size(); i++)
        if (S.empty() || S.back().second < seq[i].first)
            S.push_back(seq[i]);
        else S.back().second = max(S.back().second, seq[i].second);
    printf("%d\n", int(seq.size()) - int(S.size()));
    return 0;
}