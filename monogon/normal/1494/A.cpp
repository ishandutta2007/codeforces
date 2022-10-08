
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
    rep(mask, 0, 8) {
        int cnt = 0;
        bool flag = true;
        rep(i, 0, n) {
            int c = s[i] - 'A';
            if(mask >> c & 1) {
                cnt++;
            }else {
                cnt--;
            }
            if(cnt < 0) flag = false;
        }
        if(cnt != 0) flag = false;
        if(flag) {
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