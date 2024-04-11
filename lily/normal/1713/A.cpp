#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


void work() {
	int n;
	read(n);
	set <int> X, Y;
	X.insert(0);
	Y.insert(0);
	for (int i = 1; i<= n; i++) {
		int x, y;
		read(x); read(y);
		X.insert(x);
		Y.insert(y);
	}
	printf("%d\n", 2 * (*X.rbegin() + *Y.rbegin() - *X.begin() - *Y.begin()));
}

int main() {
	int T;
	read(T);
	while (T--) work();
}