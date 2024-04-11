#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
int d[100005];
map <int,int> sum;
int a,b,c;

int cal(int x,int y,int z)
{
	return min(a,x)+min(b,y)+min(z,c);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int mx=-inf,mn=inf;
	rep(n)
	{
		cin>>d[i];
		sum[d[i]]++;
		mx=max(mx,d[i]);
		mn=min(mn,d[i]);
	}
	if(sum.size()==1)
	{
		cout<<n<<endl;
		rep(n)
		{
			cout<<d[i]<<' ';
		}
		cout<<endl;
	}
	else if(sum.size()==2)
	{
		if(mx==mn+1)
		{
			cout<<n<<endl;
			rep(n)
			{
				cout<<d[i]<<' ';
			}
			cout<<endl;
		}
		else
		{
			int k=min(sum[mx],sum[mn]);
			cout<<(n-k*2)<<endl;
			rep(k)
			{
				cout<<mn+1<<' '<<mn+1<<' ';
				sum[mx]--;
				sum[mn]--;
			}
			rep(sum[mx])
			{
				cout<<mx<<' ';
			}
			rep(sum[mn])
			{
				cout<<mn<<' ';
			}
			cout<<endl;
		}
	}
	else
	{
		a=sum[mn],b=sum[mn+1],c=sum[mn+2];
		int x=a-min(a,c),y=b+min(a,c)*2,z=c-min(a,c);
		int ax=x,ay=y,az=z;
		while(y!=0 && y!=1)
		{
			y-=2;
			x++;
			z++;
			if(cal(x,y,z)<cal(ax,ay,az))
			{
				ax=x;
				ay=y;
				az=z;
			}
		}
		cout<<cal(ax,ay,az)<<endl;
		rep(ax)
		{
			cout<<mn<<' ';
		}
		rep(ay)
		{
			cout<<mn+1<<' ';
		}
		rep(az)
		{
			cout<<mx<<' ';
		}
		cout<<endl;
	}
	return 0;
}