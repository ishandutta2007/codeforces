/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n;
int a[100005];
string s;
char ans[100005];
ll get(int l,int r){
	ll ret=1;
	for(int i=l;i<=r;i++){
		ret*=a[i];
		ret=min(ret,(ll)1e15);
	}
	return ret;
}
vector<pair<int,int> >range;
vector<int>vals;
ll calc(int l,int r){
	ll ret=1;
	for(int i=l;i<=r;i++){
		ret*=vals[i];
	}
	return ret;
}
ll dp[5555],pre[5555];
void gao(int l,int r){
	if(l>r)return;
	range.clear();
	vals.clear();
	int lst=l;
	for(int i=l;i<=r;i++){
		if(a[i]==1){
			if(lst<=i-1)range.push_back(make_pair(lst,i-1)),vals.push_back(get(lst,i-1));
			lst=i+1;
		}
	}
	if(lst<=r)range.push_back(make_pair(lst,r)),vals.push_back(get(lst,r));
	__int128 cur=1;
	for(auto p:range){
		cur*=get(p.first,p.second);
		cur=min(cur,(__int128)1e15);
	}
	cerr<<(int)cur<<endl;
	if(cur>n){
		while(l<r&&a[l]==1){
			ans[l]='+';l++;
		}
		while(r>l&&a[r]==1){
			r--;ans[r]='+'; 
		}
		for(int i=l;i<r;i++){
			ans[i]='*';
		}
		return;
	}
	if(!range.size()){
		for(int i=l;i<r;i++){
			ans[i]='+';
		}
		return;
	}
	memset(dp,0xf7,sizeof dp);
	memset(pre,0,sizeof pre);
	dp[0]=0;
	for(int i=1;i<=range.size();i++){
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],dp[j]+calc(j,i-1)+(i==range.size()?0:range[i].first-range[i-1].second-1));
			if(dp[i]==dp[j]+calc(j,i-1)+(i==range.size()?0:range[i].first-range[i-1].second-1)){
				pre[i]=j;
			}
		}
		cerr<<i<<" "<<dp[i]<<endl;
	}
	for(int i=l;i<r;i++)ans[i]='+'; 
	int pos=range.size();
	while(pos!=0){
		for(int i=range[pre[pos]].first;i<range[pos-1].second;i++){
			ans[i]='*';
		}
		pos=pre[pos];
	}
}
void solve(){
	int lst=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			gao(lst,i-1);
			ans[i-1]=ans[i]='+';
			lst=i+1;
		}
	}
	gao(lst,n);
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)cout<<ans[i];
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>s;
	if(s.size()==1){
		for(int i=1;i<=n;i++){
			cout<<a[i];
			if(i<n)cout<<s;
		}
		return 0;
	}
	if(s.size()==3){
		solve();
		return 0;
	}
	if(s.size()==2&&s.find('-')==string::npos){
		solve();
		return 0;
	}
	if(s.size()==2&&s.find('*')==string::npos){
		for(int i=1;i<=n;i++){
			cout<<a[i];
			if(i<n)cout<<'+';
		}
		return 0;
	}
	char c='*';
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i==n)break;
		if(a[i+1]==0)putchar('-');
		else putchar('*');
	}
	return 0;
}