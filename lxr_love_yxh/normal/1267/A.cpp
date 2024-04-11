/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int l[200005],r[200005],t[200005];
map<int,int>mp;
int inv[400005];
vector<pair<int,int> >el[400005],er[400005];
int rm[400005],Min[400005],Min_next[400005];
inline pair<int,int> calc(int y){
	int L=0,R=400005;
	while(R-L>1){
		int mid=(L+R)/2;
		if(inv[mid]<=y)L=mid;
		else R=mid;
	}
	return make_pair(L,y-inv[L]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(inv,inf,sizeof inv);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i]>>t[i];r[i]-=t[i];
		mp[l[i]];mp[r[i]];
	}
	int _=0;for(auto &p:mp)p.second=++_;
	for(auto p:mp)inv[p.second]=p.first;
	for(int i=1;i<=n;i++){
		el[mp[l[i]]].push_back(make_pair(t[i],i));
		er[mp[r[i]]].push_back(make_pair(t[i],i));
	}
	set<pair<int,int> >S;S.insert(make_pair(3e18,n+1));
	for(int i=_;i>=1;i--){
		rm[i]=S.begin()->first;
		for(int j=0;j<er[i].size();j++){
			S.insert(er[i][j]);
		}
		Min[i]=S.begin()->first;
		for(int j=0;j<el[i].size();j++){
			S.erase(el[i][j]);
		}
	}
	Min_next[_]=3e18;
	for(int i=_-1;i>=1;i--){
		Min_next[i]=min(Min[i+1]+inv[i+1],Min_next[i+1]);
	}
	#ifdef LOCAL
	cerr<<_<<endl;
	for(int i=1;i<=_;i++){
		cerr<<inv[i]<<" "<<Min[i]<<" "<<Min_next[i]<<endl;
	}
	#endif
	int now=1,exceed=0,cnt=0;
	while(1){
		while(now<_&&inv[now]+exceed>=inv[now+1])now++,exceed-=inv[now]-inv[now-1];
		if(now>=_){
			cout<<cnt+(exceed==0)<<endl;
			return 0;
		}
		int x=(exceed==0?Min[now]:rm[now]),y=Min_next[now];
//		cerr<<now<<" "<<exceed<<" "<<cnt<<" "<<inv[now]+exceed+x<<" "<<y<<endl;
		if(inv[now]+exceed+x<y){
			int tmp=inv[now+1]-inv[now]-exceed;
			int times=max(tmp/x,1ll);if(exceed==0)times=1;cnt+=times;
			exceed+=times*x;
		}else{
			tie(now,exceed)=calc(y);cnt++;
//			cerr<<now<<" "<<exceed<<endl; 
		}
	}
	return 0;
}