
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
        vector<ll> t(n + 1), x(n + 1);
        rep(i, 0, n) {
            cin >> t[i] >> x[i];
        }
        t[n] = 1e10;
        x[n] = 0;
        int cmd = -1, ans = 0;
        ll pos = 0, ti = 0;
        rep(i, 0, n + 1) {
            if(i > 0) {
                ll adv = min(t[i] - ti, abs(pos - x[cmd]));
                ll newpos = pos + (pos < x[cmd] ? adv : -adv);
                if(min(pos, newpos) <= x[i - 1] && x[i - 1] <= max(pos, newpos)) {
                    ans++;
                }
                pos = newpos;
                ti += adv;
            }
            if(cmd == -1 || pos == x[cmd]) {
                ti = t[i];
                cmd = i;
            }
        }
        cout << ans << '\n';
    }
}