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

ll p1, p2, k;
int T;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
// 	freopen("color.in", "r", stdin);
// 	freopen("color.out", "w", stdout);
	read(T);
	while (T--) {
		read(p1); read(p2); read(k);
		if (k == 1) {
			printf("REBEL\n");
			continue;
		}
		ll d = gcd(p1, p2);
		p1 /= d; p2 /= d;
		if (p1 > p2) swap(p1, p2);
		if (p1 == p2) {
			printf("OBEY\n");
			continue;
		}
		if ((p2 - 2) / p1 + 1 < k) printf("OBEY\n");
		else printf("REBEL\n");
	}
    return 0;
}