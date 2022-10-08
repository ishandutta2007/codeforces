
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
    int n; ll m;
    string s;
    cin >> n >> m >> s;
    vector<ll> le(n), ri(n);
    rep(i, 0, n) {
        if(s[i] == '1') le[i] = 0;
        else if(i > 0) le[i] = le[i - 1] + 1;
        else le[i] = 2e9;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') ri[i] = 0;
        else if(i < n - 1) ri[i] = ri[i + 1] + 1;
        else ri[i] = 2e9;
    }
    rep(i, 0, n) {
        if(min(le[i], ri[i]) <= m && le[i] != ri[i]) s[i] = '1';
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}