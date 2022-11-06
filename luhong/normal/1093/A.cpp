#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		if(n % 7 == 0) printf("%d\n", n / 7);
		else printf("%d\n", n / 7 + 1);
	}
	return 0;
}