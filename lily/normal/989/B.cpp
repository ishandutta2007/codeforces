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
	int n, p;
	cin >> n >> p;	
	string s;
	cin >> s;
	bool flag = 0;
	for (int i = 0; i < n - p; i++) {
		if (s[i] != s[i + p] || s[i] == '.') {
			if (s[i] == '.' && s[i + p] == '.') s[i] = '0', s[i + p] = '1';
			else if (s[i] == '.') s[i] = s[i + p] ^ 1;
			else if (s[i + p] == '.') s[i + p] = s[i] ^ 1;
			flag = 1;
			break;
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) if (s[i] == '.') s[i] = '0';
		cout << s;
	}
	else cout << "No";
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