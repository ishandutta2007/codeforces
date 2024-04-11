
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
    int a, b, c;
    cin >> a >> b >> c;
    rep(i, 0, a - c + 1) cout << 1;
    rep(i, 0, c - 1) cout << 0;
    cout << ' ';
    cout << 1;
    rep(i, 0, b - 1) cout << 0;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}