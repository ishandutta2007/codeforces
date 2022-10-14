#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,a[N],mn[N];
void update(int x){
	mn[x]=min(mn[ls(x)],mn[rs(x)]);
}
void build(int x,int l,int r){
	if(l==r){mn[x]=a[l];return;}
	int mid=(l+r)>>1;
	build(ls(x),l,mid),build(rs(x),mid+1,r);
	update(x);
}
int query(int x,int l,int r,int ql,int qr,int k){
	if(ql>qr||mn[x]>=a[k])return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(ql>mid)return query(rs(x),mid+1,r,ql,qr,k);
	if(qr<=mid)return query(ls(x),l,mid,ql,qr,k);
	int res=query(rs(x),mid+1,r,ql,qr,k);
	if(~res)return res;
	res=query(ls(x),l,mid,ql,qr,k);
	return ~res?res:query(ls(x),l,mid,ql,qr,k);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int ans=query(1,1,n,i+1,n,i);
		cout<<(~ans?ans-i-1:-1)<<" ";
	}
}