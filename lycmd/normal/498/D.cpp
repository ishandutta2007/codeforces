#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define mid (((l)+(r))>>1)
using namespace std;
int const N=100010,T=N<<2,M=60;
typedef array<int,M> node;
int n,q,x,y,a[N];
char c;
node tr[T];
node operator+(const node&lhs,const node&rhs){
	node res;
	for(int i=0;i<M;i++)
		res[i]=lhs[i]+rhs[(i+lhs[i])%M];
	return res;
}
node init(int x){
	node res;
	for(int i=0;i<M;i++)
		res[i]=1+(i%x==0);
	return res;
}
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r)
		return tr[x]=init(a[l]),void();
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r)
		return tr[x]=init(k),void();
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr,int t){
	if(ql<=l&&r<=qr)
		return tr[x][t];
	int res=0;
	if(ql<=mid)
		res+=query(ls(x),l,mid,ql,qr,t);
	if(qr>mid)
		res+=query(rs(x),mid+1,r,ql,qr,(t+res)%M);
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(cin>>q;q--;){
		if(cin>>c>>x>>y,c<66)
			cout<<query(1,1,n,x,y-1,0)<<"\n";
		else
			modify(1,1,n,x,y);
	}
}