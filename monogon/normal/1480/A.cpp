
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
    rep(i, 0, n) {
        if(i % 2 == 0) {
            if(s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
        }else {
            if(s[i] == 'z') s[i] = 'y';
            else s[i] = 'z';
        }
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