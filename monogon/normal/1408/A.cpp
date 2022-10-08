
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n), b(n), c(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, n) cin >> c[i];
        vi ans(n);
        rep(i, 0, n) {
            ans[i] = a[i];
            if(i > 0 && ans[i] == ans[i - 1]) ans[i] = b[i];
            if(i == n - 1 && ans[i] == ans[0]) ans[i] = c[i];
            if(i > 0 && ans[i] == ans[i - 1]) ans[i] = b[i];
        }
        rep(i, 0, n) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}