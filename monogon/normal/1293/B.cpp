
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
double ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ans += 1.0 / i;
    }
    cout << fixed << setprecision(8) << ans << endl;
}