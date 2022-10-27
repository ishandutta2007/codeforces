#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;
char s[nax];
void solve() {
    cin >> n >> s + 1;
    /// there is no 'aa' in substring?
    /// 'abca

    for (int l = 2 ; l <= 10 ; ++ l) {
        for (int i = 1 ; i + l - 1 <= n ; ++ i) {
            int a[3]{};
            for (int j = 0 ; j < l ; ++ j)
                a[s[i + j] - 'a'] += 1;
            if (a[0] > max(a[1], a[2])) {
                cout << l << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Missing the contest. :3
*/