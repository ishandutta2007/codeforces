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

const int MAX = 4e3 + 5, mod = 1e9 + 7;

int n;
int c[MAX][MAX];
int f[MAX][MAX];

void init(void) {
    cin >> n;
    ff(i, 0, n) c[i][0] = c[i][i] = 1;
    ff(i, 1, n) ff(j, 1, i - 1) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
}

void process(void) {
    f[0][0] = 1;
    ff(i, 1, n) ff(j, 1, i) f[i][j] = (f[i-1][j-1] + 1ll * j * f[i-1][j]) % mod;
    int res = 0;
    ff(i, 0, n - 1) ff(j, 0, i) res = (res + 1ll * c[n][i] * f[i][j]) % mod;
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}