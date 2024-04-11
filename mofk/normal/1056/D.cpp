#include <bits/stdc++.h>

using namespace std;

int n;
int dad[100005];
int f[100005];
int ans[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> dad[i];
    }
    for (int i = n; i >= 1; --i) {
        if (f[i] == 0) f[i] = 1;
        f[dad[i]] += f[i];
        ++ans[f[i]];
    }
    for (int i = 1; i <= n; ++i) ans[i] += ans[i-1];
    for (int i = 1; i <= n; ++i) for (int j = ans[i-1] + 1; j <= ans[i]; ++j) cout << i << ' ';
    cout << endl;
    return 0;
}