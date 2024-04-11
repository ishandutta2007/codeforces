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

const int Maxn = 1005;

int n, m, c;
int p;
int res[Maxn];
int lef, rig;

void Print(int ind)
{
	printf("%d\n", ind + 1);
	fflush(stdout);
}

int main()
{
	scanf("%d %d %d", &n, &m, &c); p = c / 2;
	lef = 0; rig = n - 1;
	for (int i = 0; i < m; i++) {
		int num; scanf("%d", &num);
		if (num <= p) {
			int j;
			for (j = 0; j < lef; j++)
				if (num < res[j]) break;
			res[j] = num; Print(j);
			if (j == lef) lef++;
		} else {
			int j;
			for (j = n - 1; j > rig; j--)
				if (num > res[j]) break;
			res[j] = num; Print(j);
			if (j == rig) rig--; 
		}
		if (lef > rig) break;
	}
	return 0;
}