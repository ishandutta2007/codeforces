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
int n,k;
int a[200005];
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1]+k<<endl;
		return 0;
	}
	sort(a+1,a+n+1);a[n+1]=inf+inf;
	vector<pair<int,int> >dif;
	for(int i=n/2+2;i<=n+1;i++){
		dif.push_back(make_pair(a[i]-a[i-1],a[i-1]));
	}
	int mul=1;
	for(auto p:dif){
		int x=p.first,base=p.second;
//		cerr<<x<<" "<<k<<endl;
		if(k<=mul*x){
//			cerr<<x<<" "<<k<<" "<<mul<<endl;
			cout<<base+k/mul<<endl;
			return 0;
		}else{
			k-=mul*x;
		}
		mul++;
	}
	return 0;
}