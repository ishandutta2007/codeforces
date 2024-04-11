#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string a, b;
int n;
const int maxN = (int)1e6 + 10;
bool used[maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (a[i] == b[i]) continue;
        if (i + 1 < n && a[i + 1] != b[i + 1] && a[i + 1] != a[i]) {
            used[i + 1] = true;
            used[i] = true;
            ans++;
        }
        else {
            used[i] = true;
            ans++;
        }
    }
    cout << ans;
    return 0;
}