#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
struct SegTree{
	#define SIZE (1<<17)
	int opr[SIZE*4]={},f[SIZE*4]={};//opr=1 -> xor opr=0 ->or
	inline int func(int x,int y){return opr[x]==1?f[x]^f[y]:f[x]|f[y];}
	void build(int l,int r,int k){
		if(l==r){
			opr[k]=0;
			return;
		}
		int mid=l+r>>1;
		build(l,mid,k+k+1);
		build(mid+1,r,k+k+2);
		opr[k]=1^opr[k+k+1];
	}
	void upd(int x,int pos){
		pos+=((1<<n)-1);
		f[pos]=x;
		while(pos){
			pos=(pos-1)>>1;
			f[pos]=func(pos+pos+1,pos+pos+2);
		}
	}
}data;
int a[(int)(1<<17)+5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;data.build(0,(1<<n)-1,0);
	for(int i=0;i<(1<<n);i++){
		cin>>a[i];
		data.upd(a[i],i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;x--;
		data.upd(y,x);
		cout<<data.f[0]<<endl;
	}
	return 0;
}