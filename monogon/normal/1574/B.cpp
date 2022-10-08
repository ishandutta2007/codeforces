
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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a + b + c - 3 >= m && c - 1 - a - b <= m) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}