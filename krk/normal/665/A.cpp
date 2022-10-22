#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a, ta;
int b, tb;
char str[10];
int res;

int main()
{
	scanf("%d %d", &a, &ta);
	scanf("%d %d", &b, &tb);
	scanf("%s", str);
	int tim = ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
	for (int i = 300; i < 1440; i += b)
		if (max(tim, i) < min(tim + ta, i + tb)) res++;
	printf("%d\n", res);
	return 0;
}