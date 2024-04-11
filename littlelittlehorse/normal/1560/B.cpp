#include<bits/stdc++.h>

using namespace std;

int test, c[1001];

int main(){
	scanf("%d", &test);
	for (; test--; ) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int n = abs(b - a) * 2;
		if (c > n || a > n || b > n)
			printf("-1\n");
		else {
			int d = c + n / 2;
			if (d > n)
				d -= n;
			printf("%d\n", d);
		}
	}
}