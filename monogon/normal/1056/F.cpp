
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

const double EPS = 1e-5;
const int N = 101, P = 11;
int n, a[N], p[N];
double C, T;
double dp[N * P][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> C >> T;
        vector<pii> ve;
        rep(i, 1, n + 1) {
            cin >> a[i] >> p[i];
            ve.emplace_back(a[i], p[i]);
        }
        sort(all(ve));
        rep(i, 0, n) {
            tie(a[i + 1], p[i + 1]) = ve[i];
        }
        ll ans = 0;
        rep(score, 0, N * P) {
            rep(i, 1, n + 1) {
                rep(k, 0, n + 1) {
                    if(k == 0) {
                        if(score == 0) dp[score][i][k] = 0;
                        else dp[score][i][k] = DBL_MAX;
                    }else if(i == 1) {
                        if(k == 1 && score == p[i]) dp[score][i][k] = a[i];
                        else dp[score][i][k] = DBL_MAX;
                    }else {
                        dp[score][i][k] = dp[score][i - 1][k];
                        if(p[i] <= score) {
                            double x = dp[score - p[i]][i - 1][k - 1];
                            if(x != DBL_MAX && (dp[score][i][k] == DBL_MAX || a[i] + x / 0.9 < dp[score][i][k])) {
                                dp[score][i][k] = a[i] + x / 0.9;
                            }
                        }
                    }
                    double x = dp[score][i][k];
                    if(i == n && score > ans && x != DBL_MAX) {
                        double t = max(0.0, min((C * (T - 10 * k) - 1) / (2 * C), T - 10 * k));
                        if(t > -EPS && x / 0.9 < EPS + (1 + C * t) * (T - 10 * k - t)) {
                            ans = score;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}