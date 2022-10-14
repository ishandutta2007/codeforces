#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=55,M=200010;
int n,m,k,w,ans,a[N][M],s[N][M],f[N][M],tr[M],lt[M];
int sum(int x,int l,int r){
	return s[x][r]-s[x][l-1];
}
void update(int x){
	tr[x]=max(tr[ls(x)],tr[rs(x)]);
}
void add(int x,int k){
	tr[x]+=k,lt[x]+=k;
}
void download(int x){
	int&t=lt[x];
	if(!t)
		return;
	add(ls(x),t),add(rs(x),t),t=0;
}
void build(int x,int l,int r,int i){
	if(l==r){
		tr[x]=f[i][l]+sum(i+1,l,l+k-1);
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid,i);
	build(rs(x),mid+1,r,i);
	update(x);
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql>qr)
		return;
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
void upd(int i,int x,int flg){
	modify(1,1,w,max(x-k+1,1),min(x,w),a[i][x]*flg);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k,w=m-k+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],s[i][j]=s[i][j-1]+a[i][j];
	for(int j=1;j<=w;j++)
		f[1][j]=sum(1,j,j+k-1);
	for(int i=2;i<=n;i++){
		memset(tr,0,sizeof tr);
		memset(lt,0,sizeof lt);
		build(1,1,w,i-1);
		for(int j=1;j<k;j++)
			upd(i,j,-1);
		for(int j=1;j<=w;j++)
			upd(i,j-1,1),upd(i,j+k-1,-1),f[i][j]=sum(i,j,j+k-1)+tr[1];
	}
	for(int j=1;j<=w;j++)
		ans=max(ans,f[n][j]);
	cout<<ans<<"\n";
}