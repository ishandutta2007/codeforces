#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long u64;
typedef double db;
const int N = 1 << 17, P = 998244353;
int n, m;
int SG[N], vis[N];
int f[N];
vector<int> g[N];

void Mod(int &x) { x += (x >> 31) & P; } 

int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = (u64)a * a % P) if(b & 1) res = (u64)res * a % P;
	return res;
}

void DFS(int u) {
	if(SG[u] >= 0) return;
	for(int &v : g[u]) DFS(v);
	for(int &v : g[u]) vis[SG[v]]++;
	SG[u] = 0;
	for(; vis[SG[u]]; SG[u]++);
	for(int &v : g[u]) vis[SG[v]]--;
	return;
}

void FWT(int *a, int L, int t) {
	for(int i = 2; i <= L; i <<= 1) {
		for(int j = 0; j < L; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				int x;
				Mod(x = a[j + k] - a[j + k + (i >> 1)]);
				Mod(a[j + k] += a[j + k + (i >> 1)] - P);
				a[j + k + (i >> 1)] = x;
			}
		}
	}
	if(t < 0) {
		for(int i = 0, iL = qpow(L, P - 2); i < L; i++) a[i] = (u64)a[i] * iL % P;
	}
	return;
}

int main() {
	memset(SG, -1, sizeof(SG));
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	int L = 1; 
	for(; L < n; L <<= 1);
	for(int u = 1; u <= n; u++) DFS(u);
	for(int u = 1; u <= n; u++) f[SG[u]]++;
	FWT(f, L, 1);
	for(int i = 0; i < L; i++) {
		f[i] = (u64)f[i] * qpow(n + 1, P - 2) % P;
		Mod(f[i] = 1 - f[i]);
		f[i] = qpow(f[i], P - 2);
		f[i] = (u64)f[i] * qpow(n + 1, P - 2) % P;
	}
	FWT(f, L, -1);
	Mod(f[0] = 1 - f[0]);
	printf("%d\n", f[0]);
	return 0;
}