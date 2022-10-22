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

const int Maxm = 3000005;
const int Maxn = 2005;

int n;
int a[Maxn], b[Maxn];
bool was[Maxm];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); was[a[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]); was[b[i]] = true;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (was[a[i] ^ b[j]]) res++;
	printf("%s\n", res % 2? "Koyomi": "Karen");
	return 0;
}