
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
    // 1 + x + x/2 = n-3
    ll n;
    cin >> n;
    ll l = 1, r = n;
    while(l < r) {
        ll m = (l + r) / 2;
        if(1 + m + (m+1)/2 <= n - 3) {
            l = m + 1;
        }else {
            r = m;
        }
    }
    ll x = l - 1;
    cout << min((x+1)/2-1, x-(x+1)/2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}