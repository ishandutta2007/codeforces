//Author:Magic_Moon

#include<bits/stdc++.h>
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n,k;
const int maxn=55;
int f[maxn],fac[maxn];
const int inf=1e18+1;
int add(int a,int b)
{
	if(a+b>inf)return inf;
	else return a+b;
}
int mul(int a,int b)
{
	if(inf/a<b)return inf;
	else return a*b;
}
int ff(int x)
{
	if(x==1)return 1;
	else return fac[x-2];
}
int y[101],x[101];
void pre()
{
	fac[0]=1;
	up(i,1,50)fac[i]=mul(fac[i-1],i);
	f[0]=1;
	up(i,1,50)
	{
		up(j,1,i)
		{
			f[i]=add(f[i],mul(ff(j),f[i-j]));
		}
	}
}
int find(int x)
{
	return y[x]==0?x:find(y[x]);
}
int vis[1010];
void h(int n,int k)
{
	if(n==1)
	{
		y[1]=1;
		return;
	}
	up(i,1,n)vis[i]=0,y[i]=0;
	y[1]=n,vis[n]=1;
	up(i,2,n-1)
	{
		int nw=fac[n-i-1];
		up(j,1,n)
		{
			if(j!=i&&vis[j]==0&&find(j)!=i)
			{
				if(k<=nw)
				{
					y[i]=j;
					vis[j]=1;
					break;
				}
				k-=nw;
			}
		}
	}
	up(i,1,n)if(!vis[i])y[n]=i;
}
void g(int n,int k)
{
	if(!n)return;
	int l=0;
	up(i,1,n)
	{
		int nw=mul(ff(i),f[n-i]);
		if(k<=nw)
		{
			l=i;
			break;
		}
		k-=nw;
	}
	int s1=f[n-l];
	int rnk=(k-1)/s1+1;//
	g(n-l,k-(rnk-1)*s1);
	down(i,n,l+1)x[i]=x[i-l]+l;
	h(l,rnk);
	up(i,1,l)x[i]=y[i];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pre();
	int T;
	cin>>T;
	
	while(T--)
	{
		cin>>n>>k;
		if(f[n]<k)
		{
			cout<<"-1"<<endl;
			continue;
		}
		g(n,k);
		up(i,1,n)cout<<x[i]<<" ";
		cout<<endl;
	}
}