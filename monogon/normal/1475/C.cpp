
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
        int a, b, k;
        cin >> a >> b >> k;
        vi orz(a + 1), uwu(b + 1);
        rep(i, 0, k) {
            int x;
            cin >> x;
            orz[x]++;
        }
        rep(i, 0, k) {
            int x;
            cin >> x;
            uwu[x]++;
        }
        ll ans = 1LL * k * (k - 1) / 2;
        rep(i, 1, a + 1) ans -= 1LL * orz[i] * (orz[i] - 1) / 2;
        rep(i, 1, b + 1) ans -= 1LL * uwu[i] * (uwu[i] - 1) / 2;
        cout << ans << "\n";
    }
}