#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

const int N = 5005, md = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int fpow(int x, int y) {
	if(y < 0) return 0;
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int s[N][N];
int n, k, ans;

int main() {
    read(n); read(k); s[0][0] = 1;
    for(register int i = 1; i <= k; i++) {
    	for(register int j = 1; j <= i; j++) {
    		s[i][j] = add(s[i - 1][j - 1], mul(s[i - 1][j], j));
    	}
    }
    for(register int i = 0; i <= k; i++) {
    	if(n - i < 0) break;
    	int res = s[k][i];
    	for(register int j = n - i + 1; j <= n; j++) res = mul(res, j);
    	res = mul(res, fpow(2, n - i));
    	ans = add(ans, res);
    }
    print(ans, '\n');
    return 0;
}