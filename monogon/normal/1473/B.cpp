
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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    auto check = [&](string a, string b) {
        int n = a.length(), m = b.length();
        if(n % m != 0) return false;
        rep(i, 0, n) {
            if(a[i] != b[i % m]) return false;
        }
        return true;
    };
    int len = lcm(n, m);
    string L = "";
    rep(i, 0, len / n) L += s;
    if(check(L, t)) {
        cout << L << '\n';
    }else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}