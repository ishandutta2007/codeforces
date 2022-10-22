#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n;
int p[Maxn], b[Maxn];
bool tk[Maxn];
int res;

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	int dif = 0;
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		dif++;
		while (!tk[i]) { tk[i] = true; i = p[i]; }
	}
	if (dif > 1) res += dif;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += b[i];
	if (cnt % 2 == 0) res++;
	printf("%d\n", res);
    return 0;
}