
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
    ll c1, c2, c3, a1, a2, a3, a4, a5;
    cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;
    c1 -= a1;
    c2 -= a2;
    c3 -= a3;
    if(c1 < 0 || c2 < 0 || c3 < 0) {
        cout << "NO\n";
        return;
    }
    ll k1 = min(a4, c1);
    ll k2 = min(a5, c2);
    if(c3 - a4 + k1 - a5 + k2 < 0) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}