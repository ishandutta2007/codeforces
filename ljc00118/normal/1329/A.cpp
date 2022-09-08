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
 
int a[N], ans[N];
int n, m, l, r;
ll sum;
 
int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        read(a[i]);
        sum += a[i];
    }
    if (sum < n) {
        print(-1, '\n');
        return 0;
    }
    ans[1] = 1; l = 1; r = a[1]; sum -= a[1];
    for (int i = 2; i <= m; i++) {
    	int newlen = max(0, max((int)max(0ll, n - r - (sum - a[i])), l + a[i] - r));
    	if (newlen) {
	    	r += newlen;
	    	if (r > n) {
	    		print(-1, '\n');
	    		return 0;
	    	}
	    	ans[i] = r - a[i] + 1;
	    	l = ans[i]; sum -= a[i];
	    	continue;
	    }
	    ++l; ans[i] = l; sum -= a[i];
    }
    for (int i = 1; i <= m; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}