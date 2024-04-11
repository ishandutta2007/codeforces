#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int mxa = -1e9, mxb = -1e9;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            mxa = max(mxa, a);
            mxb = max(mxb, b);
        }
        if (mxa + mxb > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < mxa; i++)
                cout << 'R';
            for (int i = 0; i < mxb; i++)
                cout << 'W';
            for (int i = 0; i < n - mxa - mxb; i++)
                cout << 'R';
            cout << '\n';
        }
    }
    return 0;
}