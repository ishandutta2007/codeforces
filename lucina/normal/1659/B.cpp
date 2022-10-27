#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, k;
string s;
int f[nax];

void solve() {
    cin >> n >> k >> s;
    int res_k = k;
    fill(f, f + 1 + n, 0);
    for (int i = 0 ; i < n - 1 ; ++ i) {
        if (s[i] - '0' == k % 2 && res_k > 0) {
            res_k -= 1;
            f[i] += 1;
            s[i] = '1';
        } else s[i] ^= (k % 2);
    }
    int other = k - res_k;
    f[n - 1] = res_k;
    s[n - 1] ^= (other % 2);
    cout << s << '\n';
    for (int i = 0 ; i < n ; ++ i)
        cout << f[i] << ' ';
    cout << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}