#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
int n,k,m[15],q[15][45],V[15][45];
void dfs(int x)
{
//	cout<<x<<": ";fore(i,V)cout<<V[i]<<" ";cout<<endl;
	if(x==k+1)
	{
		int ss=0;
		rep0(i,0,n)if(V[x][i]==-1)ss++;
		if(ss==1&&V[x][0]==-1)
		{
			rep0(i,1,n)if(!V[x][i])
			{
				puts("REJECTED");
				exit(0);
			}
			return;
		}
		if(ss==1&&V[x][n-1]==-1)
		{
			rep0(i,0,n-1)if(V[x][i])
			{
				puts("REJECTED");
				exit(0);
			}
			return;
		}
		rep0(i,0,n)if(V[x][i]==-1)
		{
			puts("REJECTED");
			exit(0);
		}
		rep0(i,1,n)if(!V[x][i]&&V[x][i-1])
		{
			puts("REJECTED");
			exit(0);
		}
		return;
	} 
	int nn=m[x],s0=0,s1=0;
	rep(i,1,nn)
	{
		int t=V[x][q[x][i]];
		if(t==0)s0++;
		if(t==1)s1++; 
	}
	rep0(i,0,n)V[x+1][i]=V[x][i];
	rep(j,1,s0)V[x+1][q[x][j]]=0;
	rep(j,s0+1,nn)V[x+1][q[x][j]]=1;
	rep(i,s0,nn-s1){if(i)V[x+1][q[x][i]]=0;dfs(x+1);}
}
int main()
{
	n=rd();k=rd();
	rep(i,1,k)
	{
		m[i]=rd();
		rep(j,1,m[i])q[i][j]=rd()-1;
		sort(q[i]+1,q[i]+m[i]+1); 
	}
	rep0(i,0,n)V[1][i]=-1;
	dfs(1);puts("ACCEPTED");
	return 0;
}