
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
    reverse(all(s));
    int n = s.length();
    int ans = INT_MAX;
    for(string t : {"00", "52", "05", "57"}) {
        int i = 0, j = 0;
        while(i < n && j < 2) {
            if(s[i] == t[j]) j++;
            i++;
        }
        if(j == 2) {
            ans = min(ans, i - 2);
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