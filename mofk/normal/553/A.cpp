#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e3 + 5, mod = 1e9 + 7;

int k, a[MAX], s[MAX];
int f[MAX * MAX];

int pw(int a, int b) {
    int res = 1, mul = a;
    while (b) {
        if (b & 1) res = 1ll * res * mul % mod;
        mul = 1ll * mul * mul % mod;
        b >>= 1;
    }
    return res;
}

void init(void) {
    cin >> k;
    ff(i, 1, k) { cin >> a[i]; s[i] = s[i-1] + a[i]; }
    f[0] = 1;
    ff(i, 1, s[k] - 1) f[i] = 1ll * f[i-1] * i % mod;
}

void process(void) {
    int res = f[s[k]-1];
    ff(i, 1, k - 1) res = 1ll * res * pw(s[i], mod - 2) % mod;
    ff(i, 1, k) res = 1ll * res * pw(f[a[i]-1], mod - 2) % mod;
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}