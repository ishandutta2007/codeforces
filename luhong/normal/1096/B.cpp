#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>
#define mod 998244353

char s[201000];
int main()
{
	int len; scanf("%d", &len);
	scanf("%s", s + 1);
	int s1 = 1, s2 = 1;
	for(int i = 2; i <= len; i++)
	{
		if(s[i] == s[i - 1]) s1++;
		else break;
	}
	for(int i = len - 1; i >= 1; i--)
	{
		if(s[i] == s[i + 1]) s2++;
		else break;
	}
	if(s[1] == s[len])
	{
		printf("%lld\n", 1ll * (s1 + 1) * (s2 + 1) % mod);
	}
	else
	{
		printf("%d\n", s1 + s2 + 1);
	}
	return 0;
}