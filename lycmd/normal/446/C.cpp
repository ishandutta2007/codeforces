#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1) 
using namespace std;
int const N=1200010,MOD=1000000009;
int n,q,a[N],tr[N],lt1[N],lt2[N],f[N];
void update(int x){
	tr[x]=(tr[ls(x)]+tr[rs(x)])%MOD;
}
void add(int&x,int y){
	if((x+=y%MOD)>=MOD)x-=MOD;
}
void download(int x,int l,int r){
	int&t1=lt1[x],&t2=lt2[x],mid=(l+r)>>1,d=mid-l+1,k=r-l+1;
	if(!t1&&!t2)return;
	add(lt1[ls(x)],t1);
	add(lt2[ls(x)],t2);
	add(tr[ls(x)],t1*f[d]+t2*(f[d+1]-1));
	add(lt1[rs(x)],t1*f[d-1]+t2*f[d]);
	add(lt2[rs(x)],t1*f[d]+t2*f[d+1]);
	add(tr[rs(x)],t1*(f[k]-f[d]+MOD)+t2*(f[k+1]-f[d+1]+MOD));
	t1=t2=0;
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		int d=l-ql+1,k=r-l+1;
		add(lt1[x],f[d]);
		add(lt2[x],f[d+1]);
		add(tr[x],f[d]*f[k]+(f[k+1]-1)*f[d+1]);
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x,l,r);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)add(res,query(ls(x),l,mid,ql,qr));
	if(qr>mid)add(res,query(rs(x),mid+1,r,ql,qr));
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		f[i]=i<3?1:(f[i-1]+f[i-2])%MOD;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op<2){
			modify(1,1,n,l,r);
		}else{
			cout<<query(1,1,n,l,r)<<"\n";
		}
	}
}