#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;



const int maxn = 200500;
char str[maxn];
char s[maxn];
int z[maxn];

void calcZ(int len)
{
	int winL = 0, winR = 0;
	for (int i = 1; i < len; i++)
	{
		int curZ = 0;
		if (i < winR)
			curZ = min(winR - i, z[i - winL] );
		while (str[curZ] == str[i + curZ] )
			curZ++;
		z[i] = curZ;
		if (i + curZ > winR)
		{
			winL = i;
			winR = i + curZ;
		}
	}
}

const int mod = (int) 1e9 + 7;
int dpAlready[maxn];
int dpNeed[maxn];
int curNot;

void add(int &a, int b)
{
	a += b;
	a %= mod;
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s);
	scanf("%s", str);
	int m = strlen(str);
	str[m] = '#';
	for (int i = 0; i < n; i++)
		str[i + m + 1] = s[i];
	calcZ(n + m + 1);

	curNot = 1;	
	for (int i = 0; i < n; i++)
	{
		add(dpAlready[i + 1], dpAlready[i] );
		add(dpNeed[i], curNot);
		if (z[i + m + 1] == m)
		{
			add(dpAlready[i + m], dpNeed[i] );
			dpNeed[i] = 0;
		}
		add(dpNeed[i + 1], dpNeed[i] );
		add(curNot, dpAlready[i + 1] );
	}
	int ans = curNot;
	printf("%d\n", (ans + mod - 1) % mod);


	return 0;
}