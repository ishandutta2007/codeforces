#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

ll l[N]; char c[N];
ll ans, G2, W, L, naili, haveW = 0;
int n;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(l[i]);
	scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) {
		if(c[i] == 'G') {
			naili += l[i];
			ans += l[i] * 5;
			G2 += l[i] * 2;
		}
		if(c[i] == 'W') {
			naili += l[i];
			ans += l[i] * 3;
			W += l[i];
			haveW = 1;
		}
		if(c[i] == 'L') {
			if(naili >= l[i]) {
				naili -= l[i];
				ans += l[i];
			} else {
				ans += l[i];
				if(haveW) ans += (l[i] - naili) * 3;
				else ans += (l[i] - naili) * 5;
				naili = 0;
			}
		}
		G2 = min(G2, naili);
	}
	if(naili > 0) {
		ans -= G2 * 2; naili -= G2;
		ans -= naili;
	}
	cout << ans << endl;
	return 0;
}