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

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i += 2)
		res.push_back(i);
	for (int i = 1; i <= n; i += 2)
		res.push_back(i);
	for (int i = 2; i <= n; i += 2)
		res.push_back(i);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}