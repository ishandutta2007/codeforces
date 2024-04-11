#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,p,k;
int a[111111],b[111111];
pair<pair<int,int>,int>temp[111111];
set<int>ers;
priority_queue<pair<int,int> >q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>p>>k;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i],temp[i]=make_pair(make_pair(b[i],-a[i]),i);
	sort(temp,temp+n);
	for(int i=0;i<p-k;i++)ers.insert(temp[i].second);
	int pos=0;
	for(int i=0;i<n;i++)if(!ers.count(i))temp[pos++]=make_pair(make_pair(-a[i],-b[i]),i);
	sort(temp,temp+pos);
	set<int>ans;pair<int,int>small(inf,inf);
	for(int i=0;i<k;i++){
		ans.insert(temp[i].second);
		small=min(small,make_pair(-temp[i].first.second,temp[i].first.first));
	}
	pos=0;
	for(int i=0;i<n;i++)if(!ans.count(i))temp[pos++]=make_pair(make_pair(b[i],-a[i]),i);
	sort(temp,temp+pos);
	for(int i=pos-1;i>=0;i--){
		if(temp[i].first<=small){
			for(int j=i;j>i-(p-k);j--)ans.insert(temp[j].second);
			for(auto x:ans)cout<<x+1<<" ";cout<<endl;
			return 0;
		}
	}
	for(auto x:ans)cout<<x+1<<" ";cout<<endl;
	return 0;
}