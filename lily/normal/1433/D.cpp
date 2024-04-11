#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector <int> a;
		int last = 0;
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			a.push_back(x);
			if (i != 1 && x != last) flag = 0;
			last = x;
		}
		if (flag) puts("NO");
		else {
			puts("YES");
			int i = 0;
			while (a[i] == a[0]) i++;
			for (int j = 1; j < n ; j++) {
				if (a[j] == a[0]) {
					assert (a[i] != a[j]);
					printf("%d %d\n", i + 1, j + 1);
				}
				else {
					assert (a[0] != a[j]);
					printf("%d %d\n", 1, j + 1);
				}
			}
		}
	}


}