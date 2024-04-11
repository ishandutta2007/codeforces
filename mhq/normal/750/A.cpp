#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, k;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    ll cur = 0;
    for (int task = 1; task <= n + 1; task++) {
        cur += task * 5;
        if (cur > 240 - k || task == n + 1) {
            cout << task - 1;
            return 0;
        }
    }
    return 0;
}