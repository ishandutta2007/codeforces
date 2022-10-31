#include<bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a==b) cout << 0 << endl;
    else {
        int pos = 64 - __builtin_clzll(a^b);
        long long ans = (1ll << pos) - 1;
        cout << ans << endl;
    }
}