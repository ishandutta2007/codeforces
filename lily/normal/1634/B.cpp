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
		int n, x; long long y;
		read(n); read(x);cin >> y;
		for (int i = 1; i<= n; i++) {
			int z; read(z); x ^= z;
		}
		puts((x ^ y) & 1 ? "Bob" : "Alice");

	}

}