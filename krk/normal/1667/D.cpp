#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
ii res[Maxn];
int lef, rig;
vector <ii> my[Maxn];
int par[Maxn];

vector <ii> writeOdd(const vector <ii> &V)
{
    vector <ii> res;
    for (int i = 1; i < V.size(); i += 2) {
        res.push_back(V[i]);
        res.push_back(V[i - 1]);
    }
    res.push_back(V.back());
    return res;
}

void writeLef(const vector <ii> &V)
{
    for (int i = 0; i < V.size(); i++)
        res[lef++] = V[i];
}

void writeRig(const vector <ii> &V)
{
    for (int i = int(V.size()) - 1; i >= 0; i--)
        res[rig--] = V[i];
}

bool Solve(int v, int p)
{
    vector <int> od, ev;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (!Solve(u, v)) return false;
        my[par[u]].push_back(ii(v, u));
        if (my[par[u]].size() % 2) od.push_back(par[u]);
        else ev.push_back(par[u]);
    }
    while (!od.empty() && !ev.empty()) {
        auto tmp = my[od.back()];
        auto tmp2 = my[ev.back()];
        od.pop_back(); ev.pop_back();
        reverse(tmp2.begin(), tmp2.end());
        tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        writeRig(writeOdd(tmp));
    }
    if (od.size() >= 2) {
        int all = (p != 0) + int(od.size());
        if (all % 2) {
            writeLef(writeOdd(my[od.back()]));
            od.pop_back();
        }
    }
    if (ev.size() >= 2 || od.size() >= 2) return false;
    if (!ev.empty()) par[v] = ev.back();
    else if (!od.empty()) par[v] = od.back();
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        lef = 0, rig = n - 2;
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            my[i].clear();
            par[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        bool ok = Solve(1, 0);
        if (ok)
            if (!my[par[1]].empty() && my[par[1]].size() % 2 == 0) ok = false;
            else if (!my[par[1]].empty()) writeLef(writeOdd(my[par[1]]));
        if (ok) {
            printf("YES\n");
            for (int i = 0; i < n - 1; i++)
                printf("%d %d\n", res[i].first, res[i].second);
        } else printf("NO\n");
    }
    return 0;
}