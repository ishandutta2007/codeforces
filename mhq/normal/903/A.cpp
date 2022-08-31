#include <bits/stdc++.h>
using namespace std;
int n;
int a;
void solve() {
    cin >> a;
    for (int i = 0; i <= a; i++) {
        if (a - 3 * i >= 0 && (a - 3 * i) % 7 == 0) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) solve();
	return 0;
}