#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int n;
vector <int> res;

int digSum(int n)
{
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= 900 && i <= n; i++)
		if (digSum(n - i) == i) res.push_back(n - i);
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}