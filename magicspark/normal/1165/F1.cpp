#include<bits/stdc++.h>
#define maxn 200005
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int need[maxn],rest[maxn];
pair<int,int>one[maxn];//<day,type>
set<int>have;
int get(int limit,int Max){
	if(Max==0)return 0;
	auto itr=have.upper_bound(limit);
	if(itr==have.begin())return 0;
	int ret=0;itr--;
	while(itr!=have.begin()){
		have.erase(itr--);ret++;if(ret==Max)return ret;
	}
	ret++;have.erase(have.begin());
	return ret;
}
bool check(int day){
	for(int i=1;i<=n;i++)rest[i]=need[i];
	int cost=0;
	have.clear();
	for(int i=1;i<=day;i++)have.insert(i);
	vector<pair<int,int> >ones;
	vector<int>latest(4e5+10,-inf);
	for(int i=1;i<=m;i++){
		int Day=one[i].first,pos=one[i].second;
		if(Day<=day)latest[pos]=max(latest[pos],Day);
	}
	for(int i=1;i<=n;i++)if(latest[i]!=-inf)ones.push_back(make_pair(latest[i],i));
	for(int i=0;i<ones.size();i++){
		int Day=ones[i].first,pos=ones[i].second;
		if(Day<=day){
			int can_get=get(Day,rest[pos]);
			cost+=can_get;rest[pos]-=can_get;
		}
	}
	for(int i=1;i<=n;i++)cost+=rest[i]*2;
	return cost<=day;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>need[i];
	for(int i=1;i<=m;i++){
		cin>>one[i].first>>one[i].second;
	}
	int l=-1,r=maxn+maxn+5;
	while(r-l>1){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	return 0;
}