#pragma comment(linker,"/STACK:60777216")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int frozed[20];
ll d[(1<<16)+1];
vector<ll> vec[17];
int g[17]={0};
int curr;
ll getCnt(int n)
{
	memset(d,0,sizeof(ll)*(1<<16)+1);
	d[0]=1;
	rep(i,1,n+1)
	{
		if (frozed[i-1]!=-1)
		{
			int pos=frozed[i-1];
			curr=1<<pos;
			rep(j,0,vec[i-1].size())
				if ((curr&vec[i-1][j])==0 && (g[pos]&vec[i-1][j])==0)
				{
					d[curr|vec[i-1][j]]+=d[vec[i-1][j]];
				}
		}
		else
		{
			rep(pos,0,n)
			{
				curr=1<<pos;
				rep(j,0,vec[i-1].size())
					if ((curr&vec[i-1][j])==0 && (g[pos]&vec[i-1][j])==0)
					{
						d[curr|vec[i-1][j]]+=d[vec[i-1][j]];
					}
			}
		}
	}
	return d[(1<<n)-1];
}

int main()
{
	int n,m;
	ll y;
	cin>>n>>y>>m;
	y-=2001;
	rep(i,0,1<<n)
	{
		int cnt=0;
		for (int j=0;j<n;j++)
			if ((i>>j)&1) cnt++;
		vec[cnt].push_back(i);
	}
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		g[a]|=(1<<b);
	}
	rep(i,0,n)
		frozed[i]=-1;
	ll res=getCnt(n);
	if (res<=y)
	{
		printf("The times have changed\n");
		return 0;
	}
	bool used[17]={0};
	rep(i,0,n)
	{
		bool was=0;
		rep(j,0,n)
			if (!used[j])
			{
				frozed[j]=i;
				ll curr=getCnt(n);
				if (curr>y)
				{
					used[j]=1;
					was=1;
					break;
				}
				else
				{
					frozed[j]=-1;
					y-=curr;
				}
			}
		if (!was)
		{
			printf("The times have changed\n");
			return 0;
		}
	}
	int ans[17];
	rep(i,0,n)
		ans[frozed[i]]=i;
	rep(i,0,n)
		printf("%d ",ans[i]+1);
	printf("\n");
	return 0;
}

/*

*/