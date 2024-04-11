#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, LG = 30;

int n, m, u, ans = 0, a[N];
vector<int> b[LG + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (m--) {
        cin >> u;
        b[u].push_back(1);
    }
    for (int i = 0; i < LG; i++) {
        int dis = 0, cnt = b[i].size();
        for (int j = 0; j < n; j++) {
            if (a[j] % 2 == 1 && dis < cnt) {
                dis++;
            }
            a[j] /= 2;
        }
        ans += accumulate(b[i].end() - dis, b[i].end(), 0);
        if ((cnt - dis) % 2 == 1) {
            b[i + 1].push_back(b[i][0]);
        }
        for (int j = (cnt - dis) % 2; j < cnt - dis; j += 2) {
            b[i + 1].push_back(b[i][j] + b[i][j + 1]);
        }
    }
    cout << ans;
}