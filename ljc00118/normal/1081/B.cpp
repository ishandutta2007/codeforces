#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
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

const int N = 1e5 + 5;

vector <int> t[N];
int a[N], ans[N], pre[N];
int n, tot;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]), a[i] = n - a[i], t[a[i]].push_back(i);
	for(register int i = 1; i <= n; i++) {
		if(t[i].size() % i != 0) {
			printf("Impossible\n");
			return 0;
		}
		int cnt = i;
		for(register int j = 0; j < t[i].size(); j++) {
			cnt++; if(cnt > i) cnt = 1, ++tot; ans[t[i][j]] = tot;
		}
	}
	printf("Possible\n");
	for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
	return 0;
}

// Rotate Flower Round.