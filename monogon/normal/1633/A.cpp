
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
    string t = to_string(n);
    string s;
    int mi = 9;
    int ans = 0;
    for(int i = 0; i < 1000; i += 7) {
        s = to_string(i);
        int dif = 0;
        if(s.length() != t.length()) continue;
        rep(j, 0, 7) dif += (s[j] != t[j]);
        if(dif < mi) {
            mi = dif;
            ans = i;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}