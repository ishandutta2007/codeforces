#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	b -= a;
	if (b == 0 || c != 0 && b % c == 0 && b / c >= 0) printf("YES\n");
	else printf("NO\n"); 
	return 0;
}