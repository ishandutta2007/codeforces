
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
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }else {
            i += 2;
        }
    }
    if(j == m && (n - i) % 2 == 0) {
        cout << "YES\n";
        return;
    }
    i = 1;
    j = 0;
    while(i < n && j < m) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }else {
            i += 2;
        }
    }
    if(j == m && (n - i) % 2 == 0) {
        cout << "YES\n";
        return;
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