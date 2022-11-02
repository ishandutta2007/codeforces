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
int n,a,b;
string s;
bool used[200005];
int main(){
	cin>>n>>a>>b;
	cin>>s;
	vector<int>hv;
	for(int i=0;i<n;i++){
		if(used[i])continue;
		if(s[i]=='*')continue;
		int cnt=0;
		for(int j=i;j<n;j++){
			if(s[j]=='*'){
				break;
			}else{
				used[j]=1;cnt++;
			}
		}
		hv.push_back(cnt);
	}
	int sum=a+b;
	for(auto x:hv){
		a-=x/2;
		b-=x/2;
		if(x%2==0)continue;
		if(a>b)a--;
		else b--;
	}
	cout<<sum-max(0,a)-max(0,b)<<endl;
	return 0;
}