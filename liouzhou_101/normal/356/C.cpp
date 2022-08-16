#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1000010;

int n,s;
int d[10];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		d[x]++;
		s+=x;
	}
	if (s==1||s==2||s==5)
	{
		puts("-1");
		return 0;
	}
	int ans=0;
	if (d[1]>d[2])
	{
		ans+=d[2];
		d[3]+=d[2];
		d[1]-=d[2];
		d[2]=0;
		ans+=d[1]/3*2;
		d[3]+=d[1]/3;
		d[1]%=3;
		if (d[1]==1)
		{
			if (d[3]) ans++;
				else ans+=2;
		}
		else if (d[1]==2)
		{
			ans+=2;
		}
	}
	else
	{
		ans+=d[1];
		d[3]+=d[1];
		d[2]-=d[1];
		d[1]=0;
		ans+=d[2]/3*2;
		d[3]+=d[2]/3*2;
		d[2]%=3;
		if (d[2]==1)
		{
			if (d[4]) ans++;
				else ans+=2;
		}
		else if (d[2]==2)
		{
			ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}