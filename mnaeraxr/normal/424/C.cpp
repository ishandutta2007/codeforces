#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int x[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	int a = 0;
	for (int i = 1; i <= n; ++i){
		int v; 
		scanf("%d", &v);
		a ^= v;
		x[i] = x[i - 1] ^ i;
		int c = n % (2 * i);
		
		if (c >= i){
			a ^= x[i - 1];
			c -= i;
		}

		a ^= x[c];
	}
	printf("%d\n", a);
}