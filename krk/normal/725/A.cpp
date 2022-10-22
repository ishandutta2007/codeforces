#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n;
char str[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	int l = 0, r = n - 1;
	while (l <= r)
		if (str[l] == '<') { res++; l++; }
		else if (str[r] == '>') { res++; r--; }
		else break;
	printf("%d\n", res);
	return 0;
}