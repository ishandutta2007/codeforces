#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int MOD = 1e9 + 7;
using ll = int64_t;

int n;
char c;
string s;
int f[nax];

int p4(int x) {
    return 4ll * x % MOD;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k;
    cin >> k;
    /// f[i] is the number of ways to paint level x
    f[1] = 1;
    for (int i = 2 ; i <= k ; ++ i) {
        f[i] = 1ll * p4(f[i-1]) * p4(f[i-1]) % MOD;
    }
    cout << f[k] * 6ll % MOD;
}