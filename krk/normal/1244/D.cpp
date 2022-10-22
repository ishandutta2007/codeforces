#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;
const int Maxc = 3;

int n;
int C[Maxc][Maxn];
vector <int> neigh[Maxn];
vector <int> spec;
vector <int> seq;
int res[Maxn];
ll best = Inf;
vector <int> bi;

ll Get(const vector <int> &cols)
{
    ll got = 0;
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        res[v] = cols[i % Maxc];
        got += C[cols[i % Maxc]][v];
    }
    return got;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < Maxc; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &C[i][j]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() > 2) { printf("-1\n"); return 0; }
        else if (neigh[i].size() == 1) spec.push_back(i);
    if (spec.size() != 2) { printf("-1\n"); return 0; }
    int p = -1, v = spec[0]; seq.push_back(v);
    do {
        if (neigh[v][0] != p) { p = v; v = neigh[v][0]; }
        else { p = v; v = neigh[v][1]; }
        seq.push_back(v);
    } while (v != spec[1]);
    vector <int> srt = {0, 1, 2};
    do {
        ll cand = Get(srt);
        if (cand < best) { best = cand; bi = srt; }
    } while (next_permutation(srt.begin(), srt.end()));
    Get(bi);
    printf("%I64d\n", best);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i] + 1, i + 1 <= n? ' ': '\n');
    return 0;
}