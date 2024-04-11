#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
vector<pair<int,int> >poly;
int n;
int a[22],Inv[23333];
vector<pair<int,int> >mul(vector<pair<int,int> >a,vector<pair<int,int> >b){
	vector<pair<int,int> >ret;
	for(auto p:a)for(auto q:b){
		ret.push_back(make_pair(p.first+q.first,(p.second*q.second)%mod));
	}
	return ret;
}
inline int inv(int x){
	return Inv[x];
}
int C(int x,int y){
	int ret=1;
	for(int i=1;i<=y;i++)(ret*=((x-y+i)%mod))%=mod;
	for(int i=1;i<=y;i++)(ret*=inv(i))%=mod;
	return ret;
}
int van(int x){
	return C(n+x-1,n-1);
}
map<int,int>mp;//power->v
int S;
signed main(){
	poly.push_back(make_pair(0,1));
	cin>>n>>S;
	for(int i=1;i<23333;i++)Inv[i]=modpow(i,mod-2,mod);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		poly=mul(poly,(vector<pair<int,int> >){make_pair(0,1),make_pair(a[i]+1,-1)});
	}
	for(auto p:poly)mp[p.first]+=p.second;
	ll ans=0;
	for(auto p:mp){
		int pw=p.first,v=p.second%mod;
		if(pw<=S){
			(ans+=van(S-pw)*v)%=mod;
			(ans+=mod)%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}