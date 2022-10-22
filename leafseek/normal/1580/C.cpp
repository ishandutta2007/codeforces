#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxNN=1000000+5,MaxN=1000+5;
constexpr int Const=400;
long long cum[MaxNN];
int xx[MaxNN],yy[MaxNN];
int sum[MaxN][MaxN];
int Last[MaxNN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
		cin>>xx[i]>>yy[i];
	int cmd,k;
	rep(i,1,m)
	{
		cin>>cmd>>k;
		if(cmd==1)
		{
			const int x=xx[k],y=yy[k];
			if((x+y)<=Const)
			{
				int c=(x+i)%(x+y);
				rep(j,1,y)
				{
					++sum[x+y][c];
					if((++c)==(x+y))
						c=0;
				}
			}
			else
			{
				for(int j=(x+i);j<=m;j+=(x+y))
				{
					++cum[j];
					if((j+y)<=m)
						--cum[j+y];
				}
			}
			Last[k]=i;
		}
		else if(cmd==2)
		{
			const int x=xx[k],y=yy[k];
			if((x+y)<=Const)
			{
				int c=(x+Last[k])%(x+y);
				rep(j,1,y)
				{
					--sum[x+y][c];
					if((++c)==(x+y))
						c=0;
				}
			}
			else
			{
				for(int j=(x+Last[k]);j<=m;j+=(x+y))
				{
					if((j+y)<i)
						continue;
					if(j<i)
					{
						--cum[i];
						if((j+y)<=m)
							++cum[j+y];
					}
					else
					{
						--cum[j];
						if((j+y)<=m)
							++cum[j+y];
					}
				}
			}
			Last[k]=0;
		}
		rep(I,1,Const)
		{
			cum[i]+=sum[I][i%I];
			cum[i+1]-=sum[I][i%I];
		}
	}
	rep(i,1,m)
		cum[i]+=cum[i-1];
	rep(i,1,m)
		cout<<cum[i]<<'\n';
	return 0;
}