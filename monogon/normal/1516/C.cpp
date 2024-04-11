
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
    vi a(n + 1);
    const int N = 2000 * 100 + 5;
    bitset<N> dp;
    dp[0] = true;
    int sum = 0;
    int g = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    rep(i, 1, n + 1) {
        a[i] /= g;
        dp |= (dp << a[i]);
        sum += a[i];
    }
    if(sum % 2 == 1 || !dp[sum / 2]) {
        cout << 0 << '\n';
        return 0;
    }
    rep(i, 1, n + 1) {
        if(a[i] % 2 == 1) {
            cout << 1 << '\n' << i << '\n';
            return 0;
        }
    }
    assert(false);
}