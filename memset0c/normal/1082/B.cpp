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

const int N = 1e5 + 10;
int n, ans, len, cnt[2];
char a[N];
std::vector < std::pair < int, int > > b;

void main() {
	read(n), scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
		if (a[i] == 'G') a[i] = 1;
		else a[i] = 0;
	for (int i = 1; i <= n; i++) {
		cnt[(int)a[i]]++, ++len;
		if (a[i] != a[i + 1] || i == n) {
			b.push_back(std::make_pair(a[i], len));
			len = 0;
		}
	}
	// for (int i = 0; i < (int)b.size(); i++)
	// 	printf(">> %d %d\n", b[i].first, b[i].second);
	for (int i = 0; i < (int)b.size(); i++)
		if (b[i].first) {
			int t = b[i].second;
			ans = std::max(ans, t);
			if (cnt[1] - t) ans = std::max(ans, t + 1);
			if (i - 2 >= 0 && cnt[1] - t) {
				if (b[i - 1].second == 1) {
					if (cnt[1] - t - b[i - 2].second)
						ans = std::max(ans, t + b[i - 2].second + 1);
					else
						ans = std::max(ans, t + b[i - 2].second);
				}
			}
			if (i + 2 < (int)b.size() && cnt[1] - t) {
				if (b[i + 1].second == 1) {
					if (cnt[1] - t - b[i + 2].second)
						ans = std::max(ans, t + b[i + 2].second + 1);
					else 
						ans = std::max(ans, t + b[i + 2].second);
				}
			}
		}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; } //dfasfsdff