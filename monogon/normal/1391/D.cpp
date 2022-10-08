
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5;
int n, m;
string s[N];//, s2[N];
int row[N];
int dp[N][1 << 3];
bool good[1 << 3][1 << 3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    if(n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    if(n <= 3) {
        swap(n, m);
        rep(i, 0, n) rep(j, 0, m) {
            row[i] ^= (s[j][i] == '1' ? (1 << j) : 0);
        }
    }else {
        rep(i, 0, n) {
            rep(j, 0, m) {
                row[i] ^= (s[i][j] == '1' ? (1 << j) : 0);
            }
        }
    }
    rep(mask, 0, 1 << m) {
        rep(mask2, 0, 1 << m) {
            good[mask][mask2] = true;
            rep(i, 0, m - 1) {
                good[mask][mask2] &= (((mask >> i) & 1) ^ ((mask >> (i + 1)) & 1) ^ ((mask2 >> i) & 1) ^ ((mask2 >> (i + 1)) & 1));
            }
        }
    }
    // rep(i, 0, n) {
    //     cout << row[i] << endl;
    // }
    // dp[i][mask] := minimum number of changes where row i = mask
    rep(i, 1, n + 1) {
        rep(mask, 0, 1 << m) {
            int cost = __builtin_popcount(row[i - 1] ^ mask);
            dp[i][mask] = INT_MAX;
            rep(mask2, 0, 1 << m) {
                if(good[mask][mask2]) {
                    dp[i][mask] = min(dp[i][mask], cost + dp[i - 1][mask2]);
                }
            }
            // cout << dp[i][mask] << ' ';
        }
        // cout << endl;
    }
    cout << *min_element(dp[n], dp[n] + (1 << m)) << '\n';
}