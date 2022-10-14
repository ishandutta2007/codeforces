#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=4000010,K=1000000;
int n,m,q,a[N],b[N],cnt[N],tr[N],lt[N];
void update(int x){
	tr[x]=max(tr[ls(x)],tr[rs(x)]);
}
void add(int x,int k){
	tr[x]+=k,lt[x]+=k;
}
void download(int x){
	int&t=lt[x];
	if(!t)return;
	add(ls(x),t),add(rs(x),t),t=0;
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=cnt[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k);
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(int x,int l,int r){
	if(tr[x]<=0)return -1;
	if(l==r)return l;
	download(x);
	int mid=(l+r)>>1;
	return tr[rs(x)]>0?query(rs(x),mid+1,r):query(ls(x),l,mid);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=m;i++)
		cin>>b[i],cnt[b[i]]--;
	for(int i=K;i>=1;i--)
		cnt[i]+=cnt[i+1];
	build(1,1,K);
	for(cin>>q;q--;){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
			modify(1,1,K,1,a[x],-1),
			modify(1,1,K,1,a[x]=y,1);
		else
			modify(1,1,K,1,b[x],1),
			modify(1,1,K,1,b[x]=y,-1);
		cout<<query(1,1,K)<<"\n";
	}
}