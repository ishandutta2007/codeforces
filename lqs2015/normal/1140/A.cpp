#include <bits/stdc++.h>
namespace IOStream {
	const int MAXR = 10000000;
	char _READ_[MAXR], _PRINT_[MAXR];
	int _READ_POS_, _PRINT_POS_, _READ_LEN_;
	inline char readc() {
	#ifndef ONLINE_JUDGE
		return getchar();
	#endif
		if (!_READ_POS_) _READ_LEN_ = fread(_READ_, 1, MAXR, stdin);
		char c = _READ_[_READ_POS_++];
		if (_READ_POS_ == MAXR) _READ_POS_ = 0;
		if (_READ_POS_ > _READ_LEN_) return 0;
		return c;
	}
	template<typename T> inline void read(T &x) {
		x = 0; register int flag = 1, c;
		while (((c = readc()) < '0' || c > '9') && c != '-');
		if (c == '-') flag = -1; else x = c - '0';
		while ((c = readc()) >= '0' && c <= '9') x = x * 10 - '0' + c;
		x *= flag;
	}
	template<typename T1, typename ...T2> inline void read(T1 &a, T2&... x) {
		read(a), read(x...);
	}
	inline int reads(char *s) {
		register int len = 0, c;
		while (isspace(c = readc()) || !c);
		s[len++] = c;
		while (!isspace(c = readc()) && c) s[len++] = c;
		s[len] = 0;
		return len;
	}
	inline void ioflush() { fwrite(_PRINT_, 1, _PRINT_POS_, stdout), _PRINT_POS_ = 0; fflush(stdout); }
	inline void printc(char c) {
		if (!c) return;
		_PRINT_[_PRINT_POS_++] = c;
		if (_PRINT_POS_ == MAXR) ioflush();
	}
	inline void prints(const char *s, char c) {
		for (int i = 0; s[i]; i++) printc(s[i]);
		printc(c);
	}
	template<typename T> inline void print(T x, char c = '\n') {
		if (x < 0) printc('-'), x = -x;
		if (x) {
			static char sta[20];
			register int tp = 0;
			for (; x; x /= 10) sta[tp++] = x % 10 + '0';
			while (tp > 0) printc(sta[--tp]);
		} else printc('0');
		printc(c);
	}
	template<typename T1, typename ...T2> inline void print(T1 x, T2... y) {
		print(x, ' '), print(y...);
	}
}
using namespace IOStream;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, t, res, mx;
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(t); mx = max(mx, t);
		if (mx <= i) ++res;
	}
	printf("%d\n", res);
	return 0;
}