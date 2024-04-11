
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
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    rep(i, 0, n) {
        if(s[i].length() == 1) {
            cout << "YES\n";
            return;
        }
    }
    set<string> se, se2;
    rep(i, 0, n) {
        string t = s[i];
        reverse(all(t));
        se.insert(t);
        if(se.count(s[i])) {
            cout << "YES\n";
            return;
        }
        if(t.length() == 2) {
            if(se2.count(s[i])) {
                cout << "YES\n";
                return;
            }
        }
        if(t.length() == 3) {
            if(se.count(s[i].substr(1, 2))) {
                cout << "YES\n";
                return;
            }
        }
        if(t.length() == 3) {
            se2.insert(t.substr(1, 2));
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