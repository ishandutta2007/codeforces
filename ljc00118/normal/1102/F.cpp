#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

const int INF = 0x7fffffff;

vector <int> t[20];
map <int, int> f[17][17][17];
int a[20][10005], f1[20][20], f2[20][20];
int n, m, ans;

inline int lowbit(int x) { return x & -x; }

inline int calc(int x) {
	int res = 0;
	while(x) {
		++res;
		x ^= lowbit(x);
	}
	return res;
}

int main() {
//	freopen("input.txt", "r", stdin); 
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) read(a[i][j]);
	}
	if(n == 1) {
		ans = INF;
		for(register int i = 1; i < m; i++) ans = min(ans, abs(a[1][i] - a[1][i + 1]));
		cout << ans << endl; return 0;
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			if(i == j) continue;
			int minn = INF;
			for(register int k = 1; k <= m; k++) minn = min(minn, abs(a[i][k] - a[j][k]));
			f1[i][j] = minn;
		}
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			if(i == j) continue;
			int minn = INF;
			for(register int k = 1; k < m; k++) minn = min(minn, abs(a[j][k] - a[i][k + 1]));
			f2[i][j] = minn; 
		}
	}
	for(register int i = 0; i < (1 << n); i++) t[calc(i)].push_back(i);
	for(register int i = 1; i <= n; i++) f[1][i][i][1 << (i - 1)] = INF;
	for(register int i = 1; i <= n - 1; i++) {
		for(register int j = 0; j < t[i].size(); j++) {
			int zt = t[i][j];
			for(register int fir = 1; fir <= n; fir++) {
				if((zt & (1 << (fir - 1))) == 0) continue;
				for(register int sec = 1; sec <= n; sec++) {
					if((zt & (1 << (sec - 1))) == 0) continue;
					if(!f[i][fir][sec].count(zt)) continue;
					for(register int k = 1; k <= n; k++) {
						if(zt & (1 << (k - 1))) continue;
//						fprintf(stderr, "f : %d %d %d %d %d\n", i + 1, fir, k, (zt ^ (1 << (k - 1))), max(f[i + 1][fir][k][zt ^ (1 << (k - 1))], min(f[i][fir][sec][zt], f1[sec][k])));
						f[i + 1][fir][k][zt ^ (1 << (k - 1))] = max(f[i + 1][fir][k][zt ^ (1 << (k - 1))], min(f[i][fir][sec][zt], f1[sec][k]));
					}
				}
			}
		}
	}
	for(register int fir = 1; fir <= n; fir++) {
		for(register int sec = 1; sec <= n; sec++) {
			if(fir == sec) continue;
			if(!f[n][fir][sec].count((1 << n) - 1)) continue;
			ans = max(ans, min(f[n][fir][sec][(1 << n) - 1], f2[fir][sec]));
		}
	}
	cout << ans << endl;
	return 0;
} // I am faker