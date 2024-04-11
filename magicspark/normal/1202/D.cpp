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
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int t;
void solve(int x){
	int rest=x;putchar('1');
	vector<int>vec;
	for(int i=1e5;i>=1;i--){
		while(rest>=i*(i+1)/2ll){
			vec.push_back(i+1);rest-=i*(i+1)/2ll;
		}
	}
	vec.push_back(0);
	sort(vec.begin(),vec.end());
	for(int i=1;i<vec.size();i++){
		for(int j=0;j<vec[i]-vec[i-1];j++)putchar('3');
		putchar('7');
	}
	putchar('\n');
}
signed main(){
	cin>>t;
	while(t--){
		int n;cin>>n;
		solve(n);
	}
	return 0;
}