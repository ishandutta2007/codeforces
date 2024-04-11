#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxk = 105;

int n, m, k;
int cur[Maxk];
int sum;

int Get(int x)
{
	int i = 0;
	while (cur[i] != x) i++;
	int res = i + 1;
	while (i > 0) {
		swap(cur[i], cur[i - 1]);
		i--;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &cur[i]);
	while (n--) {
		for (int j = 0; j < m; j++) {
			int a; scanf("%d", &a);
			sum += Get(a);
		}
	}
	printf("%d\n", sum);
	return 0;
}