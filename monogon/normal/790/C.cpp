
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

const int N = 80;
int n;
string s;

ll dp[N][N][N], dp2[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int V = 0, K = 0, E = 0;
    vi vecV, vecK, vecE;
    rep(i, 0, n) {
        char c = s[i];
        if(c != 'V' && c != 'K') s[i] = 'E';
        if(c == 'V') {
            V++;
            vecV.push_back(i);
        }else if(c == 'K') {
            K++;
            vecK.push_back(i);
        }else {
            E++;
            vecE.push_back(i);
        }
    }
    rep(v, 0, V + 1) {
        rep(k, 0, K + 1) {
            rep(e, 0, E + 1) {
                int len = v + k + e;
                if(len == 0) continue;
                vi ve;
                rep(i, 0, v) ve.push_back(vecV[i]);
                rep(i, 0, k) ve.push_back(vecK[i]);
                rep(i, 0, e) ve.push_back(vecE[i]);
                sort(all(ve));
                dp[v][k][e] = 1e9 + 5;
                dp2[v][k][e] = 1e9 + 5;
                rep(i, 0, len) {
                    if(s[ve[i]] == 'V') dp[v][k][e] = min(dp[v][k][e], dp[v - 1][k][e] + len - i - 1);
                    if(s[ve[i]] == 'E') dp2[v][k][e] = min(dp2[v][k][e], dp[v][k][e - 1] + len - i - 1);
                }
                int amt = 0;
                ll cost = 0;
                for(int i = len - 1; i >= 0; i--) {
                    if(s[ve[i]] == 'K') {
                        cost += len - amt - i - 1;
                        amt++;
                        dp2[v][k][e] = min(dp2[v][k][e], cost + dp2[v][k - amt][e]);
                    }
                }
                if(v == 0) {
                    dp2[v][k][e] = 0;
                }
                dp[v][k][e] = min(dp[v][k][e], dp2[v][k][e]);
            }
        }
    }
    cout << dp[V][K][E] << '\n';
}