
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1), x(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        x[i] = x[i - 1] ^ a[i];
    }
    const int N = (1 << 20);
    vi pos(N);
    int ans = 0;
    rep(k, 0, 21) {
        fill(all(pos), -1);
        int z = 0;
        pos[0] = 0;
        rep(i, 1, n + 1) {
            if(~a[i] >> k & 1) {
                z = i;
            }
            if(pos[x[i]] >= z) {
                ans = max(ans, i - pos[x[i]]);
            }
            if(pos[x[i]] < z) pos[x[i]] = i;
        }
        rep(i, 0, n + 1) x[i] &= ~(1 << k);
    }
    cout << ans << '\n';
}