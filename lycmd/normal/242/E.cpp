#include<bits/stdc++.h>
#define int long long 
using namespace std;
int const N=233333;
int n,q,a[N],b[N];
struct segmenttree{
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
	static int const N=400010;
	int tr[N],lt[N];
	void update(int x){
		tr[x]=tr[ls(x)]+tr[rs(x)];
	}
	void download(int x,int l,int r){
		int&t=lt[x],mid=(l+r)>>1;
		if(!t)return;
		tr[ls(x)]=mid-l+1-tr[ls(x)];
		tr[rs(x)]=r-mid-tr[rs(x)];
		lt[ls(x)]^=1,lt[rs(x)]^=1;
		t=0;
	}
	void build(int x,int l,int r){
		if(l==r){
			tr[x]=b[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls(x),l,mid);
		build(rs(x),mid+1,r);
		update(x);
	}
	void flip(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			tr[x]=r-l+1-tr[x],lt[x]^=1;
			return;
		}
		download(x,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid)flip(ls(x),l,mid,ql,qr);
		if(qr>mid)flip(rs(x),mid+1,r,ql,qr);
		update(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)
			return tr[x];
		download(x,l,r);
		int mid=(l+r)>>1,res=0;
		if(ql<=mid)res+=query(ls(x),l,mid,ql,qr);
		if(qr>mid)res+=query(rs(x),mid+1,r,ql,qr);
		return res;
	}
#undef ls
#undef rs
}tr[23];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<20;i++){
		for(int j=1;j<=n;j++)
			b[j]=a[j]>>i&1;
		tr[i].build(1,1,n);
	}
	cin>>q;
	while(q--){
		int op,l,r,x;
		cin>>op>>l>>r;
		if(op<2){
			int res=0;
			for(int i=0;i<20;i++)
				res+=tr[i].query(1,1,n,l,r)<<i;
			cout<<res<<"\n";
		}else{
			cin>>x;
			for(int i=0;i<20;i++)
				if(x>>i&1)
					tr[i].flip(1,1,n,l,r);
		}
	}
}