#include <bits/stdc++.h>
using namespace std;
const int Q = 3 * 100000000 + 1;
bitset<Q>V;

int main() 
{
	int a, n;
	scanf("%d %d", &a, &n);
	for(int i = 3; i * i <= n; i += 2)
		if(!V[i])
			for(int j = i * i; j <= n; j += i << 1)
				V[j] = 1;
	V[1] = 1;
	int b = a, res = 0;
	while((b % 4) != 1) b ++;
	for(int i = b; i <= n; i += 4)
		if(!V[i])
			res ++;
	if(a <= 2 && 2 <= n)
		res ++;
	printf("%d\n", res);
}