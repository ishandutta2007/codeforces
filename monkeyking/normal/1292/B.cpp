#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
ll x0x,y0y,ax,ay,bx,by;
ll xs,ys,t;
ll x[65],y[65];

double dig(ll x)
{
	return log(x)/log(10);
}

bool check(ll &time,ll cost)
{
	time-=cost;
	if(time>=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>x0x>>y0y>>ax>>ay>>bx>>by>>xs>>ys>>t;
	x[0]=x0x;
	y[0]=y0y;
	int n=1;
	for(int i=1;i<=62;i++)
	{
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
		if(dig(x[i-1])+dig(ax)>=17)
		{
			break;
		}
		n++;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		int now=0;
		ll nx=xs,ny=ys;
		ll time=t;
		if(!check(time,abs(nx-x[i])+abs(ny-y[i]))) continue;
		now++;
		res=max(res,now);
		nx=x[i];
		ny=y[i];
		bool flag=true;
		for(int j=i-1;j>=0;j--)
		{
			if(!check(time,abs(nx-x[j])+abs(ny-y[j])))
			{
				flag=false;
				break;
			}
			nx=x[j];
			ny=y[j];
			now++;
			res=max(res,now);
		}
		if(flag==false) continue;
		for(int j=i+1;j<n;j++)
		{
			if(!check(time,abs(nx-x[j])+abs(ny-y[j])))
			{
				flag=false;
				break;
			}
			nx=x[j];
			ny=y[j];
			now++;
			res=max(res,now);
		}
//		assert(flag==false);
	}
	cout<<res<<endl;
	return 0;
}