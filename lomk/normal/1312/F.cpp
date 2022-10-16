/*input
1
7 5 5 1
3 5 3 1 4 5 5

10
6 5 4 5
2 3 2 3 1 3
1 5 2 3
10
4 4 2 3
8 10 8 5
2 2 1 4
8 5
3 5 3 5
9 2 10
4 5 5 5
2 10 4 2
2 3 1 4
1 10
3 1 5 3
9 8 7
2 5 4 5
8 8
3 5 1 4
5 5 10
*/
#ifdef UncleGrandpa
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if constexpr(LOCAL)cout << "[" << #x << "] ="; print(x);}
void print() {if constexpr(LOCAL)cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if constexpr(LOCAL)cout << value << ' ', print(values...);}
const int N = 3e5 + 5;

int n, s[3];
int a[N];
int grundy[N][3];
// don't need to sort val before hand
int Mex(vector<int> val) {
    int ret = 0;
    sort(val.begin(), val.end()); val.resize(distance(val.begin(), unique(val.begin(), val.end())));
    if (val.empty()) return ret = 0;
    int pre = -1;
    for (auto it : val) {
        if (it != pre + 1) return ret = pre + 1;
        pre = it;
    }
    return ret = pre + 1;
}

pair<int, int> prep() {
    map<vector<int>, int> mark;
    for (int lev = 1;; lev++) {
        grundy[lev][0] = Mex({grundy[max(0LL, lev - s[1])][1], grundy[max(0LL, lev - s[2])][2]});
        grundy[lev][1] = Mex({grundy[max(0LL, lev - s[0])][0], grundy[max(0LL, lev - s[2])][2]});
        grundy[lev][2] = Mex({grundy[max(0LL, lev - s[0])][0], grundy[max(0LL, lev - s[1])][1], grundy[max(0LL, lev - s[2])][2]});
        if (lev >= 4) {
            vector<int> cur;
            loop(i, lev - 4, lev) loop(j, 0, 2) cur.push_back(grundy[i][j]);
            if (mark.find(cur) == mark.end()) mark[cur] = lev - 4;
            else {
                return {mark[cur], lev - 4 - mark[cur]};
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> s[2] >> s[0] >> s[1];
        loop(i, 0, n - 1) cin >> a[i];
        int sta, len;
        tie(sta, len) = prep();
        auto getg = [&](int val, int type) {
            if (val >= sta)
                return grundy[sta + (val - sta) % len][type];
            else
                return grundy[val][type];
        };
        int ans = 0;
        int out = 0; loop(i, 0, n - 1)out ^= getg(a[i], 2);
        loop(i, 0, n - 1) {
            out ^= getg(a[i], 2);
            loop(j, 0, 2) {
                int nx = max(0LL, a[i] - s[j]);
                int cur = (out ^ getg(nx, j));
                if (cur == 0) ans++;
            }
            out ^= getg(a[i], 2);
        }

        // loop(i, 0, n - 1) {
        //     out ^= getg(a[i], 2);
        //     loop(j, 0, 2) {
        //         int nx = max(0LL, a[i] - s[j]);
        //         int cur = (out ^ getg(nx, j));
        //         if (cur == 0) ans++;
        //     }
        // }
        cout << ans << endl;
    }
}