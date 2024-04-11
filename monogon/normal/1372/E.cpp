
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// some column should be maximized.
// apply to all intervals intersecting this column.
// then sum answers for the two halves
// answer dp[range] = answer for all intervals strictly in this range

const int N = 105;
int n, m, k[N], cnt[N], L[N], R[N];
vector<pii> ve[N];
ll dp[N][N];

void upd(int l, int r, int val) {
    rep(i, l, r + 1) {
        cnt[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> k[i];
        // ve[i].resize(k[i]);
        rep(j, 0, k[i]) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ve[i].emplace_back(l, r);
        }
    }
    rep(len, 1, m + 1) {
        fill(cnt, cnt + m, 0);
        fill(L, L + n, 0);
        fill(R, R + n, 0);
        rep(i, 0, m - len + 1) {
            rep(j, 0, n) {
                while(R[j] < k[j] && ve[j][R[j]].second < i + len) {
                    upd(ve[j][R[j]].first, ve[j][R[j]].second, 1);
                    R[j]++;
                }
                if(L[j] < R[j] && ve[j][L[j]].first < i) {
                    upd(ve[j][L[j]].first, ve[j][L[j]].second, -1);
                    L[j]++;
                }
            }
            rep(j, i, i + len) {
                dp[len][i] = max(dp[len][i], 1LL * cnt[j] * cnt[j] + dp[j - i][i] + dp[len - (j - i) - 1][j + 1]);
            }
        }
    }
    cout << dp[m][0] << '\n';
}