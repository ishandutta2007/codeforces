#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 5;
int n;
int L[maxN];
bool used[maxN];
int ans;
int curr = maxN;
int main() {
    //freopen("input.txt", "r", stdin);
    //cout << mult(100000, 100000);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = n; i >= 1; i--) {
        if (i < curr) ans++;
        curr = min(i - L[i], curr);
    }
    cout << ans;
    return 0;
}