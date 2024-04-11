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

const int N = 200005;

int f[N][3], fr[N][3];
int n; string s;

inline int calc(char c) {
	if(c == 'R') return 0;
	if(c == 'B') return 1;
	return 2;
}

inline char solve(int x) {
	if(x == 0) return 'R';
	if(x == 1) return 'B';
	return 'G';
}

int main() {
	memset(f, 0x7f, sizeof(f));
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	f[0][0] = f[0][1] = f[0][2] = 0;
	for(register int i = 0; i < n; i++) {
		for(register int j = 0; j <= 2; j++) {
			for(register int k = 0; k <= 2; k++) {
				if(j == k) continue;
				int go = f[i][j] + (solve(k) != s[i]);
				if(go < f[i + 1][k]) {
					f[i + 1][k] = go;
					fr[i + 1][k] = j;
				}
			}
		}
	}
	int minn = 0;
	if(f[n][1] < f[n][minn]) minn = 1;
	if(f[n][2] < f[n][minn]) minn = 2;
	cout << f[n][minn] << endl;
	vector <char> ans; int now = n;
	while(now) {
		ans.push_back(solve(minn));
		minn = fr[now][minn]; --now;
	}
	reverse(ans.begin(), ans.end());
	for(register int i = 0; i < n; i++) cout << ans[i];
	cout << endl;
	return 0;
}