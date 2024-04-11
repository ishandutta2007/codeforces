#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 200005;
const int Maxs = 524288;
const int mod = 1000000007;

int mx[Maxm];
int n;
int a[Maxn];
set <ii> S[Maxm];
vector <ii> st[Maxs];
vector <ii> add[Maxn];

void Add(int v, int l, int r, int a, int b, int val, int mult)
{
    if (l == a && r == b) {
        int was = st[v].empty()? 1: st[v].back().second;
        mult = ll(mult) * was % mod;
        st[v].push_back(ii(val, mult));
    } else {
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), val, mult);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val, mult);
    }
}

int Solve(int v, int l, int r, int x, int rig)
{
    int ind = lower_bound(st[v].begin(), st[v].end(), ii(rig + 1, 0)) - st[v].begin() - 1;
    int res = ind >= 0? st[v][ind].second: 1;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res = ll(res) * Solve(2 * v, l, m, x, rig) % mod;
        else res = ll(res) * Solve(2 * v + 1, m + 1, r, x, rig) % mod;
    }
    return res;
}

int main()
{
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while (a[i] > 1) {
            int cur = mx[a[i]];
            int cnt = 0;
            while (a[i] % cur == 0) {
                a[i] /= cur; cnt++;
            }
            S[cur].insert(ii(i, cnt));
        }
    }
    for (int i = 2; i < Maxm; i++)
        for (int j = 1; !S[i].empty(); j++) {
            int cur = 1;
            for (auto it = S[i].begin(); it != S[i].end(); ) {
                add[it->first].push_back(ii(cur, i));
                cur = it->first + 1;
                if (j == it->second) S[i].erase(it++);
                else it++;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < add[i].size(); j++)
            Add(1, 1, n, add[i][j].first, i, i, add[i][j].second);
    int q; scanf("%d", &q);
    int res = 0;
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        x = (x + res) % n + 1;
        y = (y + res) % n + 1;
        if (x > y) swap(x, y);
        res = Solve(1, 1, n, x, y);
        printf("%d\n", res);
    }
    return 0;
}