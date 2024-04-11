#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 3;

int x, y;
int cur[Maxd];
int res;

int main()
{
	scanf("%d %d", &x, &y);
	cur[0] = cur[1] = cur[2] = y;
	while (true) {
		sort(cur, cur + Maxd);
		if (cur[0] >= x) break;
		cur[0] = cur[1] + cur[2] - 1;
		res++;
	}
	printf("%d\n", res);
	return 0;
}