#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
int root, root_1;
const int root_pw = 1<<18;
const int Maxn = 100005;
const int nil = Maxn;

int n;
char B[Maxn][3];
vector <int> seq;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();

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
		int nrev = toPower (n, mod - 2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

bool Check(char a, char b)
{
    for (int i = 0; i < n; i++)
        if (B[i][0] != a && B[i][0] != '?' ||
            B[i][1] != b && B[i][1] != '?')
            return false;
    return true;
}

int simpleWays()
{
    int res = 1;
    for (int i = 0; i < n; i++) {
        int cur = int((B[i][0] == 'W' || B[i][0] == '?') && (B[i][1] == 'B' || B[i][1] == '?')) +
                  int((B[i][0] == 'B' || B[i][0] == '?') && (B[i][1] == 'W' || B[i][1] == '?'));
        res = ll(res) * cur % mod;
    }
    return res;
}

void Multiply(vector <int> &A, vector <int> &B)
{
    for (int i = 0; i < A.size(); i++)
        A[i] = ll(A[i]) * B[i] % mod;
}

int main()
{
    root = toPower(3, 3808);
    root_1 = toPower(root, mod - 2);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    int res = (int(Check('W', 'B')) + int(Check('B', 'W')) - simpleWays() + mod) % mod;
    int bas = 0;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
        if (B[i][0] == '?' && B[i][1] == '?') { bas++; a++; }
        else if (B[i][0] == '?' && B[i][1] == 'B') b++;
        else if (B[i][0] == '?' && B[i][1] == 'W') { bas++; b++; }
        else if (B[i][0] == 'B' && B[i][1] == '?') b++;
        else if (B[i][0] == 'B' && B[i][1] == 'B') bas--;
        else if (B[i][0] == 'B' && B[i][1] == 'W') ;
        else if (B[i][0] == 'W' && B[i][1] == '?') { bas++; b++; }
        else if (B[i][0] == 'W' && B[i][1] == 'B') ;
        else if (B[i][0] == 'W' && B[i][1] == 'W') bas++;
    seq.resize(root_pw, 0);
    seq[0] = 1;
    fft(seq, false);
    vector <int> V(root_pw, 0);
    V[0] = V[2] = 1;
    V[1] = 2;
    fft(V, false);
    while (a) {
        if (a & 1) Multiply(seq, V);
        a >>= 1; Multiply(V, V);
    }
    V.clear();
    V.resize(root_pw, 0);
    V[0] = V[1] = 1;
    fft(V, false);
    while (b) {
        if (b & 1) Multiply(seq, V);
        b >>= 1; Multiply(V, V);
    }
    fft(seq, true);
    if (0 <= bas && bas < root_pw)
        res = (res + seq[bas]) % mod;
    printf("%d\n", res);
    return 0;
}