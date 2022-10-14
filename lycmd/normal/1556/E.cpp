#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010,INF=0x3f3f3f3f3f3f3f3fll;
int n,q,a[N],b[N],s[N],mx[N],mn[N];
void update(int x){
	mx[x]=max(mx[ls(x)],mx[rs(x)]);
	mn[x]=min(mn[ls(x)],mn[rs(x)]);
}
void build(int x,int l,int r){
	if(l==r){
		mn[x]=mx[x]=s[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
int querymin(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return mn[x];
	int mid=(l+r)>>1,res=INF;
	if(ql<=mid)res=min(res,querymin(ls(x),l,mid,ql,qr));
	if(qr>mid)res=min(res,querymin(rs(x),mid+1,r,ql,qr));
	return res;
}
int querymax(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return mx[x];
	int mid=(l+r)>>1,res=-INF;
	if(ql<=mid)res=max(res,querymax(ls(x),l,mid,ql,qr));
	if(qr>mid)res=max(res,querymax(rs(x),mid+1,r,ql,qr));
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+b[i]-a[i];
	build(1,1,n);
	while(q--){
		int l,r;cin>>l>>r;
		if(s[l-1]^s[r]){
			cout<<"-1\n";
			continue;
		}
		int mn=querymin(1,1,n,l,r)-s[l-1],
			mx=querymax(1,1,n,l,r)-s[l-1];
		cout<<(mn<0?-1:mx)<<"\n";
	}
}