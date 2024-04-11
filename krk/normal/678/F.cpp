#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Inf = 1000000007;
const ll bInf = 8000000000000000000ll;
const int Maxn = 300005;
const int Maxm = 2097152;

int n;
int qt[Maxn], qa[Maxn], qb[Maxn];
vector <int> un;
vector <ii> L[Maxm];
vector <int> X[Maxm];
int pnt[Maxm];
vector <iiii> adds;
vector <ii> solvers;
ll res[Maxn];

int getX(const ii &a, const ii &b)
{
    int fir = a.second - b.second;
    int sec = b.first - a.first;
    return fir <= 0? -((-fir) / sec): (fir - 1) / sec + 1;
}

void insertLine(int v, const ii &lin)
{
    while (!L[v].empty() &&
           ll(L[v].back().first) * (-Inf) + L[v].back().second <=
           ll(lin.first) * (-Inf) + lin.second) {
        L[v].pop_back();
        X[v].pop_back();
    }
    while (L[v].size() >= 2) {
        int x = getX(L[v].back(), lin);
        if (x <= X[v].back()) {
            L[v].pop_back();
            X[v].pop_back();
        } else break;
    }
    if (X[v].empty()) X[v].push_back(-Inf);
    else X[v].push_back(getX(L[v].back(), lin));
    L[v].push_back(lin);
}

ll Get(int v, int x)
{
    if (pnt[v] >= L[v].size()) return -bInf;
    while (pnt[v] + 1 < L[v].size() && X[v][pnt[v] + 1] <= x) pnt[v]++;
    return ll(L[v][pnt[v]].first) * x + L[v][pnt[v]].second;
}

void Update(int v, int l, int r, int a, int b, const ii &lin)
{
    if (l == a && r == b)
        insertLine(v, lin);
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), lin);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, lin);
    }
}

ll Get(int v, int l, int r, int x, int val)
{
    ll res = Get(v, val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res = max(res, Get(2 * v, l, m, x, val));
        else res = max(res, Get(2 * v + 1, m + 1, r, x, val));
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &qt[i], &qa[i]);
        if (qt[i] == 1) scanf("%d", &qb[i]);
        else if (qt[i] == 2) {
            qa[i]--;
            int lef = lower_bound(un.begin(), un.end(), qa[i]) - un.begin();
            int rig = int(un.size()) - 1;
            if (lef <= rig)
                adds.push_back(iiii(ii(qa[qa[i]], qb[qa[i]]), ii(lef, rig)));
            qt[qa[i]] = -1;
        } else {
            solvers.push_back(ii(qa[i], un.size()));
            un.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (qt[i] == 1) {
            int lef = lower_bound(un.begin(), un.end(), i) - un.begin();
            int rig = int(un.size()) - 1;
            if (lef <= rig)
                adds.push_back(iiii(ii(qa[i], qb[i]), ii(lef, rig)));
        }
    sort(adds.begin(), adds.end());
    sort(solvers.begin(), solvers.end());
    for (int i = 0; i < adds.size(); i++)
        Update(1, 0, int(un.size()) - 1, adds[i].second.first, adds[i].second.second, adds[i].first);
    for (int i = 0; i < solvers.size(); i++)
        res[solvers[i].second] = Get(1, 0, int(un.size()) - 1, solvers[i].second, solvers[i].first);
    for (int i = 0; i < solvers.size(); i++)
        if (res[i] > -bInf) printf("%I64d\n", res[i]);
        else printf("EMPTY SET\n");
    return 0;
}