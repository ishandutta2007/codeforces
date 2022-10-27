#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int n, lst = -1, ans = 0;
        cin >> n;
        for (int i = 0 ; i < n ; ++ i) {
            int b; cin >> b;
            ans += b - lst - 1;
            lst = b;
        }
        ans += 10 - lst - 1;
        cout << ans * (ans - 1) * 3 << '\n';
    }




}