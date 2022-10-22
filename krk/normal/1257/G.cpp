#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 998244353;
int r, rpw;
int root, root_1;
int root_pw = 1 << 23;
const int Maxn = 200005;
const int Maxm = 5000005;

int n;
int pw[Maxm];
int par[Maxn], len;
vector <int> V[Maxn];
priority_queue <ii> Q;

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

int getRoot()
{
    int prims[3] = {2, 7, 17};
    for (int i = 2; ; i++) {
        bool ok = true;
        for (int j = 0; j < 3 && ok; j++)
            ok = toPower(i, (mod - 1) / prims[j]) != 1;
        if (ok) return i;
    }
}

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
    root = r; root_pw = rpw;
    while (root_pw > a.size()) {
        root = ll(root) * root % mod;
        root_pw >>= 1;
    }
    root_1 = Inv(root);
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

void Multiply(vector <int> A, vector <int> B, vector <int> &C)
{
    int n = 1;
    while (n < A.size() || n < B.size()) n <<= 1;
    n <<= 1;
    A.resize(n, 0); B.resize(n, 0);
    fft(A, false); fft(B, false);
    C.resize(n);
    for (int i = 0; i < n; i++)
        C[i] = ll(A[i]) * B[i] % mod;
    fft(C, true);
    while (C.size() >= 2 && C.back() == 0) C.pop_back();
}

int main()
{
    r = toPower(getRoot(), 7 * 17);
    rpw = 1 << 23;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        pw[a]++;
    }
    for (int i = 0; i < Maxm; i++) if (pw[i]) {
        par[len] = len;
        V[len].resize(pw[i] + 1, 1);
        Q.push(ii(-int(V[len].size()), len));
        len++;
    }
    while (Q.size() > 1) {
        int a = Q.top().second; Q.pop();
        int b = Q.top().second; Q.pop();
        vector <int> tmp; Multiply(V[par[a]], V[par[b]], tmp);
        V[par[a]] = tmp; par[b] = par[a];
        Q.push(ii(-int(V[par[a]].size()), a));
    }
    int v = Q.top().second;
    printf("%d\n", n / 2 >= V[par[v]].size()? 0: V[par[v]][n / 2]);
    return 0;
}