#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int root, root_1, root_pw = 1 << 20;
int n, m;
char str[Maxn];

int toPower(int a, int p, int mod)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int reverse(int n, int mod)
{
	return toPower(n, mod - 2, mod);
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
		int nrev = reverse (n, mod);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<int> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] = ll(fa[i]) * fb[i] % mod;
	fft (fa, true);
	while (!fa.empty() && fa.back() == 0) fa.pop_back();
	res = fa;
}

void Add(vector <int> &V, int key, int val)
{
	while (V.size() <= key) V.push_back(0);
	V[key] = (V[key] + val) % mod;
}

void Solve(int l, int r, int &zer, vector <int> &W, vector <int> &B)
{
	zer = 0;
	W = {0};
	B = {0};
	if (l + 1 == r) {
		if ((str[l] == '?' || str[l] == 'w') && (str[r] == '?' || str[r] == 'w'))
			zer = (zer + 1) % mod;
		if ((str[l] == '?' || str[l] == 'w') && (str[r] == '?' || str[r] == 'b'))
			Add(W, 1, 1);
		if ((str[l] == '?' || str[l] == 'b') && (str[r] == '?' || str[r] == 'w'))
			Add(B, 1, 1);
		if ((str[l] == '?' || str[l] == 'b') && (str[r] == '?' || str[r] == 'b'))
			zer = (zer + 1) % mod;
	} else {
		int azer, bzer;
		vector <int> aW, bW;
		vector <int> aB, bB;
		int m = l + r >> 1;
		if ((m - l + 1) % 2) m++;
		Solve(l, m, azer, aW, aB);
		Solve(m + 1, r, bzer, bW, bB);
		zer = ll(azer) * bzer % mod;
		for (int i = 0; i < aW.size(); i++)
			Add(W, i, ll(aW[i]) * bzer % mod);
		for (int i = 0; i < aB.size(); i++)
			Add(B, i, ll(aB[i]) * bzer % mod);
		for (int i = 0; i < bW.size(); i++)
			Add(W, i, ll(bW[i]) * azer % mod);
		for (int i = 0; i < bB.size(); i++)
			Add(B, i, ll(bB[i]) * azer % mod);
		vector <int> tmp;
		multiply(aW, bW, tmp);
		for (int i = 0; i < tmp.size(); i++)
			Add(W, i, tmp[i]);
		multiply(aB, bB, tmp);
		for (int i = 0; i < tmp.size(); i++)
			Add(B, i, tmp[i]);
		int sub = int(bW.size()) - 1;
		reverse(bW.begin(), bW.end());
		multiply(aB, bW, tmp);
		for (int i = 0; i < tmp.size(); i++)
			if (i - sub < 0) Add(W, abs(i - sub), tmp[i]);
			else if (i - sub == 0) zer = (zer + tmp[i]) % mod;
			else Add(B, i - sub, tmp[i]);
		sub = int(bB.size()) - 1;
		reverse(bB.begin(), bB.end());
		multiply(aW, bB, tmp);
		for (int i = 0; i < tmp.size(); i++)
			if (i - sub < 0) Add(B, abs(i - sub), tmp[i]);
			else if (i - sub == 0) zer = (zer + tmp[i]) % mod;
			else Add(W, i - sub, tmp[i]);
	}
}

int main()
{
	root = toPower(3, 7 * 17 * 8, mod);
	root_1 = reverse(root, mod);
	scanf("%d %d", &n, &m);
	scanf("%s", str);
	vector <int> W, B;
	int zer;
	Solve(0, n - 1, zer, W, B);
	int all = (mod + 1) / 2;
	for (int i = 0; i < n; i++)
		if (str[i] == '?') all = ll(all) * 2 % mod;
	int sum = 0;
	for (int i = 2; i < W.size(); i += 2)
		sum = (sum + ll(i / 2) * W[i]) % mod;
	for (int i = 2; i < B.size(); i += 2)
		sum = (sum + ll(i / 2) * B[i]) % mod;
	int res = ll(sum) * reverse(all, mod) % mod;
	printf("%d\n", res);
    return 0;
}