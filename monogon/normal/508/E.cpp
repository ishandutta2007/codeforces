
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

const int N = 605;
int n, l[N], r[N];
bool dp[N][N];
string s;

void solve(int i, int len, int L) {
    if(len == 0) return;
    s[L] = '(';
    for(int j = l[i]; j <= r[i]; j += 2) {
        if(dp[j / 2][i + 1] && dp[len - j / 2 - 1][i + j / 2 + 1]) {
            solve(i + 1, j / 2, L + 1);
            solve(i + j / 2 + 1, len - j / 2 - 1, L + j + 1);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> l[i] >> r[i];
        if(l[i] % 2 == 0) l[i]++;
    }
    rep(i, 0, n + 1) dp[0][i] = true;
    rep(len, 1, n + 1) {
        rep(i, 0, n - len + 1) {
            for(int j = l[i]; j <= r[i]; j += 2) {
                if(dp[j / 2][i + 1] && dp[len - j / 2 - 1][i + j / 2 + 1]) {
                    dp[len][i] = true;
                }
            }
        }
    }
    if(!dp[n][0]) {
        cout << "IMPOSSIBLE\n";
    }else {
        s.assign(2 * n, ')');
        solve(0, n, 0);
        cout << s << '\n';
    }
}