#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxw = 2000006;
const int lim = 50;

int sm[Maxw];
int n, q;
int a[Maxn];
vector <int> neigh[Maxn];
int curtim, tim[Maxn], invtim[Maxn];
int P[Maxn];
vector <int> cur[Maxw];
vector <int> seq[Maxn], myerpars[Maxn];
bool er[Maxn];

void Traverse(int v, int p)
{
    tim[v] = ++curtim; invtim[tim[v]] = v; P[v] = p;
    vector <ii> work;
    int num = a[v], lst = -1;
    while (num > 1) {
        if (lst != sm[num]) {
            work.push_back(ii(sm[num], int(cur[sm[num]].size()) - 1));
            lst = sm[num];
        }
        num /= sm[num];
    }
    while (seq[v].size() <= lim) {
        int mx = -1;
        for (int i = 0; i < work.size(); i++)
            if (work[i].second >= 0) mx = max(mx, tim[cur[work[i].first][work[i].second]]);
        if (mx == -1) break;
        seq[v].push_back(invtim[mx]);
        for (int i = 0; i < work.size(); i++)
            if (work[i].second >= 0 && cur[work[i].first][work[i].second] == invtim[mx])
                work[i].second--;
    }
    for (int i = 0; i < work.size(); i++)
        cur[work[i].first].push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
    }
    for (int i = 0; i < work.size(); i++)
        cur[work[i].first].pop_back();
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void fillChildren(int v, int p, int val)
{
    if (v != val) myerpars[v].push_back(val);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        fillChildren(u, v, val);
    }
}

void Change(int v, int w)
{
    er[v] = true; a[v] = w;
    int u = P[v];
    seq[v].clear();
    while (seq[v].size() <= lim && u > 0) {
        if (gcd(a[v], a[u]) > 1) seq[v].push_back(u);
        u = P[u];
    }
    fillChildren(v, P[v], v);
}

int getRes(int v)
{
    int best = -1;
    for (int i = 0; i < seq[v].size(); i++) {
        int u = seq[v][i];
        if (!er[u]) { best = tim[u]; break; }
    } 
    for (int i = 0; i < myerpars[v].size(); i++) {
        int u = myerpars[v][i];
        if (gcd(a[v], a[u]) > 1) best = max(best, tim[u]);
    }
    return best == -1? -1: invtim[best];
}

int main()
{
    for (int i = 2; i < Maxw; i++) if (sm[i] == 0)
        for (int j = i; j < Maxw; j += i) sm[j] = i;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[x].push_back(y); neigh[y].push_back(x);
    }
    Traverse(1, 0);
    while (q--) {
        int typ, v, w;
        scanf("%d %d", &typ, &v);
        if (typ == 1) printf("%d\n", getRes(v));
        else {
            scanf("%d", &w);
            Change(v, w);
        }
    }
    return 0;
}