#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000000;

int n, m;
int L[Maxn], R[Maxn], T[Maxn];
vector <int> un;
int st[Maxm];
vector <ii> ev;
int res[Maxn];

void Create(int v, int l, int r)
{
    st[v] = Inf;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);

    }
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) st[v] = min(st[v], val);
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}

void Get(int v, int l, int r, int best)
{
    best = min(best, st[v]);
    if (l == r) {
        if (best < Inf) {
            ev.push_back(ii(best - un[r + 1], -1));
            ev.push_back(ii(best - un[l], -2));
        }
    } else {
        int m = l + r >> 1;
        Get(2 * v, l, m, best);
        Get(2 * v + 1, m + 1, r, best);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &L[i], &R[i], &T[i]);
        un.push_back(L[i]);
        un.push_back(R[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    Create(1, 0, int(un.size()) - 2);
    for (int i = 0; i < m; i++) {
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
        Update(1, 0, int(un.size()) - 2, L[i], R[i] - 1, T[i]);
    }
    Get(1, 0, int(un.size()) - 2, Inf);
    for (int i = 0; i < n; i++) {
        int q; scanf("%d", &q);
        ev.push_back(ii(q, i));
    }
    sort(ev.begin(), ev.end());
    int st = 0;
    int ans = 0;
    for (int i = 0; i < ev.size(); i++) {
        if (i > 0)
            ans += st * (ev[i].first - ev[i - 1].first);
        if (ev[i].second == -1) st++;
        else if (ev[i].second == -2) st--;
        else res[ev[i].second] = ans;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", res[i]);
    return 0;
}