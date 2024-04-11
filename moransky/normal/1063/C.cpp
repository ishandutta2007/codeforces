#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


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

int n, I = 1e9;

string o;

int main() {
	read(n);
	if (n == 1) {
		printf("0 0\n");
		printf("1 1 1 0\n");
		return 0;
	}
	printf("%d %d\n", 0, I);
	string p, q; cin >> p;
	printf("%d %d\n", I, I);
	cin >> q;
	if (p == q) {
		int l = 0, r = I;
		for (int i = 1; i <= n - 2; i++) {
			int mid = (l + r) >> 1;
			printf("%d %d\n", 0, mid);
			cin >> o;
			if (o == p) r = mid;
			else l = mid;
		}
		int t = l + 1;
		printf("%d %d %d %d\n", 0, t, 1, t);
	} else {
		//  
		int l = 0, r = I;
		for (int i = 1; i <= n - 2; i++) {
			int mid = (l + r) >> 1;
			printf("%d %d\n", mid, 0);
			cin >> o;
			if (o == p) l = mid;
			else r = mid;
		}
		int t = l + 1;
		printf("%d %d %d %d\n", t, 0, t, 1);
	}
}