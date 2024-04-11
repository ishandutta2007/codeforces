//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,lst=0,a[105],q[105];
inline int qry()
{
	printf("? ");for(int i=1;i<=n;i++) printf("%d%c",q[i],i==n?'\n':' ');
	fflush(stdout);int x;read(x);return x;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) q[i]=1;
	int vl=n;for(q[n]=2;q[n]<=n;q[n]++) if(qry()) vl=n+1-q[n];
	a[n]=vl,q[n]=n+1-vl;for(int i=1;i<=n;i++) if(i!=vl)
	{
		for(int j=1;j<n;j++) q[j]=n+1-i;
		a[qry()]=i;
	}
	printf("! ");for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	fflush(stdout);
	/*for(int i=1;i<=n;i++)
	{
		printf("? ");
		for(int j=1;j<n;j++) printf("1 ");
		printf("%d\n",i+1),fflush(stdout);
		int x;read(x);if(x==0) {lst=n-i+1;break;}
	}a[n]=lst;
	for(int i=1;i<=n;i++) if(i!=a[n])
	{
		printf("? ");
		for(int i=1;i<n;i++) printf("%d ",a[n]);
		printf("%d\n",i),fflush(stdout);
		int x;read(x),a[x]=i;
	}
	printf("! ");for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');*/
	//return fflush(stdout),0;
}