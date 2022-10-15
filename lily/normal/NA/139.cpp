#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

int n;
vector <int> a, b;
int main() {
	read(n);
	if (n % 2 == 0) return puts("NO"), 0;
	for (int i = 1; i <= n; i++) {
		int x = i * 2 - 1, y = i * 2;
		if (i & 1) a.push_back(x), b.push_back(y);
		else a.push_back(y), b.push_back(x);
	}
	puts("YES");
	for (auto v : a) printf("%d ", v);
	for (auto v : b) printf("%d ", v);
}