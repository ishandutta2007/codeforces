
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

const int N = 105;
int n, s, x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int ans = -1;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        if(s * 100 >= x[i] * 100 + y[i]) {
            ans = max(ans, (100 - y[i]) % 100);
        }
    }
    cout << ans << '\n';
}