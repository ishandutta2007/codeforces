#include <bits/stdc++.h>
using namespace std;


void work() {
	int n, x;
	scanf("%d%d", &n, &x);
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		a.push_back(v);
	}


	mt19937 rng(123);
	for (int T = 10; T--; ) {
		shuffle(a.begin(), a.end(), rng);
		int sum = 0; bool flag = 1;
		for (auto i : a) {
			sum += i;
			if (sum == x) {
				flag = false;
				break;
			}
		}
		if (flag) {
			puts("YES");
			for (auto i : a) printf("%d ", i);
			puts("");
			return;
		}
	}
	puts("NO");
}

int main() {
	int T;
	cin >> T;
	while (T--) work();

}