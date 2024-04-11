#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010,MOD=998244353;
int n,ans,a[N],tr[N],ltc[N],ltm[N],lta[N];
vector<int>b;
void update(int x){
	tr[x]=(tr[ls(x)]+tr[rs(x)])%MOD;
}
void download(int x,int l,int r){
	int&tc=ltc[x],&tm=ltm[x],&ta=lta[x],mid=(l+r)>>1;
	if(~tc){
		int&tc=ltc[x];
		tr[ls(x)]=tr[rs(x)]=tc;
		ltc[ls(x)]=ltc[rs(x)]=0;
		ltm[ls(x)]=ltm[rs(x)]=1;
		lta[ls(x)]=lta[rs(x)]=0;
		tc=-1;
	}
	tr[ls(x)]=(tr[ls(x)]*tm%MOD+MOD)%MOD;
	tr[rs(x)]=(tr[rs(x)]*tm%MOD+MOD)%MOD;
	lta[ls(x)]=(lta[ls(x)]*tm%MOD+MOD)%MOD;
	lta[rs(x)]=(lta[rs(x)]*tm%MOD+MOD)%MOD;
	ltm[ls(x)]=(ltm[ls(x)]*tm%MOD+MOD)%MOD;
	ltm[rs(x)]=(ltm[rs(x)]*tm%MOD+MOD)%MOD;
	tr[ls(x)]=(tr[ls(x)]+(b[mid]-b[l-1])*ta%MOD+MOD)%MOD;
	tr[rs(x)]=(tr[rs(x)]+(b[r]-b[mid])*ta%MOD+MOD)%MOD;
	lta[ls(x)]=(lta[ls(x)]+ta)%MOD;
	lta[rs(x)]=(lta[rs(x)]+ta)%MOD;
	tm=1,ta=0;
}
void build(int x,int l,int r){
	ltc[x]=-1,ltm[x]=1;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void cover(int x,int l,int r,int ql,int qr,int k){
	if(ql>qr)
		return;
	if(ql<=l&&r<=qr){
		tr[x]=ltc[x]=k;
		ltm[x]=1,lta[x]=0;
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)
		cover(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		cover(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
void modifymul(int x,int l,int r,int ql,int qr,int k){
	if(ql>qr)
		return;
	if(ql<=l&&r<=qr){
		tr[x]=(tr[x]*k%MOD+MOD)%MOD;
		ltm[x]=(ltm[x]*k%MOD+MOD)%MOD;
		lta[x]=(lta[x]*k%MOD+MOD)%MOD;
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modifymul(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modifymul(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
void modifyadd(int x,int l,int r,int ql,int qr,int k){
	if(ql>qr)
		return;
	if(ql<=l&&r<=qr){
		tr[x]=(tr[x]+(b[r]-b[l-1])*k%MOD)%MOD;
		lta[x]=(lta[x]+k)%MOD;
		return; 
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modifyadd(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modifyadd(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql>qr)
		return 0;
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x,l,r);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res=(res+query(ls(x),l,mid,ql,qr))%MOD;
	if(qr>mid)
		res=(res+query(rs(x),mid+1,r,ql,qr))%MOD;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,b.push_back(0);
	for(int i=1;i<=n;i++)
		cin>>a[i],b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end()); 
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
	int m=b.size()-1;
	build(1,1,m);
	modifyadd(1,1,m,1,a[1],1);
	for(int i=2;i<=n;i++){
		int s=query(1,1,m,1,a[i-1]);
		cover(1,1,m,a[i]+1,m,0);
		modifymul(1,1,m,1,a[i],-1);
		modifyadd(1,1,m,1,a[i],s);
	}
	cout<<query(1,1,m,1,a[n])<<"\n";
}