#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1 << 17;

int n;
vector <int> neigh[Maxn];
int P[Maxn];
vector <int> seq;
vector <int> res;
int ans;

ii getFar(int v, int p = 0)
{
    P[v] = p;
    ii res = ii(0, v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii got = getFar(u, v);
        got.first++;
        res = max(res, got);
    }
    return res;
}

ii Solve(int v, int p = 0)
{
    int ch = int(neigh[v].size()) - (p != 0);
    if (ch > 3) return ii(0, -1);
    if (ch == 0) return ii(1, 0);
    vector <int> valid, spec;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii got = Solve(u, v);
        if (got.first == 0) return ii(0, -1);
        else if (got.first == 1) valid.push_back(got.second);
        else spec.push_back(got.second);
    }
    if (spec.size() >= 2) return ii(0, -1);
    sort(valid.begin(), valid.end());
    if (ch == 1) {
        ans = v;
        if (valid.size() == 1 && valid[0] == 0) return ii(2, 1);
        else return ii(0, -1);
    }
    if (ch == 2)
        if (valid.size() >= 2 && valid[0] == valid[1]) return ii(1, valid[0] + 1);
        else if (valid.size() == 1 && valid[0] == spec[0]) return ii(2, valid[0] + 1);
        else return ii(0, -1);
    if (ch == 3) {
        ans = v;
        if (valid.size() == 3 && valid[0] == valid[1] && valid[1] + 1 == valid[2])
            return ii(2, valid[2] + 1);
        else return ii(0, -1);
    }
    return ii(0, -1);
}

int main()
{
    scanf("%d", &n);
    n = (1 << n) - 2;
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    ii a = getFar(1);
    ii b = getFar(a.second);
    ii c = getFar(b.second);
    int v = c.second;
    while (v) {
        seq.push_back(v);
        v = P[v];
    }
    int md = int(seq.size()) / 2;
    for (int i = md - 1; i <= md + 2; i++) if (0 <= i && i < seq.size()) {
        ii g = Solve(seq[i]);
        if (g.first == 2) res.push_back(ans);
    }
    sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}