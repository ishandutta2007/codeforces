#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt, ans[1000001];

int main(){
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++)
			ans[++cnt] = i;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
}