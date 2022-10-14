#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=1500010;
int n,q,a[N],tr[N],mx[N],pre[N],d[N];
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
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=query(ls(x),l,mid,ql,qr);
	if(qr>mid)res+=query(rs(x),mid+1,r,ql,qr);
	return res;
}
void modify(int x,int l,int r,int ql,int qr){
	if(mx[x]<3)return;
	if(l==r){
		tr[x]=mx[x]=d[tr[x]];
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		pre[i]=i;
	for(int i=2;i<N;i++)
		if(pre[i]==i)
			for(int j=i*i;j<N;j+=i)
				pre[j]=i;
	for(int i=1;i<N;i++){
		int t=i;d[i]=1;
		while(t>1){
			int tc=1,k=pre[t];
			while(t%k==0)tc++,t/=k;
			d[i]*=tc;
		}
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op<2)
			modify(1,1,n,l,r);
		else
			cout<<query(1,1,n,l,r)<<"\n";
	}
}