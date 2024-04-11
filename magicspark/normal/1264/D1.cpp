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
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;int n;
int pref[2005][3],C[2005][2005];
int get_sum(int l,int r,int id){
	return pref[r][id]-pref[l-1][id];
}
int main(){
	cin>>s;n=s.size();s=" "+s;
	for(int i=1;i<=n;i++){
		pref[i][0]=pref[i-1][0]+(s[i]=='(');
		pref[i][1]=pref[i-1][1]+(s[i]==')');
		pref[i][2]=pref[i-1][2]+(s[i]=='?');
	}
	for(int i=0;i<=2000;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod)C[i][j]-=mod;
		} 
	}
	int sum=0;
	for(int R=pref[n][1];R<=pref[n][1]+pref[n][2];R++){
		//split between R-1 and R
		for(int ans=min(get_sum(1,R,0),get_sum(R+1,n,1));ans<=min(get_sum(1,R,0)+get_sum(1,R,2),get_sum(R+1,n,1)+get_sum(R+1,n,2));ans++){
			int left_all=get_sum(1,R,2),left_choose=ans-get_sum(1,R,0);
			int right_all=get_sum(R+1,n,2),right_choose=ans-get_sum(R+1,n,1);
//			cerr<<R<<" "<<ans<<" "<<C[left_all][left_choose]*C[right_all][right_choose]<<endl;
			(sum+=(ll)C[left_all][left_choose]*C[right_all][right_choose]%mod*ans%mod)%=mod;
		}
	}
	cout<<sum<<endl;
	return 0;
}