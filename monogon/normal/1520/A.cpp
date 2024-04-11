
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2;
    s2.push_back(s[0]);
    rep(i, 1, n) if(s[i] != s[i - 1]) s2.push_back(s[i]);
    n = s2.length();
    rep(i, 0, n) rep(j, i + 1, n) {
        if(s2[i] == s2[j]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}