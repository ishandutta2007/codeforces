#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 100;
int c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int where = -1;
    for (int i = 1; i <= n; i++) {
        if (c[i] != c[1]) {
            where = i;
            break;
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (c[j] != c[1]) {
            ans = max(ans, j - 1);
        }
        else {
            ans = max(ans, abs(j - where));
        }
    }
    cout << ans;
    return 0;
}