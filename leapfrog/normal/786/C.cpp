//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[100005];char T[100005];
inline int solve(int K)
{
	memset(T,0,n+1);int cnt=1,tot=0,lst=1;
	for(int i=1;i<=n;i++)
	{
		if(!T[a[i]]) T[a[i]]=1,++tot;
		if(tot>K) {cnt++,tot=1;while(lst<i) T[a[lst++]]=0;}
	}
	return cnt;
}
int main()
{
	read(n);int sz=sqrt(n*log(n)/log(2));for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=sz;i++) printf("%d%c",solve(i),i==n?'\n':' ');
	for(int i=sz+1;i<=n;)
	{
		int nw=solve(i),le=i,ri=n,rs=i;
		while(le<=ri) {int md=(le+ri)>>1;if(solve(md)<nw) ri=md-1;else le=md+1,rs=md;}
		for(;i<=rs;i++) printf("%d%c",nw,i==n?'\n':' ');
	}
	return 0;
}