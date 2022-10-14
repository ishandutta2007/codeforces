#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010;
int n,q,a[N];
struct node{
	int vl,vr,len,lc,rc,cnt;
	node operator+(const node&rhs)const{
		int flg=vr<=rhs.vl;
		return{
			vl,rhs.vr,len+rhs.len,
			lc==len&&flg?lc+rhs.lc:lc,
			rhs.rc==rhs.len&&flg?rc+rhs.rc:rhs.rc,
			cnt+rhs.cnt+flg*rc*rhs.lc
		};
	}
}tr[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]={a[l],a[r],1,1,1,1};
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]={k,k,1,1,1,1};
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(ls(x),l,mid,p,k);
	else modify(rs(x),mid+1,r,p,k);
	update(x);
}
node query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1;
	if(qr<=mid)
		return query(ls(x),l,mid,ql,qr);
	if(ql>mid)
		return query(rs(x),mid+1,r,ql,qr);
	return query(ls(x),l,mid,ql,qr)+query(rs(x),mid+1,r,ql,qr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op<2)
			modify(1,1,n,x,y);
		else
			cout<<query(1,1,n,x,y).cnt<<"\n";
	}
}