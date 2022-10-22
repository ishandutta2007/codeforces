#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

vector <int> V;
int k;

int Sum(int x)
{
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &k);
	for (int i = 1; V.size() < k; i++)
		if (Sum(i) == 10) V.push_back(i);
	printf("%d\n", V.back());
	return 0;
}