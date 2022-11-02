#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE - 1;
	inline void read_char(char &c) {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		c = *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c;
		read_char(c);
		while (!isdigit(c)) {
			if (c == '-') {
				f = -1;
			}
			read_char(c);
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			read_char(c);
		}
		x *= f;
	}
	inline void flush() {
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void print_char(char c) {
		*os++ = c;
		if (os == ot) {
			flush();
		}
	}
	template <class T>
	inline void print_int(T x) {
		static char q[40];
		if (!x) {
			print_char('0');
		} else {
			if (x < 0) {
				print_char('-');
				x = -x;
			}
			int top = 0;
			while (x) {
				q[top++] = x % 10 + '0';
				x /= 10;
			}
			while (top--) {
				print_char(q[top]);
			}
		}
	}
	struct flusher_t {
		inline ~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::print_char;
using io::print_int;
//Fast IO end
const int N = 1005;
const int mod = 998244353;
int wei[16];
struct Bitset {
	unsigned long long a[16];
	inline Bitset() { memset(a, 0, sizeof(a)); }
	inline void reset() { memset(a, 0, sizeof(a)); }
	inline void set(int i) { a[i >> 6] |= (1ull << (i & 63)); }
	inline Bitset& operator ^= (const Bitset &oth) {
		for (int i = 0; i < 16; i++) a[i] ^= oth.a[i];
		return *this;
	}
	inline Bitset operator ^ (const Bitset &oth) const {
		Bitset ret;
		for (int i = 0; i < 16; i++) ret.a[i] = a[i] ^ oth.a[i];
		return ret;
	}
	inline int getval() const {
		unsigned long long ret = 0;
		for (int i = 0; i < 16; i++) {
			ret = (ret + a[i] % mod * wei[i]) % mod;
		}
		return ret;
	}
	inline bool operator == (const Bitset &oth) const {
		for (int i = 0; i < 16; i++) if (a[i] != oth.a[i]) return false;
		return true;
	}
};
int n, s, s1, s2, d;
Bitset c[35], l1[1 << 18], cur, tmp;
inline void getmin(int &x, int y) {
	if (x > y) x = y;
}
namespace HT {
int head[1145141], to[(1 << 18) + 5], nxt[(1 << 18) + 5], tot;
Bitset ts[(1 << 18) + 5];
inline void Add(const Bitset &bs, int toto) {
	int val = bs.getval() % 1145141;
	for (int i = head[val]; i; i = nxt[i]) {
		if (ts[i] == bs) {
			to[i] = min(to[i], toto);
			return;
		}
	}
	++tot;
	to[tot] = toto;
	nxt[tot] = head[val];
	ts[tot] = bs;
	head[val] = tot;
}
inline int Query(const Bitset &bs) {
	int val = bs.getval() % 1145141;
	for (int i = head[val]; i; i = nxt[i]) {
		if (ts[i] == bs) {
			return to[i];
		}
	}
	return 114;
}
}
int main() {
	mt19937 rng(1145141);
	for (int i = 0; i < 16; i++) wei[i] = uniform_int_distribution<int>(1, mod - 1)(rng);
	read_int(n);
	read_int(s);
	read_int(d);
	for (int i = 0; i < s; i++) {
		int sz;
		read_int(sz);
		while (sz--) {
			int x;
			read_int(x);
			c[i].set(x);
		}
	}
	s1 = min(s / 2, 12);
	s2 = s - s1;
	for (int mask = 0; mask < (1 << s1); mask++) {
		cur.reset();
		for (int i = 0; i < s1; i++) if (mask >> i & 1) {
			cur ^= c[i];
		}
		l1[mask] = cur;
	}
	for (int mask = 0; mask < (1 << s2); mask++) {
		cur.reset();
		for (int i = s1; i < s; i++) if (mask >> (i - s1) & 1) {
			cur ^= c[i];
		}
		HT::Add(cur, __builtin_popcount(mask));
	}
	while (d--) {
		cur.reset();
		int sz;
		read_int(sz);
		while (sz--) {
			int x;
			read_int(x);
			cur.set(x);
		}
		int ans = 114;
		for (int mask = 0; mask < (1 << s1); mask++) {
			tmp = cur ^ l1[mask];
			ans = min(ans, __builtin_popcount(mask) + HT::Query(tmp));
		}
		if (ans == 114) ans = -1;
		print_int(ans);
		print_char('\n');
	}
	return 0;
}