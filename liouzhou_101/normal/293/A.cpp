#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=2000010;

int n;
char s[MaxN],t[MaxN];
int ns,nt,m;

int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	for (int i=1;i<=2*n;++i)
	{
		if (s[i]=='1'&&t[i]=='1') ++m;
		if (s[i]=='1'&&t[i]=='0') ++ns;
		if (s[i]=='0'&&t[i]=='1') ++nt;
	}
	m%=2;
	int tt=min(ns,nt);
	ns-=tt;
	nt-=tt;
	if (m)
	{
		if (ns)
		{
			puts("First");
			return 0;
		}
		if ((nt+1)/2<1)
			puts("First");
		else if ((nt+1)/2==1)
		{
			puts("Draw");
		}
		else
			puts("Second");
		return 0;
	}
	else
	{
		if (ns)
		{
			puts("First");
			return 0;
		}
		if (nt/2)
			puts("Second");
		else
			puts("Draw");
		return 0;
	}
	return 0;
}