#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct SegTree{
	#define SIZE 65536
	ll f[SIZE<<1]={},lazy[SIZE<<1]={};
	SegTree(){}
	void set(int pos,int v){
		pos+=SIZE-1; 
		f[pos]=v;
		while(pos){
			pos=pos-1>>1;
			f[pos]=max(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	ll query(int l,int r,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r)return f[k]+lazy[k];
		if(r<l1||r1<l)return (ll)-1e18;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		ll vl=query(l,r,l1,mid,k+k+1);
		ll vr=query(l,r,mid+1,r1,k+k+2);
		f[k]=max(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return max(vl,vr);
	}
	void addrange(int l,int r,int v,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r){
			lazy[k]+=v;
			return;
		}
		if(l1>r||r1<l)return;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		addrange(l,r,v,l1,mid,k+k+1);
		addrange(l,r,v,mid+1,r1,k+k+2);
		f[k]=max(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return;
	}
}dp[52];
int n,k;
int a[44444];
int pre[44444];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;memset(pre,-1,sizeof pre);
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0].set(0,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)dp[j].addrange(pre[a[i]],i-1,1);
		pre[a[i]]=i;
//		cerr<<dp[0].query(0,0)<<endl;
		for(int j=1;j<=k;j++)dp[j].set(i,dp[j-1].query(0,i-1));
//		for(int j=1;j<=k;j++){cerr<<i<<" "<<j<<" "<<dp[j].query(i,i)<<endl;}
	}
	cout<<dp[k].query(n,n)<<endl;
	return 0;
}