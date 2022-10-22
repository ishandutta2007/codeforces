#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 300005;
const int Maxm = 2097152;

int T;
int n;
int a[Maxn];
ll has[Maxn];
ll mn[2][Maxm];
vector <lli> V[2];
int pnt[2];
map <ll, deque <int> > M[2];
ll nil[2];

void Create(int t, int v, int l, int r)
{
    if (l > r) return;
    if (l == r) mn[t][v] = V[t][l].first;
    else {
        int m = l + r >> 1;
        Create(t, 2 * v, l, m);
        Create(t, 2 * v + 1, m + 1, r);
        mn[t][v] = min(mn[t][2 * v], mn[t][2 * v + 1]);
    }
}

int getLast(int t, int v, int l, int r, int x, ll val)
{
    if (l > r) return n + 1;
    if (mn[t][v] >= val) return n + 1;
    if (l == r) return V[t][l].second;
    else {
        int m = l + r >> 1;
        int res = n + 1;
        if (x <= m) res = getLast(t, 2 * v, l, m, x, val);
        if (res != n + 1) return res;
        return getLast(t, 2 * v + 1, m + 1, r, x, val);
    }
}

ll Get(int j, int lst)
{
    auto it = M[j].find(nil[j]);
    if (it == M[j].end()) return 0ll;
    return lower_bound(it->second.begin(), it->second.end(), lst) - it->second.begin();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        V[0].clear(); V[1].clear();
        M[0].clear(); M[1].clear();
        nil[0] = nil[1] = 0;
        pnt[0] = pnt[1] = 0;
        for (int i = 1; i <= n; i++) {
            has[i] = a[i] - has[i - 1];
            int j = i % 2;
            V[j].push_back(lli(has[i], i));
            M[j][has[i]].push_back(i);
        }
        Create(0, 1, 0, int(V[0].size()) - 1);
        Create(1, 1, 0, int(V[1].size()) - 1);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            int lim = min(getLast(0, 1, 0, int(V[0].size()) - 1, pnt[0], nil[0]),
                      getLast(1, 1, 0, int(V[1].size()) - 1, pnt[1], nil[1]));
            res += Get(0, lim);
            res += Get(1, lim);
            int j = i % 2;
            pnt[j]++;
            M[j][has[i]].pop_front();
            nil[j] += a[i];
            nil[1 - j] -= a[i];
        }
        printf("%I64d\n", res);
    }
    return 0;
}