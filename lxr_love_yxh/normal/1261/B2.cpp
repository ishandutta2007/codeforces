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
int n,m;
int a[200005];
pair<int,int>hop[200005];
int bit[200005];
void add(int x,int v){
	while(x<=200003){
		bit[x]+=v;
		x+=x&-x;
	}
}
int get(int x){
	int ret=0;
	while(x){
		ret+=bit[x];
		x-=x&-x;
	}
	return ret;
}
int cnt=0;
struct ask{
	int id,k,pos;
	void read(){
		cin>>k>>pos;
		id=++cnt;
	}
};
vector<ask>vec[200005];
int ans[200005];
void answer(ask A){
	int L=0,R=n+1;
	while(R-L>1){
		int mid=(L+R)/2;
		if(get(mid)<A.pos)L=mid;
		else R=mid;
	}
//	cerr<<R<<" "<<a[R]<<endl;
	ans[A.id]=a[R];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],hop[i]=make_pair(a[i],-i);
	sort(hop+1,hop+n+1);reverse(hop+1,hop+n+1);
	cin>>m;
	for(int i=1;i<=m;i++){
		ask tmp;tmp.read();
		vec[tmp.k].push_back(tmp);
	}
	int pos=1;
	for(int i=1;i<=n;i++){
		add(-hop[i].second,1);
		for(int j=0;j<vec[i].size();j++){
			answer(vec[i][j]);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}