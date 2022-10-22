#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
 
const int Maxn = 3005;
 
int n, m;
set <int> neigh[Maxn];
set <ii> forb;
bool tk[Maxn];
vector <int> bad;
vector <int> res;
int st;

void addForb(int a, int b)
{
    if (a > b) swap(a, b);
    forb.insert(ii(a, b));
}

bool checkForb(int a, int b)
{
    if (a > b) swap(a, b);
    return forb.find(ii(a, b)) != forb.end();
}

void Solve(int v)
{
    vector <int> S;
    while (!neigh[v].empty() || !S.empty())
        if (neigh[v].empty()) {
            res.push_back(v);
            v = S.back(); S.pop_back();
        } else {
            S.push_back(v);
            int u = *neigh[v].begin();
            neigh[u].erase(v);
            neigh[v].erase(u);
            v = u;
        }
}

int Traverse(int v)
{
    if (tk[v]) return 0;
    tk[v] = true;
    int res = 1;
    for (auto u: neigh[v]) {
        if (checkForb(v, u)) continue;
        res += Traverse(u);
    }
    return res;
}

bool Check(int root)
{
    fill(tk, tk + n + 1, false);
    Traverse(root);
    int cnt = 1;
    for (int i = 1; i <= n; i++)
        if (Traverse(i) > 1) cnt++;
    return cnt <= 1;
}

void prepareEnd(int v, int forb)
{
    for (auto it = neigh[v].begin(); it != neigh[v].end(); )
        if (*it != forb && neigh[*it].size() % 2) {
            res.push_back(v);
            neigh[*it].erase(v);
            res.push_back(*it);
            neigh[v].erase(it++);
        } else it++;
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() % 2)
            bad.push_back(i);
    if (bad.empty()) st = 1;
    else if (bad.size() <= 2) st = bad[0];
    else {
        bool found = false;
        for (int i = 1; i <= n && !found; i++) {
            int nd = bad.size();
            nd -= neigh[i].size() % 2;
            for (auto it: neigh[i])
                nd -= neigh[it].size() % 2;
            if (nd == 0) {
                for (auto itimp = neigh[i].begin(); itimp != neigh[i].end() && !found; itimp++) if (neigh[*itimp].size() % 2) {
                    forb.clear();
                    for (auto it = neigh[i].begin(); it != neigh[i].end(); it++)
                        if (*it != *itimp && neigh[*it].size() % 2)
                            addForb(i, *it);
                    if (Check(i)) {
                        found = true;
                        prepareEnd(i, *itimp);
                        res.push_back(-1);
                        st = *itimp;
                    }
                }
            } else if (nd == 1) {
                forb.clear();
                for (auto it = neigh[i].begin(); it != neigh[i].end(); it++)
                    if (neigh[*it].size() % 2)
                        addForb(i, *it);
                if (Check(i)) {
                    found = true;
                    prepareEnd(i, -1);
                    res.push_back(-1);
                    int pnt = 0;
                    while (neigh[bad[pnt]].size() % 2 == 0 || bad[pnt] == i) pnt++;
                    st = bad[pnt];
                }
            }
        }
        if (!found) { printf("0\n"); return 0; }
    }
    Solve(st);
    res.push_back(st);
    printf("%d\n", int(res.size()));
    for (int i = int(res.size()) - 1; i >= 0; i--)
        printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
    return 0;
}