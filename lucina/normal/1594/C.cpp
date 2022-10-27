#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int MOD = 1e9 + 7;
using ll = int64_t;

int n;
char c;
string s;


void solve() {
    cin >> n >> c >> s;
    int cnt_c = count(s.begin(), s.end(), c);
    if (cnt_c == n) {
        cout << 0 << '\n';
        return;
    }
    s = '#' + s;


    for (int i = 1 ; i <= n ; ++ i) {
        bool ok = true;
        for (int j = i ; j <= n ; j += i)
            ok &= (s[j] == c);
        if (ok) {
            cout << "1\n" << i << '\n';
            return;
        }
    }
    cout << 2 << '\n' << n - 1 << ' ' << n << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;


    for (cin >> T ; T -- ;) {
        solve();
    }
}