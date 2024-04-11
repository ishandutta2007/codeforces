#include <bits/stdc++.h>
using namespace std;
int k, n, m;
const int maxN = (int)1e5 + 10;
string s[maxN];
map < string, int > q;
int a[maxN];
int mean[maxN];
int val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //1 - verno
    // 2 - verno
    // 3 - verno
    // 4 - verno
    // 5
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        q[s[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        val[i] = (int)1e9 + 50;
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int p;
            cin >> p;
            mean[p] = i;
            val[i] = min(val[i], a[p]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int pos = q[s];
        //cout << pos << endl;
        ans += val[mean[pos]];
    }
    cout << ans;
    return 0;
}