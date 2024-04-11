#include <iostream>
#include <cstdio>
 
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
 
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int r, b, k; scanf("%d%d%d", &r, &b, &k);
		int g = gcd(r, b);
		r /= g; b /= g;
		if(r < b) std::swap(r, b);
		if((r - 1) / b + ((r - 1) % b > 0) >= k) puts("REBEL");
		else puts("OBEY");
		
	}
}