/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)


int n;
vector <pii> a;


int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int su = 0, x;
		for (int j = 0 ;j < 4; j++) read(x), su += x;
		a.push_back(mp(-su, i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) if (a[i].y == 1) {
		printf("%d\n", i + 1);
	}
	
	return 0;
}