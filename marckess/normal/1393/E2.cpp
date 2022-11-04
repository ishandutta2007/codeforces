#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, LG = 20, mod = 1000000007;
int sa[MX], lcp[MX], f[MX], S[MX];

inline bool leq (int a1, int a2, int b1, int b2) {
	return a1 < b1 || a1 == b1 && a2 <= b2;
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3); 
}

int c[2 * MX];
void radixPass (int a[], int b[], int r[], int n, int K)  {
	forn (i, K + 1) c[i] = 0;
	forn (i, n) c[r[a[i]]]++;
	
	for (int i = 0, sum = 0; i <= K; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}

	forn (i, n) b[c[r[a[i]]]++] = a[i];
}

// find the suffix array sa of s[0...n - 1] in {1 ... K} ^ n
// require s[n] = s[n + 1] = s[n + 2]=0, n>=2
void obtSA (int s[], int sa[], int n, int K) {
	int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2; 
	int s12[n02 + 3];
	s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0; 

	int sa12[n02 + 3];
	sa12[n02] = sa12[n02 + 1] = sa12[n02 + 2] = 0;
	
	int s0[n0];
	int sa0[n0];

	for (int i = 0, j = 0;  i < n + (n0 - n1);  i++) if (i % 3 != 0) s12[j++] = i;

	radixPass(s12, sa12, s + 2, n02, K);
	radixPass(sa12, s12, s + 1, n02, K);  
	radixPass(s12, sa12, s, n02, K);

	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	forn (i, n02) {
		if (s[sa12[i]] != c0 || s[sa12[i] + 1] != c1 || s[sa12[i] + 2] != c2) { 
			name++;
			c0 = s[sa12[i]];
			c1 = s[sa12[i] + 1];
			c2 = s[sa12[i] + 2];
		}

		if (sa12[i] % 3 == 1) {
			s12[sa12[i] / 3] = name;
		} else {
			s12[sa12[i] / 3 + n0] = name;
		}
	}

	if (name < n02) {
		obtSA(s12, sa12, n02, name);
		forn (i, n02) s12[sa12[i]] = i + 1;
	} else {
		forn (i, n02) sa12[s12[i] - 1] = i; 
	}

	for (int i = 0, j = 0; i < n02; i++) if (sa12[i] < n0) s0[j++] = 3 * sa12[i];
	radixPass(s0, sa0, s, n0, K);

	for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
		#define GetI() (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2)
		int i = GetI();
		int j = sa0[p];
		
		if (sa12[t] < n0 ? leq(s[i], s12[sa12[t] + n0], s[j], s12[j / 3]) : leq(s[i], s[i + 1], s12[sa12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0])) {
			sa[k] = i;
			t++;

			if (t == n02) for (k++; p < n0; p++, k++) sa[k] = sa0[p];
		} else { 
			sa[k] = j;
			p++; 

			if (p == n0) for (k++; t < n02; t++, k++) sa[k] = GetI(); 
		}
	} 
}

int phi[MX], plcp[MX];
void obtLCP (string &s) {
	int n = s.size();

	phi[sa[0]] = -1;
	for (int i = 1; i < n; i++) phi[sa[i]] = sa[i - 1];

	for (int i = 0, l = 0; i < n; i++) {
		if (phi[i] == -1) {
			plcp[i] = 0;
			continue;
		}

		while (s[i + l] == s[phi[i] + l]) l++;

		plcp[i] = l;
		l = max(l - 1, 0);
	}

	forn (i, n) lcp[i] = plcp[sa[i]];
}

int M[LG][MX], logTable[MX];

#define mini(x,y) ((x) < (y) ? (x) : (y))

void pre (int n, int A[]) {
	for (int i = 2; i <= n; i++)
		logTable[i] = logTable[i >> 1] + 1;
	
	forn (i, n) M[0][i] = A[i];

	for(int j = 1; (1 << j) <= n; j++)
		forn (i, n - (1 << j) + 1)
			M[j][i] = mini(M[j - 1][i], M[j - 1][i + (1 << (j - 1))]);
}

int k;
inline int query (int i, int j) {
	if (i > j) return 1e9;
	k = logTable[j - i + 1];
	return mini(M[k][i], M[k][j - (1 << k) + 1]);
}

int n, m, tam[MX + 100005], cn[MX], ind[MX + 100005];
string in[100005], s;
int x[MX + 100005], y[MX + 100005], sz, q[MX + 100005];

inline int leq (int i, int j, int len) {
	int x = f[i], y = f[j];
	if (x < y && query(x + 1, y) < len) return 1;
	if (x > y && query(y + 1, x) < len) return -1;
	return 0;
}

int sza, szb, g, to;
bool comp (int i, int j) {
	sza = tam[i], szb = tam[j];
	g = leq(x[i], x[j], mini(y[i], y[j]));

	if (g == 1) return 1;
	if (g == -1) return 0;

	if (y[i] < y[j]) g = leq(x[i] + y[i] + 1, x[j] + y[i], mini(y[j], sza - 1) - y[i]);
	if (y[i] > y[j]) g = leq(x[i] + y[j], x[j] + y[j] + 1, mini(y[i], szb - 1) - y[j]);

	if (g == 1) return 1;
	if (g == -1) return 0;

	to = y[i];
	if (to < y[j]) to = y[j];
	if (mini(sza, szb) > (to + 1))
		g = leq(x[i] + to + 1, x[j] + to + 1, mini(sza, szb) - (to + 1));

	if (g == 1) return 1;
	if (g == -1) return 0;

	if (y[i] < sza) sza--;
	if (y[j] < szb) szb--;

	if (sza == szb) return x[i] < x[j];
	return sza < szb;
}

int dp[2][MX];
vi ord[100005];
 
void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> in[i];

		forn (j, in[i].size() + 1) {
			x[sz] = s.size();
			y[sz] = j;
			tam[sz] = in[i].size();
			ind[sz] = i;
			sz++;
		}

		s += in[i];
	}

	m = s.size();

	forn (i, m) S[i] = s[i] - 'a' + 1;

	obtSA(S, sa, m, 26);
	obtLCP(s);
	pre(m, lcp);
	forn (i, m) f[sa[i]] = i;

	sz = 0;

	forn (i, n) {
		ord[i].resize(in[i].size() + 1);
 
		int l = 0, r = (int)in[i].size(), j = 0;
 
		while (j < in[i].size()) {
			int to = j;
 
			while (to < in[i].size() && in[i][j] == in[i][to]) to++;
 
			while (j < to) {
				if (to == in[i].size() || in[i][j] > in[i][to]) ord[i][l++] = sz + j++;
				else ord[i][r--] = sz + j++;
			}
		}
 
		ord[i][l] = sz + in[i].size();
		sz += in[i].size() + 1;
	}
 
	int x = 0, y = 1;
	fill(dp[x], dp[x] + ord[0].size(), 1);
 
	forn (i, n - 1) {
		int j = 0;
 
		forn (k, ord[i + 1].size()) {
			if (k) dp[y][k] = dp[y][k - 1];
			else dp[y][k] = 0;
 
			while (j < ord[i].size() && comp(ord[i][j], ord[i + 1][k]))
				sum(dp[y][k], dp[x][j++]);
		}
 
		swap(x, y);
	}
 
	int res = 0;
	forn (i, ord[n - 1].size())
		sum(res, dp[x][i]);
	cout << res << endl;
	
	return 0;
}