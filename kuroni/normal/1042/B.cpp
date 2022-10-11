#include <bits/stdc++.h>
using namespace std;

const int INF = 1E8 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> xd(8, INF);
    for (int i = 0; i < n; i++) {
        int c; string s; cin >> c >> s;
        int msk = 0;
        for (char ch : s) {
            msk |= (1 << (ch - 'A'));
        }
        xd[msk] = min(xd[msk], c);
    }
    int ans = INF;
    for (int msk = 0; msk < (1 << 8); msk++) {
        int sum = 0, cur = 0;
        for (int i = 0; i < 8; i++) {
            if (msk >> i & 1) {
                sum += xd[i];
                cur |= i;
            }
        }
        if (cur == 7) {
            ans = min(ans, sum);
        }
    }
    cout << (ans == INF ? -1 : ans);
}