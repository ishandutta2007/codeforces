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
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int q,mul=1,ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	stack<int>stk;
	cin>>q;
	stk.push(1);
	while(q--){
		string s;cin>>s;
		if(s[0]=='f'){
			int t;
			cin>>t;
			if(mul*t>(1ll<<32)-1 || stk.top()==-1){
				stk.push(-1);
			}else{
				stk.push(t);
				mul*=t;
			}
		}else if(s[0]=='a'){
			if(mul+ans>(1ll<<32)-1 || stk.top()==-1){
				puts("OVERFLOW!!!");
				return 0;
			}
			ans+=mul;
		}else{
			if(stk.top()!=-1)mul/=stk.top();
			stk.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}