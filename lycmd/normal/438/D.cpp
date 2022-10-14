#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,q,a[N],tr[N],mx[N];
void update(int x){
	mx[x]=max(mx[ls(x)],mx[rs(x)]);
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=mx[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
int querysum(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=querysum(ls(x),l,mid,ql,qr);
	if(qr>mid)res+=querysum(rs(x),mid+1,r,ql,qr);
	return res;
}
void modifymod(int x,int l,int r,int ql,int qr,int k){
	if(mx[x]<k)return;
	if(l==r){
		tr[x]%=k,mx[x]%=k;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)modifymod(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modifymod(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
void cover(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=mx[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)cover(ls(x),l,mid,p,k);
	else cover(rs(x),mid+1,r,p,k);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,l,r,x;
		cin>>op>>l>>r;
		switch(op){
			case 1:cout<<querysum(1,1,n,l,r)<<"\n";break;
			case 2:cin>>x,modifymod(1,1,n,l,r,x);break;
			case 3:cover(1,1,n,l,r);break;
		}
	}
}