//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[300005],L[300005],R[300005],rs[300005];
int main()
{
	read(n);int mx=0,pnt=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) {L[i]=i;while(L[i]>1&&a[L[i]-1]%a[i]==0) L[i]=L[L[i]-1];}
	for(int i=n;i>=1;i--) {R[i]=i;while(R[i]<n&&a[R[i]+1]%a[i]==0) R[i]=R[R[i]+1];}
	for(int i=1;i<=n;i++) if(mx<R[i]-L[i]) mx=R[i]-L[i],rs[pnt=1]=L[i];else if(mx==R[i]-L[i]&&L[i]!=rs[pnt]) rs[++pnt]=L[i];
	printf("%d %d\n",pnt,mx);for(int i=1;i<=pnt;i++) printf("%d%c",rs[i],i==pnt?'\n':' ');
	return 0;
}