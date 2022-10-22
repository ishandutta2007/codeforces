#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define pb push_back
#define i64 long long
#define p(i, j) ((i) * (m + 1) + (j))
#define g(i, j) (id[find(p(i, j))])
using namespace std;
const int N = 400 + 10;
int n, m, mod;
int fa[N * N], id[N * N];
char s[N][N];

void Mod(int &x) {x += (x >> 31) & mod; }

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % mod) {
		if(b & 1) {
			c = 1ll * c * a % mod;
		}
	}
	return c;
}

struct Matrix {
	int a[N][N];
	
	void clear() {memset(a, 0, sizeof(a)); }
	
	int det(int n) {
		static int b[N][N];
		memcpy(b, a, sizeof(a));
		int prod = 1;
		for(int i = 0; i < n; i++) {
			int p = -1;
			for(int j = i; j < n; j++) {
				if(b[j][i]) {
					p = j;
					break;
				}
			}
			if(p == -1) return 0;
			if(p != i) prod = (mod - prod) % mod, swap(b[p], b[i]);
			prod = 1ll * prod * b[i][i] % mod;
			int inv = power(b[i][i], mod - 2);
			for(int j = i + 1; j < n; j++) {
				int coef = 1ll * b[j][i] * inv % mod;
				for(int k = i; k < n; k++) {
					Mod(b[j][k] -= 1ll * coef * b[i][k] % mod);
				}
			}
		}
		return prod;
	}
}A;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }

int unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	fa[x] = y;
	return 1;
} 

void Adde(int u, int v) {
	A.a[u][u]++, A.a[v][v]++;
	A.a[u][v]--, A.a[v][u]--;
	return;
}

int solve(int parity) {
	A.clear();
	int tot = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if((i + j) % 2 != parity) continue;
			if(find(p(i, j)) == p(i, j)) {
				id[p(i, j)] = tot++;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '*') {
				if((i + j) % 2 == parity) {
					Adde(g(i - 1, j - 1), g(i, j));
				} else {
					Adde(g(i - 1, j), g(i, j - 1));
				}
			}
		}
	}
	for(int i = 0; i < tot; i++) {
		for(int j = 0; j < tot; j++) {
			((A.a[i][j] %= mod) += mod) %= mod;
		}
	}
	return A.det(tot - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> mod;
	for(int i = 0; i < (n + 1) * (m + 1); i++) fa[i] = i;
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '\\') {
				flag |= !unite(p(i - 1, j - 1), p(i, j));
			} 
			if(s[i][j] == '/') {
				flag |= !unite(p(i - 1, j), p(i, j - 1));
			}
		}
	}
	if(flag) cout << 0 << endl, exit(0);
	int ans = (solve(0) + solve(1)) % mod;
	cout << ans << endl;
	return 0;
}