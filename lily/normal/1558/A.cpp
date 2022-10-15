#include <bits/stdc++.h>
using namespace std;

void work() {
	int a, b;
	scanf("%d%d", &a, &b);
	set <int> s;
	int n = (a + b);
	int L = n / 2, R = n - L;
	for (int i = 0; i <= L; i++) {
		int aL = i;
		int aR = a - i;
		int bL = L - i;
		int bR = b - bL;
		if (aL < 0 || aR < 0 || bL < 0 || bR < 0) continue;
		s.insert (aR + bL);
	}
	swap(L, R);
	for (int i = 0; i <= L; i++) {
		int aL = i;
		int aR = a - i;
		int bL = L - i;
		int bR = b - bL;
		if (aL < 0 || aR < 0 || bL < 0 || bR < 0) continue;
		s.insert (aR + bL);
	}
	printf("%d\n", (int)s.size());
	for (auto i : s) printf("%d ", i);
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}