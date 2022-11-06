#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

char s[101000];
long long f[101000][4];
int v[101000];

int main()
{
	int n; scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 'h') f[i][0] = f[i - 1][0] + v[i];
		else f[i][0] = f[i - 1][0];
		if(s[i] == 'a') f[i][1] = std::min(f[i - 1][0], f[i - 1][1] + v[i]);
		else f[i][1] = f[i - 1][1];
		if(s[i] == 'r') f[i][2] = std::min(f[i - 1][1], f[i - 1][2] + v[i]);
		else f[i][2] = f[i - 1][2];
		if(s[i] == 'd') f[i][3] = std::min(f[i - 1][2], f[i - 1][3] + v[i]);
		else f[i][3] = f[i - 1][3];
	}
	printf("%lld\n", std::min(std::min(f[n][0], f[n][1]), std::min(f[n][2], f[n][3])));
}