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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n,x,y;
string s;
int u[1110];

int main()
{
	cin>>s;
	n=s.size();
	for (int i=0;i<n;++i)
		if (s[i]=='?')
			++x;
		else if (s[i]>='A'&&s[i]<='J')
		{
			if (!u[s[i]])
			{
				u[s[i]]=1;
				++y;
			}
		}
	ll ans=1;
	if (s[0]=='?')
	{
		--x;
		ans*=9;
	}
	if (s[0]>='A'&&s[0]<='J')
	{
		ans*=9;
		for (int i=1;i<y;++i)
			ans*=10-i;
	}
	else
	{
		for (int i=1;i<=y;++i)
			ans*=10-i+1;
	}
	cout<<ans;
	while (x--) putchar('0');
	return 0;
}