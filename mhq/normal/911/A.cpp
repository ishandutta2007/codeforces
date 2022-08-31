#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int mn = (int)1e9 + 10;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    int ans = (int)1e6;
    int ind = -(int)1e9;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mn) {
            ans = min(i - ind, ans);
            ind = i;
        }
    }
    cout << ans;
}