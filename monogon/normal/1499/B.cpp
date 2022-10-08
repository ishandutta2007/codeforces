
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
    int n = s.length();
    vector<bool> pref(n + 1, false), suf(n + 1, false);
    pref[0] = true;
    suf[n] = true;
    rep(i, 1, n + 1) {
        if(s[i - 1] == '0' || i == 1 || s[i - 2] == '0') {
            pref[i] = pref[i - 1];
        }else {
            pref[i] = false;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1' || i == n - 1 || s[i + 1] == '1') {
            suf[i] = suf[i + 1];
        }else {
            suf[i] = false;
        }
    }
    rep(i, 0, n + 1) {
        if(pref[i] && suf[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}