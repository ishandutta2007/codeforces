#include<bits/stdc++.h>

using namespace std;

int test, c[1001];

int main(){
	scanf("%d", &test);
	for (; test--; ) {
		int n;
		scanf("%d", &n);
		int i = sqrt(n);
		n -= i * i;
		if (!n)
			printf("%d %d\n", i, 1);
		else
		if (n <= i + 1)
			printf("%d %d\n", n, i + 1);
		else
			printf("%d %d\n", i + 1, i + 1 - (n - (i + 1)));
	}
}