#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,ans;
int a[222222],cnt[222222];
int mx1[222222],mx2[222222];
void solve(int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	solve(l,mid);solve(mid+1,r);
	vector<pair<int,int> >left,right;//mx,val
	mx1[mid+1]=-inf;mx2[mid]=-inf;
	for(int i=mid;i>=l;i--)mx1[i]=max(mx1[i+1],a[i]),left.push_back(make_pair(mx1[i],a[i]));
	for(int i=mid+1;i<=r;i++)mx2[i]=max(mx2[i-1],a[i]),right.push_back(make_pair(mx2[i],a[i]));
	int pos=0;
	for(auto p:left){
		int mx=p.first,v=p.second;
		//to find mx2[i]>mx,mx2[i]-a[i]==v
		while(pos!=right.size()&&right[pos].first<mx){
			cnt[right[pos].second]++;
			pos++;
		}
		ans+=cnt[mx-v];
	}
	for(int i=0;i<pos;i++)cnt[right[i].second]--;
	swap(left,right);pos=0;
	for(auto p:left){
		int mx=p.first,v=p.second;
		//to find mx2[i]>mx,mx2[i]-a[i]==v
		while(pos!=right.size()&&right[pos].first<mx){
			cnt[right[pos].second]++;
			pos++;
		}
		ans+=cnt[mx-v];
	}
	for(int i=0;i<pos;i++)cnt[right[i].second]--;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}