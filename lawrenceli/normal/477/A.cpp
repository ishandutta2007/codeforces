#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    int a, b;
    cin >> a >> b;
    ll ans = 0;
    for (int m=0; m<b; m++)
        ans = (ans+ll(m)*((a+ll(b)*((ll(a)*(a+1)/2)%MOD))%MOD)%MOD)%MOD;
    cout << ans << endl;
}