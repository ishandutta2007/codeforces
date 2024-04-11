#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=140010,K=55,INF=0x3f3f3f3f;
int n,k,a[N],f[K][N],tr[N],lt[N],pre[N];
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
void build(int x,int l,int r,int i){
	lt[x]=0;
	if(l==r){
		tr[x]=f[i-1][l-1];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid,i);
	build(rs(x),mid+1,r,i);
	update(x);
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k);
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res=max(res,query(ls(x),l,mid,ql,qr));
	if(qr>mid)
		res=max(res,query(rs(x),mid+1,r,ql,qr));
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++){
		build(1,1,n,i);
		memset(pre,0,sizeof pre);
		for(int j=1;j<=n;j++){
			modify(1,1,n,pre[a[j]]+1,j,1);
			f[i][j]=query(1,1,n,1,j);
			pre[a[j]]=j;
		}
	}
	cout<<f[k][n]<<"\n";
}