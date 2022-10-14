#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333;
int n,m,l[N],r[N],x[N],tr[N],ans[N];
inline void download(int x){
	if(!tr[x])return;
	tr[ls(x)]=tr[rs(x)]=tr[x],tr[x]=0;
}
inline void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){tr[x]=k;return;}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
}
inline void getans(int x,int l,int r){
	if(l==r){ans[l]=tr[x];return;}
	download(x);
	int mid=(l+r)>>1;
	getans(ls(x),l,mid);
	getans(rs(x),mid+1,r);
} 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>l[i]>>r[i]>>x[i];
	for(int i=m;i>=1;i--){
		if(x[i]>l[i])modify(1,1,n,l[i],x[i]-1,x[i]);
		if(x[i]<r[i])modify(1,1,n,x[i]+1,r[i],x[i]);
	}
	getans(1,1,n);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}