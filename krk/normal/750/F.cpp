#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 7;

int T;
int h;
vector <int> neigh[Maxn];

vector <int> Ask(int v)
{
    if (neigh[v].empty()) {
        printf("? %d\n", v); fflush(stdout);
        int k; scanf("%d", &k);
        neigh[v].resize(k);
        for (int i = 0; i < k; i++)
            scanf("%d", &neigh[v][i]);
    }
    return neigh[v];
}

void Print(int v)
{
    printf("! %d\n", v); fflush(stdout);
}

void buildAll(int v, int p1, int p2, int lft, vector <int> &seq, bool &found)
{
    if (lft == 0) { seq.push_back(v); return; }
    auto V = Ask(v);
    if (V.size() == 2) { Print(v); found = true; return; }
    for (int i = 0; i < V.size() && !found; i++) {
        int u = V[i];
        if (p1 == u || p2 == u) continue;
        buildAll(u, v, -1, lft - 1, seq, found);
    }
}

deque <int> getPath(int v, int p1, int p2, bool &found)
{
    deque <int> res;
    auto V = Ask(v);
    if (V.size() == 2) { Print(v); found = true; return res; }
    int nxt = 0;
    while (nxt < V.size() && (V[nxt] == p1 || V[nxt] == p2)) nxt++;
    if (nxt >= V.size()) return res;
    int p = v;
    v = V[nxt];
    while (true) {
        res.push_back(v);
        auto V = Ask(v);
        if (V.size() == 2) { Print(v); found = true; return res; }
        int nxt = 0;
        while (nxt < V.size() && V[nxt] == p) nxt++;
        if (nxt >= V.size()) break;
        p = v; v = V[nxt];
    }
    return res;
}

void findMid(int &v, deque <int> &path1, deque <int> &path2)
{
    if (path1.size() < path2.size()) swap(path1, path2);
    while (path1.size() > path2.size()) {
        path2.push_front(v);
        v = path1.front(); path1.pop_front();
    }
}

void Solve()
{
    int v = 1;
    bool found = false;
    auto path1 = getPath(v, -1, -1, found);
    if (found) return;
    auto path2 = getPath(v, path1[0], -1, found);
    if (found) return;
    findMid(v, path1, path2);
    while (true) {
        int lvl = h - 1 - int(path1.size());
        if (lvl <= 3) {
            vector <int> seq;
            buildAll(v, path1[0], path2[0], lvl, seq, found);
            if (found) return;
            for (int i = 0; i + 1 < seq.size(); i++)
                if (Ask(seq[i]).size() == 2) { Print(seq[i]); return; }
            Print(seq.back());
            return;
        } else {
            path2 = getPath(v, path1[0], path2[0], found);
            if (found) return;
            findMid(v, path1, path2);
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &h);
        for (int i = 1; i < 1 << h; i++)
            neigh[i].clear();
        Solve();
    }
    return 0;
}