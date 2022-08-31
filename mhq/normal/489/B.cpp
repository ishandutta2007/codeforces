#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[150];
int b[150];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = 0;
    int cura = 1;
    int curb = 1;
    while (cura <= n && curb <= m){
        if (abs(a[cura] - b[curb]) <= 1) {
            ans++;
            cura++;
            curb++;
            continue;
        }
        if (a[cura] > b[curb]) curb++;
        else cura++;
    }
    cout << ans;
    return 0;
}