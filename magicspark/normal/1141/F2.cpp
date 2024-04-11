#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
map<int,vector<pair<int,int> > >mp;
int sum[1511],a[1511],n;
inline pair<int,vector<pair<int,int> > > calc(vector<pair<int,int> >v){
	deque<pair<int,int> >q;
	for(auto x:v)q.push_back(x);
	int pre=-inf,ret=0;vector<pair<int,int> >ret2;
	while(q.size()){
		pair<int,int>p=q.front();
		if(p.first>pre){
			pre=p.second;
			ret++;ret2.push_back(p);
		}else if(p.second<pre){
			ret2.pop_back();
			ret2.push_back(p);
			pre=p.second;
		}q.pop_front();
	}
	return make_pair(ret,ret2);
}
int main(){
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)mp[sum[r]-sum[l-1]].push_back(make_pair(l,r));
	pair<int,vector<pair<int,int> > >ans;ans.first=0;
	for(auto x:mp){
		vector<pair<int,int> >v=x.second;
		ans=max(ans,calc(v));
	}
	cout<<ans.first<<endl;
	for(auto [l,r]:ans.second)cout<<l<<" "<<r<<endl;
	return 0;
}