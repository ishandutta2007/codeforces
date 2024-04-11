/*input
4
8
2 1 3 5 1 2 4 5
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
2
3 3
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;


const int INF = numeric_limits<int>::max() / 2;

vector<int> a;
int trace[15][(1 << 15)];
int cal(vector<int> &rem, vector<int> &piv) {
    int n = rem.size(); int m = piv.size();
    int sum[(1 << rem.size())]; memset(sum, 0, sizeof(sum));
    loop(mask, 1, (1 << n) - 1) {
        int p = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ (1 << p)] + a[rem[p]];
    }
    int dp[m][(1 << n)];
    loop(j, 0, m - 1) loop(mask, 0, (1 << n) - 1) {
        if (j == 0) dp[j][mask] = sum[((1 << n) - 1)^mask] + a[piv[0]], trace[0][mask] = ((1 << n) - 1)^mask;
        else dp[j][mask] = INF;
    }
    loop(i, 0, m - 2) {
        loop(mask, 0, (1 << n) - 1) {
            if (dp[i][mask] == INF) continue;
            for (int mask2 = mask;; mask2 = (mask2 - 1) & mask) {
                int nxt = sum[mask2] + a[piv[i + 1]];
                if (nxt > dp[i][mask] && dp[i + 1][mask ^ mask2] > nxt) {
                    trace[i + 1][mask ^ mask2] = mask2;
                    dp[i + 1][mask ^ mask2] = nxt;
                }
                if (mask2 == 0) break;
            }
        }
    }
    return dp[m - 1][0];
}


int n;

bool solve(int mask) {
    vector<int> rem, piv;
    loop(i, 0, n - 1) {
        if (bit(mask, i) == 0) rem.push_back(i);
        else piv.push_back(i);
    }
    return cal(rem, piv) != INF;
}

vector<pair<int, int> > getTrace(int mask) {
    vector<int> rem, piv;
    vector<pair<int, int> > ret;
    loop(i, 0, n - 1) {
        if (bit(mask, i) == 0) rem.push_back(i);
        else piv.push_back(i);
    }
    cal(rem, piv);
    pair<int, int> cur = {piv.size() - 1, 0};
    vector<int> tmp;
    while (cur.fi >= 0) {
        int mask2 = trace[cur.fi][cur.se];
        while (mask2) {
            int p = __builtin_ctz(mask2);
            ret.push_back({rem[p], piv[cur.fi]});
            mask2 ^= (1 << p);
        }
        cur.se = cur.se ^ trace[cur.fi][cur.se];
        cur.fi--;
    }
    reverse(ret.begin(), ret.end());
    loop(i, 0, n - 1) tmp.push_back(i);
    for (auto &it : ret) {
        int p = find(tmp.begin(), tmp.end(), it.fi) - tmp.begin();
        int q = find(tmp.begin(), tmp.end(), it.se) - tmp.begin();
        it.fi = p; it.se = q;
        tmp.erase(tmp.begin() + p);
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T--) {
        a.clear();
        cin >> n;
        loop(i, 1, n) {
            int t; cin >> t;
            a.push_back(t);
        }
        vector<int> b[n + 1]; int last = -1;
        loop(mask, 0, (1 << n) - 1) b[__builtin_popcountll(mask)].push_back(mask);
        auto check = [&](int lev) {
            for (auto mask : b[lev]) if (solve(mask)) {
                    last = mask;
                    return true;
                }
            return false;
        };
        int l = 1, r = n;
        while (l != r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        if (last == -1) check(l);
        auto rec = getTrace(last);
        cout << rec.size() << endl;
        if (!rec.empty())
            for (auto it : rec) cout << it.fi + 1 << sp << it.se + 1 << endl;
    }
}