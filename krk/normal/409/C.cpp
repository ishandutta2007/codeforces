#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 5;
const int need[Maxn] = {1, 1, 2, 7, 4};

int res = 1000;

int main()
{
	for (int i = 0; i < Maxn; i++) {
		int a; scanf("%d", &a);
		res = min(res, a / need[i]);
	}
	printf("%d\n", res);
	return 0;
}