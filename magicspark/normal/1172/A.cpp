//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,posone;
int a[200005],b[200005],pos[200005],one=-1;
bool ok(int _pos){
	for(int i=1;i<=n;i++){
		if(pos[i]-_pos>=i)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];pos[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];pos[b[i]]=i;if(b[i]==1)one=i;
	}
	if(one!=-1){
		for(int j=one+1;j<=n;j++){
			if(b[j]!=b[j-1]+1){
				one=-1;
				break;
			}
		}
	}
	if(one!=-1){
		int need=n+1-one;
		for(int i=need+1;i<=n;i++){
			if(pos[i]>=i-need){
				one=-1;
			}
		}
		if(one!=-1){
			cout<<n-need<<endl;
			return 0;
		}
	}
	int l=-1,r=n+1;
	while(r-l>1){
		int mid=l+r>>1;
		if(ok(mid))r=mid;
		else l=mid;
	}
	cout<<n+r<<endl;
	return 0;
}