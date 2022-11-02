#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;

char ans[N];
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n * 2 - 1; i += 1) {
            string x;
            cin >> x;
            for (int j = 0; j < m; j += 1) {
                ans[j] ^= x[j];
            }
        }
        for (int j = 0; j < m; j += 1) cout << ans[j], ans[j] = 0;
        cout << endl;
    }
}