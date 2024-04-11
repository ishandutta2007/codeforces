#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int root_pw = 1<<23;
int root, root_1 = 4404020;

int toPower(int a, int p, int mod)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a, int mod) { return toPower(a, mod - 2, mod); }

int getRoot()
{
    int divs[] = {2, 7, 17};
    for (int i = 2; ; i++) {
        bool ok = true;
        for (int j = 0; j < 3 && ok; j++)
            ok = toPower(i, (mod - 1) / divs[j], mod) != 1;
        if (ok) return i;
    }
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
		int nrev = Inv(n, mod);
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
	res.resize(n);
	for (int i = 0; i < n; i++)
        res[i] = ll(fa[i]) * fb[i] % mod;
    fft(res, true);
    while (res.size() > 1 && res.back() == 0) res.pop_back();
}

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 1505;

int n;
vector <iii> E;
int B[Maxn][Maxn];
int par[Maxn], siz[Maxn];
vector <int> my[Maxn];
vector <int> seq[Maxn];
int mx[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b, int cost)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    if (mx[a] > cost) my[a][1] = 0;
    if (mx[b] > cost) my[b][1] = 0;
    vector <int> res;
    multiply(my[a], my[b], res);
    res[1]++;
    my[a] = res;
    mx[a] = max(mx[a], mx[b]);
    for (int i = 0; i < seq[a].size(); i++)
        for (int j = 0; j < seq[b].size(); j++)
            mx[a] = max(mx[a], B[seq[a][i]][seq[b][j]]);
    for (int j = 0; j < seq[b].size(); j++)
        seq[a].push_back(seq[b][j]);
    return true;
}

int main()
{
    root = toPower(getRoot(), 7 * 17, mod);
    root_1 = Inv(root, mod);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        par[i] = i; siz[i] = 1;
        seq[i].push_back(i);
        mx[i] = 0;
        my[i].push_back(0);
        my[i].push_back(1);
        for (int j = 1; j <= n; j++) {
            int a; scanf("%d", &a);
            B[i][j] = a;
            if (i < j) E.push_back(iii(a, ii(i, j)));
        }
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++)
        unionSet(E[i].second.first, E[i].second.second, E[i].first);
    vector <int> tmp = {1};
    for (int i = 1; i <= n; i++)
        if (getPar(i) == i) {
            vector <int> res;
            multiply(tmp, my[i], res);
            tmp = res;
        }
    for (int i = 1; i <= n; i++)
        printf("%d%c", tmp[i], i + 1 <= n? ' ': '\n');
    return 0;
}