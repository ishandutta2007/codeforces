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
pair<int,int> sum[100005];
signed main(){
	int sx,sy,tx,ty,n;string s;
	cin>>sx>>sy>>tx>>ty;cin>>n;cin>>s;
	sum[0].first=sum[0].second=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i-1]=='R')sum[i].first++;
		if(s[i-1]=='L')sum[i].first--;
		if(s[i-1]=='U')sum[i].second++;
		if(s[i-1]=='D')sum[i].second--;
	}
	long long l=-1,r=2e18;
	while(r-l>1){
		long long mid=l+r>>1;
		if(mid>=
		abs(tx-(mid/n*sum[n].first+sum[mid%n].first+sx))+
		abs(ty-(mid/n*sum[n].second+sum[mid%n].second+sy))
		)r=mid;
		else l=mid;
	}
	if(r==2e18)puts("-1");
	else cout<<r<<endl;
	return 0;
}