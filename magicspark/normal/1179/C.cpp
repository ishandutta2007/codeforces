//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct SegTree{
	#define SIZE 1048576
	ll f[SIZE<<1]={},lazy[SIZE<<1]={};
	inline int func(int x,int y){return x<y?x:y;}
	void set(int pos,ll v){
		pos+=SIZE-1; 
		f[pos]=v;
		while(pos){
			pos=pos-1>>1;
			f[pos]=func(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	void add(int l,int r,int v,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r){
			lazy[k]+=v;
			return;
		}
		if(l1>r||r1<l)return;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		add(l,r,v,l1,mid,k+k+1);
		add(l,r,v,mid+1,r1,k+k+2);
		f[k]=func(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return;
	}
	int search(int l=0,int r=SIZE-1,int k=0){
		if(l==r){
			if(f[k]+lazy[k]<0)return l;
			else return -1;
		}
		int mid=l+r>>1;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		f[k]=func(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		if(f[k+k+2]+lazy[k+k+2]<0)return search((l+r>>1)+1,r,k+k+2);
		else return search(l,l+r>>1,k+k+1);
	}
}data;
int n,m;
int a[300005];
int b[300005];
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		data.add(1,a[i],-1);
	}
	for(int i=1;i<=m;i++){
		scanf("%I64d",&b[i]);
		data.add(1,b[i],1);
	}
	int q;
	scanf("%I64d",&q);
	while(q--){
		int type,i,v;
		scanf("%I64d%I64d%I64d",&type,&i,&v);
		if(type==1){
			data.add(1,a[i],1);
			a[i]=v;
			data.add(1,a[i],-1);
		}else{
			data.add(1,b[i],-1);
			b[i]=v; 
			data.add(1,b[i],1);
		}
		cout<<data.search()<<endl;
	}
	return 0;
}