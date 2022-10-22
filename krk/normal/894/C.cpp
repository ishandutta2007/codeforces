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

const int Maxm = 1005;

int m;
int a[Maxm];
vector <int> res;

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < m; i++)
		if (a[i] % a[0] != 0) { printf("-1\n"); return 0; }
	res.push_back(a[0]);
	for (int i = 1; i < m; i++) {
		res.push_back(a[i]);
		res.push_back(a[0]);
	}
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}