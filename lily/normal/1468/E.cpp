#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a[4];
		for (int i = 0; i < 4; i++) scanf("%d",  a+ i);
		sort(a, a + 4);
		printf("%d\n", min(a[0], a[1]) * min(a[2], a[3]));
	}

}