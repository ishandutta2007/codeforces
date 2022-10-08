
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
        ll n;
        cin >> n;
        map<ll, int> ma;
        int s = 1;
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                int cnt = 0;
                while(n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ma[i] = cnt;
                s = max(s, cnt);
            }
        }
        if(n > 1) {
            ma[n] = 1;
        }
        vector<ll> ans(s, 1);
        for(auto &pa : ma) {
            ll p; int cnt;
            tie(p, cnt) = pa;
            rep(i, 0, cnt) {
                ans[s - i - 1] *= p;
            }
        }
        cout << s << '\n';
        rep(i, 0, s) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}