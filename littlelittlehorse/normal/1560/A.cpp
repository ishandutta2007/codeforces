#include<bits/stdc++.h>

using namespace std;

int test, c[1001];

int main(){
	int cnt = 0;
	for (int i = 1; i <= 1666; i++)
		if ((i % 3) && (i % 10 != 3))
			c[++cnt] = i;
	int test;
	scanf("%d", &test);
	for (; test--; ) {
		int n;
		scanf("%d", &n);
		printf("%d\n", c[n]);
	}
}