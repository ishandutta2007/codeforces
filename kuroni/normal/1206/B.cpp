#include <bits/stdc++.h>
using namespace std;
 
int n, a, tmp = 1;
long long ans = 0;
bool chk = false;
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a < 0) {
            ans += -a - 1;
            tmp *= -1;
        } else if (a > 0) {
            ans += a - 1;
        } else {
            ans++;
            chk = true;
        }
    }
    if (!chk && tmp == -1) {
        ans += 2;
    }
    cout << ans;
}