#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw[60];
ll ans[60];
ll n;
ll solve(ll n) {
    if (n == 0) return 0;
    for (int i = 59; i >= 0; i--) {
        if (n >= pw[i]) {
            if (n != pw[i]) return pw[i] + ans[i] + solve(n - pw[i]);
            else return ans[i];
        }
    }
}
int main() {
    //freopen("cruel.in", "r", stdin);
    //freopen("cruel.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    pw[0] = 1;
    for (int i = 1; i < 60; i++) pw[i] = 2 * pw[i - 1];
    ans[0] = 0;
    for (int i = 1; i < 60; i++) {
        ans[i] = 2 * ans[i - 1] + pw[i - 1];
    }
    cin >> n;
    cout << solve(n);
    return 0;
}