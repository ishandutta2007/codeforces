#include <bits/stdc++.h>
using namespace std;
int _ = (cout << fixed << setprecision(9), cin.tie(0), ios::sync_with_stdio(0));
using Int = long long;
const Int MOD = 1000000007;
Int modpow(Int x, Int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return modpow(x * x % MOD, y / 2);
    return x * modpow(x, y - 1) % MOD;
}
int main() {
    Int N, M, K, R, C; cin >> N >> M >> K >> R >> C;
    Int Ax, Ay, Bx, By; cin >> Ax >> Ay >> Bx >> By;
    if (Ax == Bx && Ay == By) {
        cout << modpow(K, N * M) << '\n';
    } else {
        cout << modpow(K, N * M - R * C) << '\n';
    }
    return 0;
}