
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

void solve() {
    int n;
    cin >> n;
    set<ll> s;
    ll pr = -1;
    bool flag = true;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        if(!s.empty()) {
            auto it = s.find(pr);
            if((a > pr && it != prev(s.end()) && *next(it) < a) || (a < pr && it != s.begin() && *prev(it) > a)) {
                flag = false;
            }
        }
        s.insert(a);
        pr = a;
    }
    cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}