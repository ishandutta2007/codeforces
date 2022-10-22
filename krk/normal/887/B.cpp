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

const int Maxd = 6;
const int Maxn = 3;

int n;
int B[Maxn][Maxd];
int has[Maxn];
bool tk[Maxn];

bool Check(int lft)
{
	if (lft == 0) return true;
	int fnd = lft % 10;
	bool found = false;
	for (int i = 0; i < Maxn && !found; i++) if (!tk[i] && (has[i] & 1 << fnd)) {
		tk[i] = true;
		found = Check(lft / 10);
		tk[i] = false;
	}
	return found;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Maxd; j++) {
			scanf("%d", &B[i][j]);
			has[i] |= 1 << B[i][j];
		}
	}
	int i = 1;
	while (Check(i)) i++;
	printf("%d\n", i - 1);
	return 0;
}