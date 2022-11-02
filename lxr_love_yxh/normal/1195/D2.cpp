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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string a[100005];
int cnt[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i].size()]++;
	int ans=0;
	for(int i=1;i<=n;i++){
		const int my=a[i].size();
		for(int len=1;len<=10;len++){
			int add=0;
			if(my>=len){
				for(int t=0;t<=my-len;t++){
					add=add*10ll+a[i][t]-'0';
					add%=mod;
				}
				for(int t=my-len+1;t<a[i].size();t++){
					add=add*100ll+a[i][t]-'0';
					add%=mod;
				}
			}else{
				for(int t=max(0ll,my-len+1);t<a[i].size();t++){
					add=add*100ll+a[i][t]-'0';
					add%=mod;
				}
			}
			(ans+=add*10ll%mod*cnt[len]%mod)%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		const int my=a[i].size();
		for(int len=0;len<=10;len++){
			if(my>len){
				int add=0;
				for(int t=0;t<my-len;t++){
					add=add*10ll+a[i][t]-'0';
					add%=mod;
				}
				for(int t=my-len;t<a[i].size();t++){
					add=add*100ll+a[i][t]-'0';
					add%=mod;
				}
				(ans+=add*cnt[len]%mod)%=mod;
			}else{
				int add=0;
				for(int t=0;t<a[i].size();t++){
					add=add*100ll+a[i][t]-'0';
					add%=mod;
				}
				(ans+=add*cnt[len]%mod)%=mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}