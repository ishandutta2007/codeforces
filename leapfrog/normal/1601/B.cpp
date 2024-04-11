//Coded by leapfrog {{{
//Gened on 2021.10.25
//
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
const int N=300005;pair<int,int> T[N<<2];int n,a[N],b[N],ls[N];
int dp[N],ps[N],st[N],tp;vector<int>id[N*2];
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=make_pair(l==0?0:1000000000,l),void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=min(T[x<<1],T[x<<1|1]);
}
inline void modif(int x,int l,int r,int dw,pair<int,int>dc)
{
	if(l==r) return T[x]=min(T[x],dc),void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
}
inline pair<int,int> query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return make_pair(1e9,0);else if(dl<=l&&r<=dr) return T[x];
	return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	/*for(int i=1;i<=n*4;i++) T[i]=make_pair(1e9,1e9);
	//modif(1,1,n,0,make_pair(0,0));
	for(int i=1;i<=n;i++) if(i-a[i]<=0) modif(1,1,n,i,make_pair(1,i));
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1,st[i][0]=i;
	for(int i=0;i<16;i++) for(int j=1;j+(1<<i)<=n;j++) st[j][i+1]=chk(st[j][i],st[j+(1<<i)][i]);
	for(int i=1;i<=n;i++)
	{
		int R=i-a[i];if(R<=0) continue;else R=qry(R,i);
		if(R>i) continue;
		pair<int,int>w=query(1,1,n,R+b[R],i);
		//printf("%d : %d %d ( %d %d\n",i,R,i,w.first,w.second);
		ls[i]=w.second,modif(1,1,n,i,make_pair(w.first+1,i));
	}
	//for(int i=1;i<=n;i++) printf("%d%c",ls[i],i==n?'\n':' ');
	pair<int,int>w=query(1,1,n,n,n);if(w.first>=1e9) return puts("-1"),0;
	printf("%d\n",w.first);int nw=n;
	while(nw!=0) nw=ls[nw],printf("%d ",nw);
	return putchar('\n'),0;*/
	for(int i=1;i<=n;i++) dp[i]=1e9,ls[i]=-1,ps[i]=i;
	for(int i=1;i<=n;i++) id[i+b[i]].push_back(i);
	sort(ps+1,ps+n+1,[](int x,int y){return x-a[x]<y-a[y];});
	build(1,0,n);for(int z=1;z<=n;z++)
	{
		int i=ps[z];pair<int,int>qwq=query(1,0,n,max(0,i-a[i]),i);
		if(qwq.first>=1e9) continue;
		for(auto x:id[i]) {ls[x]=qwq.second,dp[x]=qwq.first+1,modif(1,0,n,x,make_pair(dp[x],x));}
	}
	int ps=n;do
	{
		if(!~ls[ps]) return puts("-1"),0;
		st[++tp]=ps=ls[ps];
	}while(ps);
	printf("%d\n",tp);
	for(int i=1;i<=tp;i++) printf("%d%c",st[i],i==tp?'\n':' ');
	return 0;
}