#include<bits/stdc++.h>
#define int long long
#define fib(i) ((i)<0?0:f[i])
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010,MOD=1000000000;
int n,q,a[N],f[N],s[N],tr1[N],tr2[N],lt[N];
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
int calc(int s1,int s2,int l){
	return l<0?s1:(s1*fib(l-1)%MOD+s2*fib(l)%MOD)%MOD;
}
void update(int x,int l,int r){
	int mid=(l+r)>>1;
	tr1[x]=(calc(tr1[rs(x)],tr2[rs(x)],mid-l)+tr1[ls(x)])%MOD;
	tr2[x]=(calc(tr1[rs(x)],tr2[rs(x)],mid-l+1)+tr2[ls(x)])%MOD;
}
void add(int x,int l,int r,int k){
	int len=r-l+1;
	add(lt[x],k);
	add(tr1[x],k*s[len-1]%MOD);
	add(tr2[x],k*(s[len]-1)%MOD);
}
void download(int x,int l,int r){
	int&t=lt[x],mid=(l+r)>>1;
	if(!t)
		return;
	add(ls(x),l,mid,t);
	add(rs(x),mid+1,r,t);
	t=0;
}
void build(int x,int l,int r){
	if(l==r)
		return add(x,l,r,a[l]);
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x,l,r);
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr)
		return add(x,l,r,k);
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,k);
	update(x,l,r);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return calc(tr1[x],tr2[x],l-ql-1);
	download(x,l,r);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		add(res,query(ls(x),l,mid,ql,qr));
	if(qr>mid)
		add(res,query(rs(x),mid+1,r,ql,qr));
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		f[i]=i<2?1:(f[i-1]+f[i-2])%MOD,s[i]=(f[i]+(i?s[i-1]:0))%MOD;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,l,r,k;
		switch(cin>>op>>l>>r,op){
			case 1:
				modify(1,1,n,l,l,r-query(1,1,n,l,l));break;
			case 2:
				cout<<query(1,1,n,l,r)<<"\n";break;
			case 3:
				cin>>k,modify(1,1,n,l,r,k);break;
		}
	}
}