#include <iostream>
#include <cstdio>
 
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		if(n > m) std::swap(n, m);
		if(2 * n < m) puts("NO");
		else if((n + m) % 3 != 0) puts("NO");
		else puts("YES"); 
	}
}