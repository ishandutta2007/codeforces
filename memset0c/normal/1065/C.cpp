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

const int N = 200005, inf = 1e9;
int n, m, min = inf, max = -inf, ans;
int a[N], cnt[N];

void main() {
	std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
		read(a[i]);
		cnt[a[i]]++;
		min = std::min(min, a[i]); 
		max = std::max(max, a[i]);
	}
    if (min == max) {
		printf("0\n");
		return;
	}
    for (int i = max - 1; i; i--) cnt[i] += cnt[i + 1];
    for (int i = 1; i <= max; i++) cnt[i] += cnt[i - 1];
    for (int i = max, j = max; i != min; ) {
        while (j > min && cnt[i] - cnt[j - 1] <= m) j--;
		j++, ans++; i = j - 1;
    }
	std::cout << ans << std::endl;
}

} signed main() { return ringo::main(), 0; }