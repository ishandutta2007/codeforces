#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
int root, root_1;
const int root_pw = 1<<19;
const int Maxm = root_pw;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); } 
 
void fft (int a[], bool invert) {
    int n = root_pw;
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = Inv(n);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

int n, k, f;
int ways[Maxm];

void Simplify()
{
    int sum = 0;
    for (int i = k + 1; i < Maxm; i++) {
        sum = (sum + ways[i]) % mod;
        ways[i] = 0;
    }
    for (int i = k; i >= 0; i--) {
        int oldsum = sum;
        sum = (sum + ways[i]) % mod;
        ways[i] = (ll(k - i + 1) * ways[i] + oldsum) % mod;
    }
}

int main()
{
    root = toPower(3, 1904);
    root_1 = Inv(root);
    scanf("%d %d %d", &n, &k, &f);
    ways[Maxm - 1] = 1;
    for (int i = 0; i < n; i++) {
        Simplify();
        fft(ways, false);
        for (int j = 0; j < Maxm; j++)
            ways[j] = ll(ways[j]) * ways[j] % mod;
        fft(ways, true);
    }
    printf("%d\n", ways[f]);
    return 0;
}