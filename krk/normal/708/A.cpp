#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

char str[Maxn];
int n;

int main()
{
	scanf("%s", str); n = strlen(str);
	int pnt = 0;
	while (pnt < n && str[pnt] == 'a') pnt++;
	if (pnt == n) {
		str[n - 1] = 'z';
	} else {
		int j = pnt;
		while (j < n && str[j] != 'a') j++;
		for (int i = pnt; i < j; i++)
			str[i]--;
	}
	printf("%s\n", str);
	return 0;
}