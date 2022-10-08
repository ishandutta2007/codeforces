
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, M = 998244353;
int n;
ll pow10[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow10[0] = 1;
    for(int i = 1; i < N; i++) {
        pow10[i] = (10 * pow10[i - 1]) % M;
    }
    cin >> n;
    for(int i = 1; i < n; i++) {
        ll ans = ((((n - i - 1) * 9 * 9) % M) * pow10[n - i - 1] + ((2 * 9 * pow10[n - i]) % M)) % M;
        cout << ans << " ";
    }
    cout << "10\n";
}