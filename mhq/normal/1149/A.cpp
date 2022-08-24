#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, cnt2, cnt1;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 2) cnt2++;
        else cnt1++;
    }
    if (cnt1 == 0) {
        for (int i = 1; i <= n; i++) cout << 2 << " ";
        return 0;
    }
    else if (cnt2 == 0) {
        for (int i = 1; i <= n; i++) cout << 1 << " ";
        return 0;
    }
    cout << 2 << " ";
    cnt2--;
    cout << 1 << " ";
    cnt1--;
    for (int i = 1; i <= cnt2; i++) cout << 2 << " ";
    for (int i = 1; i <= cnt1; i++) cout << 1 << " ";
    return 0;
}