#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[245676],v;
bool check[245678];
int n,m,ans,bb;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0;
    int p = 1LL << 60LL;
    while (p > 0) {
        s += p;
        vector<vector<bool>> d(n + 1, vector<bool>(k + 1));
        d[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (!d[i][j]) continue;
                int t = 0;
                for (int q = i; q < n; q++) {
                    t += a[q];
                    if ((t & s) == s) {
                        d[q + 1][j + 1] = true;
                    }
                }
            }
        }
        if (!d[n][k]) {
            s -= p;
        }
        p >>= 1;
    }

    cout << s;

    return 0;
}