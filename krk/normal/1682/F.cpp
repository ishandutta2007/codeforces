#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int a[Maxn];
int b[Maxn];
ll sumb[Maxn];
vector <ll> un;
ii cur[Maxm];
vector <int> byL[Maxm];
vector <ii> el[Maxm];
int ql[Maxn], qr[Maxn];
vector <int> byR[Maxn];
int res[Maxn];

void Check(const ii &p)
{
    assert(0 <= p.first && p.first < mod);
    assert(0 <= p.second && p.second < mod);
}

ii Add(const ii &a, const ii &b)
{
    Check(a);
    Check(b);
    return ii((a.first + b.first) % mod, (a.second + b.second) % mod);
}

ii Sub(const ii &a, const ii &b)
{
    Check(a);
    Check(b);
    return ii((a.first - b.first + mod) % mod, (a.second - b.second + mod) % mod);
}

ii Get(int v, int l, int r, int a, int b, int lef)
{
    if (l == a && r == b) {
        ii res = cur[v];
        int ind = lower_bound(byL[v].begin(), byL[v].end(), lef) - byL[v].begin();
        if (ind < byL[v].size())
            res = Sub(res, el[v][ind]);
        else res = Sub(res, cur[v]);
        return res;
    } else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b, lef);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b, lef);
        return Add(Get(2 * v, l, m, a, m, lef), Get(2 * v + 1, m + 1, r, m + 1, b, lef));
    }
}

void Update(int v, int l, int r, int x, int lef, ii val)
{
    byL[v].push_back(lef);
    el[v].push_back(cur[v]);
    cur[v] = Add(cur[v], val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, lef, val);
        else Update(2 * v + 1, m + 1, r, x, lef, val);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        sumb[i] = sumb[i - 1] + b[i];
        un.push_back(sumb[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &ql[i], &qr[i]);
        byR[qr[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int ind = lower_bound(un.begin(), un.end(), sumb[i]) - un.begin();
        int A = i < n? a[i + 1] - a[i]: 0;
        int B = sumb[i] % mod;
        if (B < 0) B += mod;
        B = ll(B) * A % mod;
        Update(1, 0, int(un.size()) - 1, ind, i, ii(A, B));
        for (int j = 0; j < byR[i].size(); j++) {
            int qind = byR[i][j];
            ii got1 = Get(1, 0, int(un.size()) - 1, 0, ind, ql[qind]);
            ii got2 = Get(1, 0, int(un.size()) - 1, ind, int(un.size()) - 1, ql[qind]);
            int tmp = sumb[i] % mod;
            if (tmp < 0) tmp += mod;
            res[qind] = (ll(tmp) * got1.first % mod - got1.second + mod) % mod;
            res[qind] = (ll(res[qind]) + got2.second - ll(tmp) * got2.first % mod + mod) % mod;
            assert(res[qind] >= 0);
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", res[i]);
    return 0;
}