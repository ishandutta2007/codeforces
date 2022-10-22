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

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > 0) sum += a[i];
	}
	if (sum % 2 == 0) {
		int mx = -Maxn;
		for (int i = 0; i < n; i++)
			if (a[i] > 0 && a[i] % 2 == 1) mx = max(mx, -a[i]);
			else if (a[i] < 0 && (-a[i]) % 2 == 1) mx = max(mx, a[i]);
		sum += mx;
	}
	printf("%d\n", sum);
	return 0;
}