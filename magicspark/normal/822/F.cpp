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
vector<pair<int,int> >g[105];
void dfs(int x,int par=0,double pre=0){
	double res=2.0/(int)g[x].size();
	double cur=pre;
	for(auto p:g[x]){
		if(p.first!=par){
			printf("1 %d ",p.second);
			cur+=res;
			if(cur>2)cur-=2;
			if(cur<=1){
				printf("%d %d %.12lf\n",p.first,x,1.0-cur);
			}else{
				printf("%d %d %.12lf\n",x,p.first,2.0-cur);
			}
			double nxt;
			if(cur>=1){
				nxt=cur-1;
			}else{
				nxt=cur+1;
			}
			dfs(p.first,x,nxt);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}
	cout<<n-1<<endl;
	dfs(1);
	return 0;
}