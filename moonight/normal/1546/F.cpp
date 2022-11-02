#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define mp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=1005;
int n,m,a1,a2;ll x,y,s,t,a[N][N],c[N];
int main()
{
	n=rd();m=rd();
	rep0(i,0,m)rep(j,1,n)a[i][j]=rd(),c[i]+=a[i][j];
	x=(c[m-1]-c[0])/(m-1);
	rep0(i,1,m)if(c[i]-c[0]!=x*i){a1=i;y=c[i]-c[0]-x*i;break;}
	rep0(i,1,m-1)if(i-1!=a1&&i!=a1&&i+1!=a1)
	{
		x=0;
		rep(j,1,n)x+=a[i-1][j]*a[i-1][j]+a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j]*2;
		break;
	}
	int i=a1;
	rep(j,1,n)s+=a[i-1][j]*a[i-1][j]+a[i+1][j]*a[i+1][j];
	rep(j,1,n)t+=a[i][j]*a[i][j]*2;
	s-=x;
	rep(j,1,n)
	{
		ll w=t-a[i][j]*a[i][j]*2+(a[i][j]-y)*(a[i][j]-y)*2;
		if(w==s){a2=a[i][j]-y;break;}
	} 
	printf("%d %d\n",a1,a2);
	return 0;
}