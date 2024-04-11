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

const int Maxd = 4;

int l[Maxd], m[Maxd], r[Maxd], p[Maxd];

int main()
{
	for (int i = 0; i < Maxd; i++)
		scanf("%d %d %d %d", &l[i], &m[i], &r[i], &p[i]);
	for (int i = 0; i < Maxd; i++) if (p[i])
		if (l[i] || m[i] || r[i] || l[(i + 1) % Maxd] || m[(i + 2) % Maxd] || r[(i + 3) % Maxd]) {
			printf("YES\n"); return 0;
		}
	printf("NO\n");
	return 0;
}