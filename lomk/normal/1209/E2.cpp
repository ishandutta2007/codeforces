/*input
3
2 2
5 2
1 5
1 1
3
1 2
1 1
*/
#ifdef UncleGrandpa
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
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
// const int N =;

vector<vector<int> > a, b;
int n, m;

int dp[2000][(1 << 12)];
int mx[2000][(1 << 12)];
int sum[2000][(1 << 12)];

void prep() {
    loop(lev, 0, m - 1) {
        fill(mx[lev], mx[lev] + (1 << n), 0);
        fill(dp[lev], dp[lev] + (1 << n), 0);
        fill(sum[lev], sum[lev] + (1 << n), 0);
    }
    loop(lev, 0, m - 1) {
        loop(mask, 1, (1 << n) - 1) {
            int i = __builtin_ctzll(mask);
            sum[lev][mask] = sum[lev][mask ^ (1 << i)] + a[lev][i];
        }
    }
    loop(lev, 0, m - 1) {
        loop(mask, 1, (1 << n) - 1) {
            loop(shift, 0, n - 1) {
                int nmask = ((mask << shift) | (mask >> (n - shift))) & ((1 << n) - 1);
                mx[lev][mask] = max(mx[lev][mask], sum[lev][nmask]);
            }
        }
    }
}

void reformat() {
    a.assign(n, vector<int>(m, 0));
    loop(i, 0, n - 1) loop(j, 0, m - 1) cin >> a[i][j];
    b.assign(m, vector<int>(n, 0));
    loop(i, 0, n - 1) loop(j, 0, m - 1) b[j][i] = a[i][j];
    a = b;
    vector<pair<int, int> > all;
    loop(i, 0, m - 1) all.push_back({*max_element(a[i].begin(), a[i].end()), i});
    sort(all.begin(), all.end(), greater<pair<int, int> >());
    b = vector<vector<int> >();
    loop(i, 0, min(n, (int)all.size()) - 1)b.push_back(a[all[i].se]);
    a = b;
    n = a[0].size(); m = a.size();
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        reformat();
        prep();
        loop(i, 0, m - 1) {
            if (i == 0) {
                loop(mask, 0, (1 << n) - 1) dp[i][mask] = mx[i][mask];
            }
            else {
                loop(mask, 0, (1 << n) - 1) {
                    for (int mask2 = mask;; mask2 = (mask2 - 1) & mask) {
                        dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ mask2] + mx[i][mask2]);
                        if (mask2 == 0) break;
                    }
                }
            }
        }
        cout << dp[m - 1][(1 << n) - 1] << endl;
    }
}