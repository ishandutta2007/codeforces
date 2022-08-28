#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int _mod = 1e9 + 7;

int add(int x, int y)
{
	return (x + y) % _mod;
}
int mul(int x, int y)
{
	return (x * 1LL * y) % _mod;
}

const int maxn = 1e5 + 100;
char str[maxn];
char rule[maxn];
int tenMod[11], mod[11];

string R[maxn];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 10; i++)
	{
		tenMod[i] = 10;
		mod[i] = i;
	}

	scanf("%s", str);
	int n;
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", rule);
		R[i] = string(rule);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sprintf(rule, "%s", R[i].c_str() );
		int ch = rule[0] - '0';
		int len = strlen(rule);
		
		int ans = 0;
		int tenAns = 1;
		for (int j = 3; j < len; j++)
		{
			int x = rule[j] - '0';
			ans = add(mul(ans, tenMod[x] ), mod[x] );
			tenAns = mul(tenAns, tenMod[x] );
		}
		mod[ch] = ans;
		tenMod[ch] = tenAns;
	}
	int ans = 0;
	int lens = strlen(str);
	for (int i = 0; i < lens; i++)
	{
		int x = str[i] - '0';
		ans = add(mul(ans, tenMod[x] ), mod[x] );
	}
	printf("%d\n", ans);


	return 0;
};