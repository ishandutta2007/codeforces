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

const int Maxn = 100005;

int n;
int freq[Maxn];

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		freq[a]++;
	}
	int pnt = Maxn - 1;
	while (pnt >= 0 && freq[pnt] % 2 == 0) pnt--;
	if (pnt < 0) printf("Agasa\n");
	else printf("Conan\n");
	return 0;
}