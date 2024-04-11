#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


int main() {
	int T;
	read(T);
	while (T--) {
		int n; read(n);
		if (n == 1) puts("-1");
		else {
			putchar('2');
			while (--n) putchar('3');
			puts("");
		}
	}
}