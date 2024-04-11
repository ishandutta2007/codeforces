#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=5e4+5;
int n;
int id[N];
ll a[N],x,b[N],dp[N],lsh[N];
int tot;
ll seg[N<<2];
void change(int k,int l,int r,int p,ll v) {
	if(l==r) return seg[k]=v,void();
	int mid=l+r>>1;
	if(p<=mid) change(k<<1,l,mid,p,v);
	else change(k<<1|1,mid+1,r,p,v);
	seg[k]=min(seg[k<<1],seg[k<<1|1]);
}
ll query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return seg[k];
	int mid=l+r>>1; ll res=0x3f3f3f3f;
	if(x<=mid) res=query(k<<1,l,mid,x,y);
	if(y>mid) res=min(res,query(k<<1|1,mid+1,r,x,y));
	return res;
}
int getid(ll x) {return lower_bound(lsh+1,lsh+tot+1,x)-lsh;}
ll st[20][N]; int dlg[N];
ll getmax(int l,int r) {
	int k=__lg(r-l+1);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i],a[i]+=a[i-1];
		cin>>x;
		tot=0;
		fr(i,1,n) b[i]=a[i]-i*x,lsh[++tot]=b[i];
		dlg[0]=-1; fr(i,1,n) st[0][i]=b[i],dlg[i]=dlg[i>>1]+1;
		st[0][0]=b[0];
		fr(k,1,19) fr(i,0,n-(1<<k)+1) st[k][i]=max(st[k-1][i],st[k-1][i+(1<<k-1)]);
		lsh[++tot]=b[0];
		sort(lsh+1,lsh+tot+1);
		tot=unique(lsh+1,lsh+tot+1)-lsh-1;

		fr(i,1,n+1) dp[i]=0x3f3f3f3f;
		fr(i,1,4*(n+1)) seg[i]=0x3f3f3f3f;
		change(1,0,n,0,dp[0]=0);
		int p=0;
		fr(i,1,n+1) {
			while(p<i-2&&getmax(p,i-3)>b[i-1]) ++p;
			dp[i]=query(1,0,n,p,i-1)+1;
			change(1,0,n,i,dp[i]);
		}
		//fr(i,1,n+1) cout<<b[i]<<' '<<dp[i]<<endl;
		cout<<n-(dp[n+1]-1)<<endl;
	}
	return 0;
}