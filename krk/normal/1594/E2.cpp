#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 6;
const string cols[Maxd] = {"white", "yellow", "green", "blue", "red", "orange"};
const int mod = 1000000007;
const int Maxn = 62;

struct pos {
    int res[Maxd];
    pos() {
        fill(res, res + Maxd, 0);
    }
};

char tmp[50];
int k;
ll lim;
int dp[Maxn];
map <ll, int> C;
map <ll, pos> M;

int Alone(ll v)
{
    int cur = 0;
    ll lef = v, rig = v;
    while (rig < lim) {
        cur++;
        auto it = C.lower_bound(lef);
        if (it != C.end() && it->first <= rig) return -1;
        lef = 2 * lef;
        rig = 2 * rig + 1;
    }
    return cur;
}

pos Solve(ll v)
{
    auto it = M.find(v);
    if (it == M.end()) {
        pos cur;
        int al = Alone(v);
        if (al != -1) {
            for (int i = 0; i < Maxd; i++)
                cur.res[i] = dp[al];
            M.insert(make_pair(v, cur));
            return cur;
        }
        int valid = -1;
        auto cit = C.find(v);
        if (cit != C.end()) valid = cit->second;
        if (2ll * v >= lim) {
            for (int i = 0; i < Maxd; i++)
                cur.res[i] = valid == i || valid == -1;
            M.insert(make_pair(v, cur));
            return cur;
        }
        pos A = Solve(2 * v), B = Solve(2 * v + 1);
        for (int i = 0; i < Maxd; i++)
            if (valid == i || valid == -1) {
                for (int a = 0; a < Maxd; a++) if (i / 2 != a / 2)
                    for (int b = 0; b < Maxd; b++) if (i / 2 != b / 2)
                        cur.res[i] = (cur.res[i] + ll(A.res[a]) * B.res[b]) % mod;
            } else cur.res[i] = 0;
        M.insert(make_pair(v, cur));
        return cur;
    }
    return it->second;
}

int main()
{
    scanf("%d", &k);
    lim = 1ll << ll(k);
    dp[1] = 1;
    for (int i = 2; i <= k; i++)
        for (int a = 0; a < 6; a++) if (a / 2 != 0)
            for (int b = 0; b < 6; b++) if (b / 2 != 0)
                dp[i] = (dp[i] + ll(dp[i - 1]) * dp[i - 1]) % mod;
    int n; scanf("%d", &n);
    while (n--) {
        ll v; scanf("%I64d %s", &v, tmp);
        string s = tmp;
        int i = 0;
        while (cols[i] != s) i++;
        C[v] = i;
    }
    auto got = Solve(1);
    int res = 0;
    for (int i = 0; i < Maxd; i++)
        res = (res + got.res[i]) % mod;
    cout << res << endl;
    return 0;
}