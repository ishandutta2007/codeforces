
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

const int X = 1e6 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    vector<bool> seen(X, false);
    vector<int> last(X, 0);
    rep(i, 0, n) {
        cin >> a[i];
        seen[a[i]] = true;
    }
    rep(i, 1, X) {
        last[i] = last[i - 1];
        if(seen[i]) last[i] = i;
    }
    int ans = 0;
    rep(i, 1, X) {
        if(seen[i]) {
            for(int p = 2 * i; p < X; p += i) {
                if(last[p - 1] > i) {
                    ans = max(ans, last[p - 1] % i);
                }
            }
            if(last[X - 1] > i) ans = max(ans, last[X - 1] % i);
        }
    }
    cout << ans << '\n';
}