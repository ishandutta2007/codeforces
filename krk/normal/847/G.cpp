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

const int Maxd = 7;

int n;
int sum[Maxd];

int main()
{
	scanf("%d", &n);
	while (n--) {
		string s; cin >> s;
		for (int i = 0; i < Maxd; i++)
			sum[i] += s[i] - '0';
	}
	int res = 0;
	for (int i = 0; i < Maxd; i++)
		res = max(res, sum[i]);
	printf("%d\n", res);
	return 0;
}