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
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a == 0) cnt++;
	}
	if (n > 1 && cnt == 1 || n == 1 && cnt == 0)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}