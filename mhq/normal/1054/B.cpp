#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
int a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int cur_mex = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > cur_mex + 1) {
            cout << i;
            return 0;
        }
        cur_mex = max(cur_mex, a[i]);
    }
    cout << -1;
    return 0;
}