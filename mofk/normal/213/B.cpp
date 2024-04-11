#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1000000007;
int N, a[10];
int c[105][105];
int f[105][10];

int main(void) {
    cin >> N; ff(i, 0, 9) cin >> a[i];
    ff(i, 0, N) { c[i][0] = 1; ff(j, 1, i) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod; }
    ff(i, 0, N) {
        f[i][9] = (i >= a[9]);
        fb(j, 8, 1) ff(k, a[j], i) f[i][j] = (f[i][j] + 1ll * c[i][k] * f[i-k][j+1]) % mod;
        ff(k, a[0], i) f[i][0] = (f[i][0] + 1ll * c[i-1][k] * f[i-k][1]) % mod;
//        ff(j, 0, 9) cout << f[i][j] << " "; cout << endl;
    }
    int ans = 0; ff(i, 1, N) ans = (ans + f[i][0]) % mod;
    cout << ans << endl;
    return 0;
}