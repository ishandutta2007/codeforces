#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 1000003;

int64 fexp(int64 a, int64 n){
    if (n == 0) return 1;
    if (n & 1) return a * fexp(a, n - 1) % mod;
    return fexp(a * a % mod, n / 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int64 n, k;
    cin >> n >> k;

    if (n <= 60){
        int64 v = 1LL << n;
        if (k > v){
            cout << 1 << " " << 1 << endl;
            return 0;
        }
    }

    int64 ii = fexp(2, n);
    int64 pp = 2;

    while ((k - 1) / pp){
        ii = ii * fexp(2, (k - 1) / pp) % mod;
        pp *= 2;
    }


    ii = fexp(ii, mod - 2);

    int64 v2n = fexp(2, n);
    int64 den = fexp(v2n, k);

    int64 tmp = 1;

    for (int64 i = 0; i < min(k, mod); ++i){
        tmp = tmp * ((v2n - i + mod) % mod) % mod;
    }

    int64 num = (den - tmp + mod) % mod;
    num = num * ii % mod;
    den = den * ii % mod;

    cout << num << " " << den << endl;

    return 0;
}