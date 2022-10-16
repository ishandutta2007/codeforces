/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
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
int cnt[6],v[1<<6],mask[100005];
string s,ans;
bool can(int x){
	cnt[x]--;
	for(int i=0;i<(1<<6);i++){
		int sum=0,van=0;
		for(int j=0;j<6;j++)if(i&(1<<j))van+=cnt[j];
		for(int j=0;j<(1<<6);j++)if(i&j){
			sum+=v[j];
		}
		if(sum<van){
//			cerr<<x<<" "<<i<<" "<<v[(1<<6)-1]<<" "<<cnt[x]<<endl;
			cnt[x]++;
			return false;
		}
	}
	cnt[x]++;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;n=s.size();
	for(char c:s)cnt[c-'a']++;
	s=" "+s;
	int m;cin>>m;
	for(int i=1;i<=n;i++)mask[i]=(1<<6)-1;
	while(m--){
		int pos;string st;
		cin>>pos>>st;
		int msk=0;
		for(char c:st)msk|=(1<<(c-'a'));
		mask[pos]=msk;
	}
	for(int i=1;i<=n;i++)v[mask[i]]++;
	for(int i=1;i<=n;i++){
		v[mask[i]]--;
		for(int j=0;j<6;j++){
			if((mask[i]&(1<<j))&&cnt[j]&&can(j)){
				cnt[j]--;
				ans.push_back('a'+j);
				break;
			}
			if(j==5){
				puts("Impossible");
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}