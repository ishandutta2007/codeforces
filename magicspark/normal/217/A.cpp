/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
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
int n;
int x[1005],y[1005];
int par[2005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	par[find(x)]=find(y);
}
int main(){
	cin>>n;
	for(int i=0;i<2005;i++)par[i]=i;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		unite(x[i],y[i]+1002);
	}
	set<int>S;
	for(int i=1;i<=n;i++){
		S.insert(find(x[i]));
		S.insert(find(y[i]+1002));
	}
	cout<<(int)S.size()-1<<endl;
	return 0;
}