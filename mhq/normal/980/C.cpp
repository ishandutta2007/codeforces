#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, k;
int p[maxN];
int val[270];
const int INF = 300;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < 256; i++) {
        val[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (val[x] != INF) {
            cout << val[x] << " ";
            continue;
        }
        int cnt = max(x - k + 1, 0);
        for (int j = x; j >= max(x - k + 1, 0); j--) {
            if (x - val[j] >= k) {
                cnt = j + 1;
                break;
            }
        }
        for (int j = x; j >= cnt; j--) {
            val[j] = cnt;
        }
        cout << val[x] << " ";
    }
    return 0;
}