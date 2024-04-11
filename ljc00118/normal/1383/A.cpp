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
 
const int N = 1e5 + 5;

char a[N], b[N];
int f[25][25];
int T, n, ans;
 
int main() {
	read(T);
	while (T--) {
		memset(f, 0, sizeof(f));
		read(n); scanf("%s%s", a + 1, b + 1);
		bool ok = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] > b[i]) {
				ok = 0;
				break;
			}
			f[a[i] - 'a' + 1][b[i] - 'a' + 1] = 1;
		}
		if (!ok) {
			print(-1, '\n');
			continue;
		}
		ans = 0;
		for (int i = 1; i <= 20; i++) {
			for (int j = i + 1; j <= 20; j++) {
				if (f[i][j]) {
					++ans;
					for (int k = j; k <= 20; k++) f[j][k] |= f[i][k];
					break;
				}
			}
		}
		print(ans, '\n');
	}
	return 0;
}