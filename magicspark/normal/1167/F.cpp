#pragma optimize("Ofast")
#include<bits/stdc++.h>
#define N 500000 
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
char in[10000000];
int itr=0,llen=0;
char get(){
	if(itr==llen)llen=fread(in,1,10000000,stdin),itr=0;
	if(llen==0)return EOF;
	return in[itr++];
}
int getint(){
    int ret=0;char ch=get();
	while(ch<'0'||ch>'9'){
		if(ch=='-')return -getint();ch=get();
	}
	while ('0'<=ch&&ch<='9'){
		ret=ret*10-48+ch;
		ch=get();
	}
	return ret;
}
struct SegTree{
	#define SIZE 524288
	#define int long long
	struct node{
		ll f=0,add=0,sz;
	}f[SIZE<<1];
	int l,r,v;
	#define lson(x) (x<<1)
	#define rson(x) (x<<1|1)
	void pushdown(int k){
		f[lson(k)].add+=f[k].add;f[rson(k)].add+=f[k].add;f[k].add=0;
	}
	void build(int l=0,int r=SIZE-1,int k=1,int sz=SIZE){
		int mid=l+r>>1;
		f[k].sz=sz;
		if(l==r)return;
		build(l,mid,lson(k),sz>>1);
		build(mid+1,r,rson(k),sz>>1);
	}
	void _add(int l1=0,int r1=SIZE-1,int k=1){
		if(r<l1||r1<l)return;
		if(l<=l1&&r1<=r){
			f[k].add++;
			return;
		}
		int L=lson(k),R=rson(k);
		f[L].add+=f[k].add;f[R].add+=f[k].add;f[k].add=0;
		int mid=l1+r1>>1;
		_add(l1,mid,L);
		_add(mid+1,r1,R);
		f[k].f=f[L].f+f[R].f+f[L].add*f[L].sz+f[R].add*f[R].sz;
	}
	int _query(int l1=0,int r1=SIZE-1,int k=1){
		if(r<l1||r1<l)return 0;
		if(l<=l1&&r1<=r){
			return f[k].f+f[k].add*f[k].sz;
		}
		int L=lson(k),R=rson(k);
		f[L].add+=f[k].add;f[R].add+=f[k].add;f[k].add=0;
		int mid=l1+r1>>1;
		int vl=_query(l1,mid,L);
		int vr=_query(mid+1,r1,R);
		f[k].f=f[L].f+f[R].f+f[L].add*f[L].sz+f[R].add*f[R].sz;
		return vl+vr;
	}
	
	int query(int _l,int _r){
		l=_l;r=_r;return _query()%mod;
	}
	void add(int _l,int _r,int _v){
		l=_l;r=_r;v=1;_add();
	}
	#undef int
}seg1,seg2;
int n;
ll a[N+5],tmp1,tmp2,tmp3;
int main(){
	n=getint();seg1.build();seg2.build();
	for(int i=1;i<=n;i++)a[i]=1000000ll*getint()+i;
	sort(a+1,a+n+1);ll ans=0;
	for(int i=1;i<=n;i++){
		int pos=a[i]%1000000;ll v=a[i]/1000000;
		tmp1=seg1.query(pos,pos)*(n-pos)%mod;tmp2=seg2.query(pos,pos)*(pos-1)%mod;tmp3=pos;tmp3=tmp3*(n+1-pos)%mod;
		ans+=(seg1.query(pos+1,n)-tmp1)*(v*pos%mod);
		ans+=(seg2.query(1,pos-1)-tmp2)*(v*(n+1-pos)%mod);
		ans+=tmp3*v;
		seg1.add(pos,n,1);seg2.add(1,pos,1);
		ans%=mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}