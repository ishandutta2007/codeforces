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

int n, ans = N; string s, foo, now;

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
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s; now = s;
	for(register int i = 0; i <= 2; i++) {
		for(register int j = 0; j <= 2; j++) {
			for(register int k = 0; k <= 2; k++) {
				if(i != j && i != k && j != k) {
					int sum = 0;
					for(register int t = 1; t <= n; t++) {
						if(t % 3 == 0) sum += (calc(s[t - 1]) != i), now[t - 1] = solve(i);
						if(t % 3 == 1) sum += (calc(s[t - 1]) != j), now[t - 1] = solve(j);
						if(t % 3 == 2) sum += (calc(s[t - 1]) != k), now[t - 1] = solve(k);
					}
					if(sum < ans) ans = sum, foo = now;
				}
			}
		}
	}
	cout << ans << endl;
	cout << foo << endl;
	return 0;
}