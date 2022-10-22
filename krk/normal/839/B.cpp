#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxk = 105;

int n, k;
int a[Maxk];

int main()
{
	scanf("%d %d", &n, &k);
	int fours = n;
	int twos = 2 * n;
	int o = 0, t = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		while (a[i] >= 4 && fours > 0) { a[i] -= 4; fours--; }
		while (a[i] >= 2 && twos > 0) { a[i] -= 2; twos--; }
		while (a[i] >= 2) { t++; a[i] -= 2; }
		if (a[i] == 1) o++;
	}
	while (t > 0 && twos > 0) { t--; twos--; }
	while (o > 0 && twos > 0) { o--; twos--; }
	while (t > 0 && fours > 0) { 
		o--; t--; fours--; 
		if (o <= -2) { o += 2; t--; }
	}
	while (o > 0 && fours > 0) { o -= 2; fours--; }
	if (o > 0 || t > 0) printf("NO\n");
	else printf("YES\n");
	return 0;
}