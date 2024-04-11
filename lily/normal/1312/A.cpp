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
		int u, v;
		read(u); read(v);
		puts(u >= v && __gcd(u, v) == v ? "YES" : "NO");
	}

}