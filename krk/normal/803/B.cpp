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

const int Maxn = 200005;
const int Inf = 1000000000;

int n;
int a[Maxn];
int L[Maxn], R[Maxn];

int main()
{
	scanf("%d", &n);
	L[0] = Inf;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		L[i] = a[i] == 0? 0: L[i - 1] + 1;
	}
	R[n + 1] = Inf;
	for (int i = n; i > 0; i--)
		R[i] = a[i] == 0? 0: R[i + 1] + 1;
	for (int i = 1; i <= n; i++)
		printf("%d%c", min(L[i], R[i]), i + 1 <= n? ' ': '\n');
	return 0;
}