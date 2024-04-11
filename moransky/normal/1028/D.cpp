// Skyqwq
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef set<int>::iterator SIT;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;

const int N = 2e6 + 5, P = 1e9 + 7;

int n, d[N], t, L = -2e9, R = 2e9;

set<int> C;
char op[10];


int main() {
	read(n); int oo = n;
	int cnt = 1, sum = 0;
	while (n--) {
		scanf("%s", op); int x; read(x);
		if (op[1] == 'C') {
			sum = 0;
			C.erase(x);
			if (x < L || x > R) {
				puts("0");
				return 0;
			}
			if (L != x && x != R) {
				cnt = cnt * 2 % P;
			}
			
			SIT it = C.lower_bound(x);
			if (it != C.end()) {
				R = *it;
			} else R = 2e9;
			if (it != C.begin()) {
				--it;
				L = *it;
			} else L = -2e9;
			
		} else {
			C.insert(x);
			if (x >= L && x <= R)sum++;
		}
	}
	cnt = 1ll * cnt * (sum + 1) % P;
	printf("%d\n", cnt);
	return 0;
}