
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
        ll p, q;
        cin >> p >> q;
        ll ans = 1;
        ll p2 = p;
        auto check = [&](int i) {
            int ti = 0;
            while(q % i == 0) {
                q /= i;
                ti++;
            }
            int ti2 = 0;
            while(p % i == 0) {
                p /= i;
                ti2++;
            }
            ll pp = 1;
            // cout << i << ' ' << ti2 - ti << endl;
            for(int j = 0; j < ti2 - ti + 1; j++) pp *= i;
            ans = max(ans, p2 / pp);
        };
        for(ll i = 2; i * i <= q; i++) {
            if(q % i == 0) {
                check(i);
            }
        }
        if(q > 1) check(q);
        cout << ans << '\n';
    }
}