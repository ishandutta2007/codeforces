#include<bits/stdc++.h>
#pragma optimize("Ofast")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int cnt[500005];
int a[500005],b[500005];
vector<int>g[500005];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]=i;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[b[y]].push_back(b[x]);
	}
	for(auto x:g[n])cnt[x]++;
	int ans=0;
	for(int i=n-1;i>0;i--){
		if(cnt[i]==n-i-ans)ans++;
		else for(auto x:g[i])cnt[x]++;
	}
	cout<<ans<<endl;
	return 0;
}