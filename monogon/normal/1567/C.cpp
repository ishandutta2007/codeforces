
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
    string s;
    cin >> s;
    ll a = 0, b = 0;
    // reverse(all(s));
    int n = s.length();
    rep(i, 0, n) {
        if(i % 2 == 0) {
            a = 10 * a + (s[i] - '0');
        }else {
            b = 10 * b + (s[i] - '0');
        }
    }
    // cout << a << ' ' << b << '\n';
    cout << (a + 1) * (b + 1) - 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}