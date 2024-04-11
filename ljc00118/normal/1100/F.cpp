#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 500005;

vector <pii> q[N];
int ans[N], a[N];
int b[20], pos[20];
int n, m;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	read(m);
	for(register int i = 1; i <= m; i++) {
		int l, r; read(l); read(r);
		q[r].emplace_back(l, i);
	}
	for(register int i = 1; i <= n; i++) {
		int p = i;
		for(register int j = 19; j >= 0; j--) {
			if((a[i] >> j) & 1) {
				if(b[j] == 0) {
					b[j] = a[i];
					pos[j] = p;
					break;
				}
				if(pos[j] < p) swap(pos[j], p), swap(b[j], a[i]);
				a[i] ^= b[j];
			}
		}
		for(register unsigned j = 0; j < q[i].size(); j++) {
			int res = 0;
			for(register int t = 19; t >= 0; t--) if(pos[t] >= q[i][j].first && (res ^ b[t]) > res) res ^= b[t];
			ans[q[i][j].second] = res;
		}
	}
	for(register int i = 1; i <= m; i++) print(ans[i], '\n');
	return 0;
} // I am faker

// Rotate Flower Round.