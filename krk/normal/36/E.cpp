#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 10005;

int m;
set <ii> neigh[Maxn];
bool tk[Maxn];
vector <int> comp;
vector <vector <int> > res;

void Take(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    comp.push_back(v);
    for (auto u: neigh[v])
        Take(u.first);
}

void getSeq(int v, vector <int> &seq)
{
    while (!neigh[v].empty()) {
        ii u = *neigh[v].begin();
        neigh[v].erase(neigh[v].begin());
        neigh[u.first].erase(ii(v, u.second));
        getSeq(u.first, seq);
        seq.push_back(u.second);
    }
}

void Cut(const vector <int> &V, int l, int r)
{
    l = (l + 1) % int(V.size());
    vector <int> my;
    while (l != r) {
        my.push_back(V[l]);
        l = (l + 1) % int(V.size());
    }
    res.push_back(my);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &m);
    if (m == 1) { printf("-1\n"); return 0; }
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(ii(b, i));
        neigh[b].insert(ii(a, i));
    }
    for (int i = 0; i < Maxn; i++) if (!neigh[i].empty() && !tk[i]) {
        comp.clear();
        Take(i);
        vector <int> special;
        for (int j = 0; j < comp.size(); j++) if (neigh[comp[j]].size() % 2)
            special.push_back(comp[j]);
        if (special.size() <= 2) {
            int v = special.empty()? comp[0]: special[0];
            vector <int> seq;
            getSeq(v, seq);
            res.push_back(seq);
        } else if (special.size() == 4) {
            for (int i = 0; i < special.size(); i++) {
                int oth = i % 2 == 0? i + 1: i - 1;
                neigh[special[i]].insert(ii(special[oth], 0));
            }
            vector <int> seq;
            getSeq(special[0], seq);
            int l = 0;
            while (seq[l] != 0) l++;
            int r = l + 1;
            while (seq[r] != 0) r++;
            Cut(seq, l, r);
            Cut(seq, r, l);
        } else { printf("-1\n"); return 0; }
    }
    if (res.size() > 2) { printf("-1\n"); return 0; }
    if (res.size() == 1) {
        vector <int> tmp = {res[0].back()}; res[0].pop_back();
        res.push_back(tmp);
    }
    for (int i = 0; i < res.size(); i++) {
        printf("%d\n", int(res[i].size()));
        for (int j = 0; j < res[i].size(); j++)
            printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
    }
    return 0;
}