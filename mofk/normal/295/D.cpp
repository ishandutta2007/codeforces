#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1000000007;
void add(int& a, int b) { a += b; if (a >= mod) a -= mod; }
void sub(int& a, int b) { add(a, mod - b); }

int N, M;
int f[2005][2005];
int s[2005][2005];
int t[2005][2005];

int main(void) {
    cin >> N >> M;
    ff(i, 1, N) ff(j, 2, M) {
        f[i][j] = (1 + ll(j+1) * s[i-1][j] - t[i-1][j] + mod) % mod;
        s[i][j] = (s[i][j-1] + f[i][j]) % mod;
        t[i][j] = (t[i][j-1] + (ll)j * f[i][j]) % mod;
    }
    int ans = 0;
    ff(i, 1, N) ff(j, 2, M) ans = (ans + 1ll * (1 + (ll)(j+1) * s[N-i][j-1] - t[N-i][j-1] + mod) % mod * (M - j + 1) % mod * f[i][j] % mod) % mod;
    cout << ans << endl;
    return 0;
}