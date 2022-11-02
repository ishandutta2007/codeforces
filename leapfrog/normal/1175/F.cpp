//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[300005],ls[300005],nx[300005],pr[300005],st[300005],tp;
int main()
{
	read(n);int rs=0;for(int i=1;i<=n;i++) read(a[i]);
	memset(st,0,sizeof(st));for(int i=1;i<=n;i++) pr[i]=st[a[i]],st[a[i]]=i;
	for(int i=1;i<=n;st[++tp]=i++) while(tp&&a[st[tp]]<=a[i]) nx[st[tp]]=i,tp--;
	while(tp) nx[st[tp]]=n+1,tp--;
	for(int i=n;i>=1;st[++tp]=i--) while(tp&&a[st[tp]]<=a[i]) ls[st[tp]]=i,tp--;
	while(tp) ls[st[tp]]=0,tp--;
	for(int i=1;i<=n;i++) pr[i]=max(pr[i-1],pr[i]);
	//for(int i=1;i<=n;i++) printf("<%d,%d>%c",ls[i],nx[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) if(i-ls[i]<nx[i]-i)
		{for(int j=ls[i]+1;j<=i;j++) if(j+a[i]-1>=i&&j+a[i]-1<nx[i]&&pr[j+a[i]-1]<j) rs++;}
	else {for(int j=i;j<nx[i];j++) if(j-a[i]+1>ls[i]&&j-a[i]+1<=i&&pr[j]<j-a[i]+1) rs++;}
	return printf("%d\n",rs),0;
}