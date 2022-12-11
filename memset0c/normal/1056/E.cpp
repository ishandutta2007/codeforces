#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 2e6 + 10, M = 2e6 + 10;
const int p1 = 998244353, p2 = 1e9 + 7;
int n, m, ans, cnt[2];
char a[N], b[N];

struct pair {
	int a, b;
	inline pair operator + (const pair &other) {
		return (pair){(a + other.a) % p1, (b + other.b) % p2};
	}
	inline pair operator - (const pair &other) {
		return (pair){(a - other.a + p1) % p1, (b - other.b + p2) % p2};
	}
	inline pair operator * (const pair &other) {
		return (pair){
			(int)((ll)a * other.a % p1),
			(int)((ll)b * other.b % p2)
		};
	}
	inline bool operator == (const pair &other) {
		return a == other.a && b == other.b;
	}
} s[M], pow[M];

pair gethash(int l, int r) {
	// printf("get hash %d %d\n", l, r);
	return s[r] - s[l - 1] * pow[r - l + 1];
}

bool check(int len0, int len1) {
	int l[2] = {len0, len1}, flag[2] = {false, false};
	pair base[2] = {0, 0};
	for (int i = 1, u, k = 1; i <= n; i++) {
		u = a[i] - '0';
		if (!flag[u]) base[u] = gethash(k, k + l[u] - 1), flag[u] = 1;
		else if (!(gethash(k, k + l[u] - 1) == base[u])) return false;
		k += l[u];
	}
	// printf("%d %d : %d %d\n", base[0].a, base[0].b, base[1].a, base[1].b);
	if (base[0] == base[1]) return false;
	return true;
}

void main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; i++)
		++cnt[a[i] - '0'];
	pow[0].a = pow[0].b = 1;
	for (int i = 1; i <= m; i++) {
		pow[i].a = (ll)pow[i - 1].a * 131 % p1;
		pow[i].b = (ll)pow[i - 1].b * 131 % p2;
		s[i].a = ((ll)s[i - 1].a * 131 + b[i] - 'a' + 1) % p1;
		s[i].b = ((ll)s[i - 1].b * 131 + b[i] - 'a' + 1) % p2;
	}
	// for (int i = 1; i <= m; i++)
	// 	printf("(%d %d)%c", s[i].a, s[i].b, " \n"[i == m]);
	for (int i = 1, j; i <= m; i++) {
		ll tmp = m - (ll)i * cnt[0];
		if (tmp <= 0 || tmp % cnt[1]) continue;
		j = tmp / cnt[1];
		if (check(i, j)) ans++;
	}
	print(ans, '\n');
	// for (int i = 1; i <= m; i++) {
	// 	for (int j = i; j <= m; j++) {
	// 		pair now = gethash(i, j);
	// 		printf("(%d %d)%c", now.a, now.b, " \n"[j == m]);
	// 	}
	// }
}

} signed main() { return ringo::main(), 0; }