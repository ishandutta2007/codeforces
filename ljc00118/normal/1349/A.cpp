#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

int cnt[N], c[20], isp[N], a[N];
int n;
ll ans = 1;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		++cnt[a[i]];
	}
	for (int i = 2; i <= 200000; i++) {
		if (isp[i]) continue;
		memset(c, 0, sizeof(c));
		c[0] = n;
		for (int j = i; j <= 200000; j += i) {
			isp[j] = 1;
			int now = j, _ = 0;
			while (now % i == 0) now /= i, ++_;
			c[_] += cnt[j]; c[0] -= cnt[j];
		}
		int sum = 0;
		for (int j = 0; j <= 20; j++) {
			sum += c[j];
			if (sum >= 2) {
				for (int k = 1; k <= j; k++) ans *= i;
				break;
			}
		}
	}
	print(ans, '\n');
    return 0;
}