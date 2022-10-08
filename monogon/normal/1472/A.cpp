
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
    ll w, h, n;
    ll cnt = 1;
    cin >> w >> h >> n;
    while(w % 2 == 0) {
        w /= 2;
        cnt *= 2;
    }
    while(h % 2 == 0) {
        h /= 2;
        cnt *= 2;
    }
    cout << (cnt >= n ? "YES" : "NO") << '\n';
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