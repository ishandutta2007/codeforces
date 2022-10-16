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
int n,m;
int par[1005],a[1005];
int t[1005],l[1005],r[1005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	par[find(x)]=find(y);
}
int main(){
	for(int i=0;i<=1000;i++)par[i]=i;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i]>>l[i]>>r[i];
		if(t[i]){
			for(int j=l[i];j<r[i];j++)unite(j,j+1);
		}
	}
	for(int i=1;i<=m;i++){
		if(!t[i]){
			if(find(l[i])==find(r[i])){
				puts("NO");return 0;
			}
		}
	}
	puts("YES");
	int now=1e9;
	for(int i=1;i<=n;i++){
		if(find(i-1)==find(i)){
			a[i]=now;
		}else{
			now--;a[i]=now;
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}