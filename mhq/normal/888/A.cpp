#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int t = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) t++;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) t++;
    }
    cout << t;
    return 0;
}