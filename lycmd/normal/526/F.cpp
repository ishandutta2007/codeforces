#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=1200010;
int n,ans,t1,t2,a[N],mn[N],tr[N],lt[N],s1[N],s2[N];
void update(int x){
	mn[x]=min(mn[ls(x)],mn[rs(x)]);
	tr[x]=(mn[x]==mn[ls(x)])*tr[ls(x)]+(mn[x]==mn[rs(x)])*tr[rs(x)];
}
void add(int x,int k){
	lt[x]+=k,mn[x]+=k;
}
void download(int x){
	int&t=lt[x];
	if(!t)return;
	add(ls(x),t),add(rs(x),t),t=0;
}
void build(int x,int l,int r){
	if(l==r)
		return mn[x]=tr[x]=1,void();
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr)
		return add(x,k);
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,x,y;i<=n;i++)
		cin>>x>>y,a[x]=y;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		modify(1,1,n,1,i,-1);
		for(;t1&&a[s1[t1]]>a[i];t1--)
			modify(1,1,n,s1[t1-1]+1,s1[t1],a[s1[t1]]-a[i]);
		for(;t2&&a[s2[t2]]<a[i];t2--)
			modify(1,1,n,s2[t2-1]+1,s2[t2],a[i]-a[s2[t2]]);
		s1[++t1]=s2[++t2]=i,ans+=tr[1];
	}
	cout<<ans<<"\n";
}