#include<bits/stdc++.h>
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
int a[25][25];
int main()
{
	int T=rd();
	while(T--)
	{
		int n=rd(),m=rd();
		rep(i,0,n+1)rep(j,0,m+1)a[i][j]=0;
		rep(i,1,n)rep(j,1,m)if(i==1||j==1||i==n||j==m)
		{
			int ff=1;
			rep(x,-1,1)rep(y,-1,1)if(a[i+x][j+y])ff=0;
			a[i][j]=ff;
		}
		rep(i,1,n)
		{
			rep(j,1,m)printf("%d",a[i][j]);
			puts("");
		}
	}
	return 0;
}