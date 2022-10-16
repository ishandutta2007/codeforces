#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;
const int64 mod = 1000000009;

int64 M(int64 a){
    return (a % mod + mod) % mod;
}

int64 modpow(int64 a, int64 n){
    int64 b = 1;

    while (n){
        if (n & 1)
            b = a * b % mod;
        a = a * a % mod;
        n >>= 1;
    }

    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, a, b, k;
    cin >> n >> a >> b >> k;

    int64 B = 1, A = modpow(a, n), IA = 1;
    int64 ia = modpow(a, mod - 2);

    string s; cin >> s;

    int64 x = 0;

    for (int i = 0; i < k; ++i){
        int64 v = s[i] == '+' ? +1 : mod - 1;

        x = (x + v * B % mod * A % mod) % mod;

        B = B * b % mod;
        A = A * ia % mod;
        IA = IA * ia % mod;
    }

    int64 Y = B * IA % mod;
    int64 t = (n + 1) / k;
    int64 ans;

    if (Y == 1)
        ans = x * t % mod;
    else
        ans = x * (modpow(Y, t) - 1 + mod) % mod * modpow(Y - 1, mod - 2) % mod;

    cout << ans << endl;

    return 0;
}