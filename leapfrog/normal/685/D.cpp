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
const int N=200005;int n,K,tn[N],ut,ls[N],cn[N];ll rs[N];
struct ${int x,y,v;char operator<($ b) {return x<b.x;}}a[N];
int main()
{
	read(n,K);for(int i=1,x,y;i<=n;i++)
		read(x,y),a[i]=($){x-K,y,1},a[i+n]=($){x,y,-1},tn[++ut]=y,tn[++ut]=y-K;
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1,sort(a+1,a+n+n+1);
	for(int i=1;i<=n+n;i++)
	{
		int l=lower_bound(tn+1,tn+ut+1,a[i].y-K)-tn;
		int r=lower_bound(tn+1,tn+ut+1,a[i].y)-tn;
		for(int j=l+1;j<=r;j++)
			rs[cn[j]]+=1ll*(tn[j]-tn[j-1])*(a[i].x-ls[j]),
			ls[j]=a[i].x,cn[j]+=a[i].v;
	}
	for(int i=1;i<=n;i++) printf("%lld%c",rs[i],i==n?'\n':' ');
	return 0;
}