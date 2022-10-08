#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<string> se;
    rep(i, 0, n) {
        string ss;
        for(int k = 0; k < 5 && i + k < n; k++) {
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
    rep(len, 1, 6) {
        string t(len, 'a');
        while(true) {
            if(se.count(t) == 0) {
                cout << t << '\n';
                return;
            }
            int idx = len - 1;
            while(idx >= 0 && t[idx] == 'z') {
                t[idx] = 'a';
                idx--;
            }
            if(idx < 0) break;
            t[idx]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}