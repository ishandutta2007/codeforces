#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k,a[222222],b[222222];
int v[222222];
inline bool check(int x){
	memset(v,0,sizeof(v));
	int cnt=0;
	for(int i=0;i<n;i++){
		ll sum=a[i];
		while(sum<(k-1)*b[i]){
			if(sum<0)return false;
			v[sum/b[i]+1]++;
			sum+=x;cnt++;//cerr<<x<<" "<<sum<<endl;
			if(cnt>=k)return false;
		}
	}
	ll ss=0;
	for(int i=1;i<=k;i++){
		ss=ss+v[i];
		if(ss>i)return false;
	}
	return true;
}
signed main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	ll l=-1,r=1e18;
	while(r-l>1){
		ll mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<(r==1e18?-1:r)<<endl;
	return 0;
}