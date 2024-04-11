#include <bits/stdc++.h>
using namespace std;
int n;
string t;
const int inf = 10000000;
const int maxN = 100010;
int f[2 * 100010];
int main(){
    cin >> n >> t;
    int s = 0;
    int ans = 0;
    for (int i = 0; i < 2 * maxN; i++) f[i] = inf;
    f[0 + maxN] = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i - 1] == '0') s += -1;
        if (t[i - 1] == '1') s += 1;
        if (f[s + maxN] == inf) f[s + maxN] = i;
        ans = max(ans, i - f[s + maxN]);
    }
    cout << ans;
return 0;
}