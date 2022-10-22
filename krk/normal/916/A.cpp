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

const int mod = 24 * 60;

int x;
int cur;

int main()
{
	scanf("%d", &x);
	int h, m; scanf("%d %d", &h, &m);
	cur = 60 * h + m;
	for (int y = 0; ; y++, cur = (cur - x + mod) % mod) {
		h = cur / 60, m = cur % 60;
		if (h / 10 == 7 || h % 10 == 7 || m / 10 == 7 || m % 10 == 7) {
			printf("%d\n", y); return 0;
		}
	}
	return 0;
}