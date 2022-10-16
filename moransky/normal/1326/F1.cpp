// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 18;

int n, d[N], t, ans, pc[1 << N];

int g[N][N];

LL f[1 << N][N], a[N + 1][1 << N];

void inline OR(LL *w, int n) {
	for (int k = 1; k < (1 << n); k <<= 1) {
		for (int i = 0; i < (1 << n); i += (k << 1)) {
			for (int j = 0; j < k; j++) {
				w[i + j + k] += w[i + j];
			}
		}
	}
}

void inline AND(LL *w, int n) {
	for (int k = 1; k < (1 << n); k <<= 1) {
		for (int i = 0; i < (1 << n); i += (k << 1)) {
			for (int j = 0; j < k; j++) {
				w[i + j] += w[i + j + k];
			}
		}
	}
}


void inline prework() {
	for (int i = 0; i < n; i++) f[1 << i][i] = 1;
	for (int s = 1; s < (1 << n); s++) {
		int c = __builtin_popcount(s);
		pc[s] = c;
		for (int i = 0; i < n; i++) {
			if ((s >> i & 1) && f[s][i]) {
				a[c][s] += f[s][i];
				for (int j = 0; j < n; j++) {
					if ((s >> j & 1) || !g[i][j]) continue;
					f[s | (1 << j)][j] += f[s][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		OR(a[i], n);
		//for (int j = 0; j < (1 << n); j++) cout << a[i][j]<< " ";
		//cout << endl;
	}
}

LL b[N + 1][1 << N];

map<vector<int>, LL> M;

void ins() {
	LL r = 0;
	for (int i = 0; i < (1 << n); i++) {
		if ((n - pc[i]) & 1) r -= b[t][i];
		else r += b[t][i];
	//	cout << i << " ... " << b[t][i] << endl;
	}
	vector<int> A;
	for (int i = 1; i <= t; i++) A.pb(d[i]);//, cout << d[i] << " ";
	M[A] = r;
}

void dfs(int u) {
	if (u == n){
		++ans;
		ins();
		return;
	}
	for (int i = d[t]; i <= n - u; i++) {
		d[++t] = i;
		for (int j = 0; j < (1 << n); j++)
			b[t][j] = b[t - 1][j] * a[i][j];
		dfs(u + i);
		--t;
	}
}

LL h[1 << N];

int main() {
    read(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		scanf("%1d", &g[i][j]);
    	}
    }	
    for (int i = 0; i < (1 << n); i++) b[0][i] = 1; 
    prework();
    d[0] = 1;
    dfs(0);
    int m = n - 1;
    for (int i = 0; i < (1 << m); i++) {
    	vector<int> A;
    	int s = 0;
    	for (int j = 0; j < n; j++) {
    		int k = j;
    		while (k + 1 < n && (i >> k & 1)) k++;
    		A.pb(k - j + 1);
    		j = k;
    	}
    	sort(A.begin(), A.end());
    	h[i] = M[A];
    }
    for (int i = 0; i < (1 << m); i++)
    	if (pc[i] & 1) h[i] = -h[i];
   	AND(h, m);
    for (int i = 0; i < (1 << m); i++) {
    	LL ans = h[i];
    	if (pc[i] & 1) ans = -ans;
    	printf("%lld ", ans);
    }
    return 0;
}