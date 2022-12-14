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

const int MAXN = 300005, MAXT = 1100000, MAXM = 600005;
vector<P> vec[MAXT];
map<P, int> mp;
int par[MAXM], fst[MAXM], sec[MAXM], tp, m;
P sta[MAXN]; ll res;
void add(int a, int b, P x, int l = 1, int r = m, int k = 1) {
	if (a > r || b < l) return;
	if (a <= l && b >= r) { vec[k].push_back(x); return; }
	int mid = (l + r) >> 1;
	add(a, b, x, l, mid, k << 1);
	add(a, b, x, mid + 1, r, k << 1 | 1);
}
int find(int x) { return x == par[x] ? x : find(par[x]); }
void calc(int l, int r, int k = 1) {
	int bef = tp;
	for (P p : vec[k]) {
		int a = find(p.first), b = find(p.second);
		if (a == b) continue;
		if (fst[a] + sec[a] > fst[b] + sec[b]) swap(a, b);
		sta[++tp] = P(a, b), par[a] = b;
		res -= (ll)fst[a] * sec[a] + (ll)fst[b] * sec[b];
		fst[b] += fst[a], sec[b] += sec[a];
		res += (ll)fst[b] * sec[b];
	}
	if (l < r) {
		int mid = (l + r) >> 1;
		calc(l, mid, k << 1);
		calc(mid + 1, r, k << 1 | 1);
	} else print(res, ' ');
	while (tp > bef) {
		int a = sta[tp].first, b = sta[tp].second; --tp;
		par[a] = a, res -= (ll)fst[b] * sec[b];
		fst[b] -= fst[a], sec[b] -= sec[a];
		res += (ll)fst[a] * sec[a] + (ll)fst[b] * sec[b];
	}
}
int main() {
	read(m);
	for (int i = 1; i <= 300000; i++) par[i] = i, fst[i] = 1;
	for (int i = 300001; i <= 600000; i++) par[i] = i, sec[i] = 1;
	for (int i = 1; i <= m; i++) {
		int a, b; read(a, b); b += 300000;
		P x = P(a, b);
		if (mp[x]) add(mp[x], i - 1, x), mp[x] = 0;
		else mp[x] = i;
	}
	for (auto t : mp) if (t.second) add(t.second, m, t.first);
	calc(1, m);
	ioflush();
	return 0;
}