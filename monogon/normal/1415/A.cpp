
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
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll d = 0;
    for(ll i : {1ll, n}) for(ll j : {1ll, m}) {
        d = max(d, abs(i - r) + abs(j - c));
    }
    cout << d << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}