#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
template <class T> inline void read(T &a) {
	static char ch = 0; bool f = 0; a = 0;
	while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9') a = a * 10 + ch - '0', ch = getchar();
	if (f) a = -a;
}
#define MOD
#define N
//#define MULTI_CASE


void work() {
	string s;
	cin >> s;
	for (int i = 0; i + 2 < s.size(); i++) {
		if (s[i] + s[i + 1] + s[i + 2] == 3 * 'B' && s[i] != s[i + 1]) {
			puts("Yes");
			return;
		}
	}
	puts("No");

}


int main() {
#ifdef MULTI_CASE
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