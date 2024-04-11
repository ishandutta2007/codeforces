#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int SZ = (int) 3e6;
int goTo[SZ][2];
int cntExact[SZ];
const int LEN = 20;
int sz = 1;

void add(char str[], int x)
{
	int pos = 0;
	int len = strlen(str);
	for (int i = 0; i < LEN; i++)
	{
		if (i > len)
			str[i] = '0';
		int cur = (str[i] - '0') % 2;
		if (goTo[pos][cur] == -1)
			goTo[pos][cur] = sz++;
		pos = goTo[pos][cur];
	}
	cntExact[pos] += x;
}

int getAns(char str[])
{
	int pos = 0;
	int ans = 0;
	int len = strlen(str);
	for (int i = 0; i < LEN; i++)
	{
		if (i > len)
			str[i] = '0';
		int cur = (str[i] - '0') % 2;
		if (goTo[pos][cur] == -1)
			return ans;
		pos = goTo[pos][cur];
		ans += cntExact[pos];
	}
	return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	memset(goTo, -1, sizeof goTo);

	int t;
	scanf("%d", &t);
	for (int it = 0; it < t; it++)
	{
		char ch[2];
		char str[25];
		scanf("%s%s", ch, str);
		int len = strlen(str);
		reverse(str, str + len);
	
		if (ch[0] == '+')
			add(str, 1);
		else if (ch[0] == '-')
			add(str, -1);
		else printf("%d\n", getAns(str) );
	}



	return 0;
}