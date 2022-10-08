
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
    s = "$" + s;
    rep(i, 1, n + 1) {
        if(s[i] == '0') {
            if(i <= n / 2) {
                cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
                return;
            }else {
                cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << '\n';
                return;
            }
        }
    }
    cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}