#include <bits/stdc++.h> 
#define int long long
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

const int N = 510;
int n, ans, tag;
int a[N], b[N], c[N];

std::vector < std::pair < int, int > > e;

bool cmp(int x, int y) {
	return a[x] == a[y] ? x < y : a[x] > a[y];
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] > n - 1) a[i] = n - 1;
		++b[a[i]], c[i] = i;
	}
	ans = n - b[1] + std::min(b[1], (int)2) - 1;
	std::sort(c + 1, c + n + 1, cmp);
	// for (int i = 1; i <= n; i++) print(c[i], " \n"[i == n]);
	tag = n + 1;
	for (int i = 1; i <= n; i++)
		if (a[c[i]] == 1) {
			tag = i;
			break;
		} else if (i != 1) {
			e.push_back(std::make_pair(c[i - 1], c[i]));
			--a[c[i - 1]], --a[c[i]];
		}
	if (tag > 2 && tag != n + 1) {
		std::swap(c[tag - 1], c[2]);
		if (tag == n) {
			e.push_back(std::make_pair(c[1], c[tag]));
			--a[c[1]], --a[c[tag]], ++tag;
		} else {
			e.push_back(std::make_pair(c[1], c[tag]));
			--a[c[1]], --a[c[tag]], ++tag;
			e.push_back(std::make_pair(c[2], c[tag]));
			--a[c[2]], --a[c[tag]], ++tag;
		}
	}
	for (int i = tag, j = 1; i <= n; i++) {
		while (!a[c[j]] && j < tag) j++;
		if (j >= tag) { puts("NO"); return; }
		e.push_back(std::make_pair(c[j], c[i]));
		--a[c[j]], --a[c[i]];
	}
	if ((int)e.size() < n - 1) {
		puts("NO");
		return;
	}
	printf("YES "), print(ans, '\n'), print(n - 1, '\n');
	for (auto u : e) {
		print(u.first, ' ');
		print(u.second, '\n');
	}
}

} signed main() { return ringo::main(), 0; }