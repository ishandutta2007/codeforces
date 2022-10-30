//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}mt19937 rnd(1919810);
int n,a[35],vs[1000005],lim;inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
	read(n),lim=min(30,n),srand(2005);
	if(n<=30) for(int i=1;i<=n;i++) printf("? %d\n",i),fflush(stdout),read(a[i]);
	else for(int i=1,x;i<=30;i++) x=rnd()%n+1,printf("? %d\n",x),fflush(stdout),read(a[i]);
	int g=0;sort(a+1,a+lim+1);for(int i=2;i<=lim;i++) g=gcd(a[i]-a[i-1],g);
	int le=0,ri=(1000000000-a[lim])/g+1,md,rs=0,x;
	while(le<=ri) {md=(le+ri)>>1;printf("> %d\n",md*g+a[lim]),fflush(stdout),read(x);if(x) le=md+1;else ri=md-1,rs=md;}
	return printf("! %d %d\n",(rs-n+1)*g+a[lim],g),0;
}