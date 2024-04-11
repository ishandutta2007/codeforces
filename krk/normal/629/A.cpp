#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
char B[Maxn][Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		int cnt = 0;
		for (int j = 0; j < n; j++)
			cnt += B[i][j] != '.';
		res += cnt * (cnt - 1) / 2;
	}
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += B[i][j] != '.';
		res += cnt * (cnt - 1) / 2;
	}
	printf("%d\n", res);
	return 0;
}