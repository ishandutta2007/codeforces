#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int f[300005][3];
int c[300005],pr[300005];
int n;
vector<int>g[300005];
void dfs(int x,int par=0){pr[x]=par;f[x][c[x]]++;for(auto to:g[x])if(to!=par)dfs(to,x),f[x][0]+=f[to][0],f[x][1]+=f[to][1],f[x][2]+=f[to][2];}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(auto to:g[i]){
			if(pr[to]==i&&((f[to][1]==0&&f[1][2]==f[to][2])||(f[to][2]==0&&f[1][1]==f[to][1])))ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}