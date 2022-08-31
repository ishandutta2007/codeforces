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

int n,p,c;
string s;
int F[200010];

int main()
{
	cin>>n>>s;
	if (n&1)
	{
		puts("0");
		return 0;
	}
	F[p=100010]=1;
	c=n/2;
	for (int i=1;i<=n;++i)
	{
		if (s[i-1]=='?')
		{
			int t=min(i,n/2);
			for (int j=i%2;j<=t;j+=2)
				F[p+j]=F[p+j-1]+F[p+j+1];
		}
		else
		{
			p--;
			c--;
		}
	}
	for (int i=1;i<=c;++i)
		F[p]*=25;
	printf("%u\n",F[p]);
	return 0;
}