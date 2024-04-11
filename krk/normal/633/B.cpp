#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> res;

int Zeros(int n)
{
	int res = 0;
	for (int i = 5; i <= n; i *= 5)
		res += n / i;
	return res;
}

int main()
{
	int m; scanf("%d", &m);
	for (int i = 1; i <= 1000000; i++)
		if (Zeros(i) == m) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}