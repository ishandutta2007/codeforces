#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
template <class T> inline void read(T &a) {
	static char ch = 0; bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {
		f |= ch == '-', ch = getchar();
	}
	while (ch >= '0' && ch <= '9') a = a * 10 + ch - '0', ch = getchar();
	if (f) a = -a;
}
#define MOD
//#define MULTI_CASE
#define N

LL n, m, a, b;

void work() {
	cin >> n >> m >> a >> b;	
	n %= m;
	cout << min(b * n, a * (m - n));
}


int main() {
#ifdef MULTI_CASE
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		printf("Case %d: ");
		work();
	}
#else
	work();
#endif
	return 0;
}