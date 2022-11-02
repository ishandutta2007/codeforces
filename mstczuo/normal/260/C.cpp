# include <iostream>
# include <cstdio>
# define For(i,a,b) for(int i=a;i<=b;i++)
# define rep(i,n) For(i,1,n)
using namespace std;
long long a[100010],m=~0U>>1;
int n,x;

int getint()
{
	static char c; 
	static int ret;
	while(!isdigit(c=getchar()));
	ret=c-'0';
	while( isdigit(c=getchar()))
		ret=ret*10+c-'0';
	return ret;
}
inline void write()
{
	rep(i,n)printf("%lld ",a[i]);printf("\n");
}
int main()
{
	n=getint(); x=getint();
	rep(i,n) a[i]=getint();
	rep(i,n) if(a[i]<m)m=a[i];
	if(a[x]==m){rep(i,n)a[i]-=m;a[x]=m*n;write();return 0;}
	for(int i=x;i;--i)if(a[i]==m){
		rep(j,n)a[j]-=m;For(j,i+1,x)a[j]--;a[i]=m*n+x-i;write();return 0;
	}
	for(int i=n;i;--i)if(a[i]==m){
		rep(j,n)a[j]-=m+1;For(j,x+1,i)a[j]++;a[i]=(m+1)*n-(i-x);write();return 0;
	}
}