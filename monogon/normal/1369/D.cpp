
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

const int N = 2e6 + 5, M = 1e9 + 7;
int t, n;
ll dp0[N], dp1[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 3, N) {
        dp0[i] = (2 * dp1[i - 2] + dp1[i - 1]) % M;
        if(i % 3 == 0) {
            dp1[i] = (4 + 2 * dp0[i - 2] + dp0[i - 1]) % M;
        }else {
            dp1[i] = dp0[i];
        }
    }
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp1[n] << '\n';
    }
}