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
bool a[2][10];
bool f[2][10];
int n[2],nf;
double r[2],rf;
double d[2];
int nn;
double pro[2][2][10];

inline double calc(double x1,double y1,double r1,double x2,double y2,double r2)
{
	double il1=y1-sqrt(r1*r1-x1*x1);
	double ir1=y1+sqrt(r1*r1-x1*x1);
	double il2=y2-sqrt(r2*r2-x2*x2);
	double ir2=y2+sqrt(r2*r2-x2*x2);
	double il=max(il1,il2);
	double ir=min(ir1,ir2);
	return (ir-il<0?0:ir-il);
}

double solve(int x,int y,int type)
{
	if(x==0) x=1;else x=-1;
	double res=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(f[i][j]) res+=d[type]*calc((i==0?1:-1),j,rf,x,y,r[type]);
		}
	}
	res+=d[type]*calc(x,y,r[type],x,y,r[type]);
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	cout<<calc(1,1,10,1,0,10)*100<<endl;
	cin>>n[0]>>n[1]>>nf>>r[0]>>r[1]>>rf>>d[0]>>d[1];
	nn=n[0]+n[1]+nf;
	double res=0;
	for(int mask=0;mask<(1<<20);mask++)
	{
		if(__builtin_popcount(mask)!=nf) continue;
		memset(f,0,sizeof(f));
		for(int i=0;i<20;i++)
		{
			if(!((1<<i) & mask)) continue;
			f[i/10][i%10]=true;
		}
		priority_queue <double> que;
		for(int i=0;i<20;i++)
		{
			if((1<<i) & mask) continue;
			for(int type=0;type<2;type++)
			{
				pro[type][i/10][i%10]=solve(i/10,i%10,type);
			}
		}
		int r[2];
		r[0]=nn/2;
		r[1]=nn-r[0];
		double now=0;
		bool flag=false;
		for(int i=0;i<2;i++)
		{
			for(int j=r[i];j<10;j++)
			{
				if(f[i][j]) flag=true;
			}
		}
		if(flag) continue;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<r[i];j++)
			{
				if(f[i][j]) continue;
				now+=pro[0][i][j];
				que.push(pro[1][i][j]-pro[0][i][j]);
			}
		}
		for(int i=0;i<n[1];i++)
		{
			now+=que.top();
			que.pop();
		}
		if(now>res)
		{
			res=max(res,now);
		}
//		res=max(res,now);
	}
	cout.precision(10);
	cout<<res<<endl;
	return 0;
}