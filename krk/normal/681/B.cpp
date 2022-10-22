#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	for (int a = 0; a <= n; a += 1234567)
		for (int b = a; b <= n; b += 123456)
			if ((n - b) % 1234 == 0) 
				{ printf("YES\n"); return 0; }
	printf("NO\n");
	return 0;
}