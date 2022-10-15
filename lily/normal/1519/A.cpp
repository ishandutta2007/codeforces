#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)


int main() {
	int T;
	read(T);
	while (T--) {
		int r, b, d;
		read(r); read(b); read(d);
		if (r < b) swap(r, b);
		puts(r > b * LL(d + 1) ? "NO" : "YES");
	}

}