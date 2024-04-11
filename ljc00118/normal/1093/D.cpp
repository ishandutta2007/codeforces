#include <bits/stdc++.h> // 23333333
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5, mod = 998244353;

inline int mul(int x, int y) { return (ll)x * y % mod; }

inline int add(int x, int y) {
	x += y;
	if(x >= mod) x -= mod;
	return x;
}

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

queue <int> q;
vector <int> adj[N];
int f[N];
int T, n, m, cnt1, cnt2, ans;

int main() {
	read(T); while(T--) {
		read(n); read(m); ans = 1;
		for(register int i = 1; i <= n; i++) f[i] = -1, adj[i].clear();
		for(register int i = 1; i <= m; i++) {
			int a, b; read(a); read(b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(register int i = 1; i <= n; i++) {
			if(~f[i]) continue;
			cnt1 = 1; cnt2 = 0; f[i] = 1; q.push(i);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(register int j = 0; j < (int)adj[u].size(); j++) {
					int v = adj[u][j];
					if(f[v] == -1) {
						f[v] = 3 - f[u];
						if(f[v] == 1) cnt1++; else cnt2++;
						q.push(v);
					} else if(f[v] != 3 - f[u]) {
						ans = 0; break;
					}
				}
			}
			if(!ans) break;
			ans = mul(ans, add(fpow(2, cnt1), fpow(2, cnt2)));
		}
		print(ans, '\n');
	}
	return 0;
}