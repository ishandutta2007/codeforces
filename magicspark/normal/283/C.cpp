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
int n,m,t;
int a[100005];
int dp[100005];
int to[100005],from[100005];
bool vis[100005];
vector<int>v;
inline void add(int &x,int y){
	(x+=y)%=mod; 
}
void dfs(int x,int p){
	vis[x]=true;
	if(!~to[x])return;
	if(to[x]==p){
		puts("0");
		exit(0);
	}
	dfs(to[x],p);
}
signed main(){
	memset(from,-1,sizeof from);
	memset(to,-1,sizeof to);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int t,s;
		cin>>t>>s;
		to[s]=t;
		from[t]=s; 
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,i);
	queue<pair<int,int> >q;//id,sum
	for(int i=1;i<=n;i++)if(!~to[i])q.push(make_pair(i,a[i]));
	while(!q.empty()){
		pair<int,int>p=q.front();q.pop();
		if(!~from[p.first]){
			continue;
		}
		t-=a[p.first];
		if(t<0){
			puts("0");
			exit(0);
		}
		to[from[p.first]]=-1;
		int _=from[p.first];
		q.push(make_pair(_,a[_]+p.second));
		a[_]+=p.second;
	}
	if(t<0){
		puts("0");
		return 0;
	}
//	for(int i=1;i<=n;i++)cerr<<i<<" "<<a[i]<<endl;
	dp[0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j+a[i]<=t;j++)add(dp[j+a[i]],dp[j]);
	cout<<dp[t]<<endl;
	return 0;
}