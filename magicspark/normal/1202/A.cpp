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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T,k;
string s,t;
int main(){
	cin>>T;
	while(T--){
		cin>>s;cin>>t;
		reverse(s.begin(),s.end());
		reverse(t.begin(),t.end());
		int F=0;
		for(int i=0;i<t.size();i++){
			if(t[i]=='1'){
				F=i;break;
			}
		}
		int ans=s.size();
		for(int j=F;j<s.size();j++){
			if(s[j]=='1'){
				ans=j-F;break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}