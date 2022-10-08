
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

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    multiset<ll> s;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    multiset<ll> dif;
    for(auto it = s.begin(); it != s.end(); it++) {
        if(it != s.begin()) {
            dif.insert(*it - *prev(it));
        }
    }
    if(sz(s) <= 2) {
        cout << 0 << '\n';
    }else {
        cout << *prev(s.end()) - *s.begin() - *prev(dif.end()) << '\n';
    }
    while(q--) {
        int ty;
        ll p;
        cin >> ty >> p;
        if(ty == 0) {
            // remove
            s.erase(s.find(p));
            auto it = s.lower_bound(p);
            if(it != s.end()) {
                dif.erase(dif.find(*it - p));
            }
            if(it != s.begin()) {
                dif.erase(dif.find(p - *prev(it)));
            }
            if(it != s.end() && it != s.begin()) {
                dif.insert(*it - *prev(it));
            }
        }else {
            // insert
            auto it = s.lower_bound(p);
            if(it != s.end()) {
                dif.insert(*it - p);
            }
            if(it != s.begin()) {
                dif.insert(p - *prev(it));
            }
            if(it != s.end() && it != s.begin()) {
                dif.erase(dif.find(*it - *prev(it)));
            }
            s.insert(p);
        }
        if(sz(s) <= 2) {
            cout << 0 << '\n';
        }else {
            cout << *prev(s.end()) - *s.begin() - *prev(dif.end()) << '\n';
        }
    }
}