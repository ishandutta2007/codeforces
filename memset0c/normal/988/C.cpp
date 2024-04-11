#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = std::getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::m = -1, r::c = getchar(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
using namespace std;
namespace r {
	char c;
	int m;
}
 
const int maxn = 200010;
int k, n, sum, a[maxn];
struct Node {
	int x, y;
};
map < int, Node > m;
 
int main() {
	
	read(k);
	for (int i = 1; i <= k; i++) {
		
		sum = 0; Node t;
		
		read(n);
		for (int j = 1; j <= n; j++) {
			read(a[j]);
			sum += a[j];
		}
	
		for (int j = 1; j <= n; j++) {
			t = m[sum - a[j]];
//			cout << t.x << " " << t.y << endl;
			if (t.x && t.y) {
				printf("YES\n%d %d\n%d %d\n", t.x, t.y, i, j);
				return 0;
			}
		}
		for (int j = 1; j <= n; j++) {
			m[sum - a[j]] = {i, j};
		}
	}
	printf("NO\n");
	return 0;
}