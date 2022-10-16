#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
bool path[15][15][1<<14];
int dp[1<<14];
struct state{
	int x,y,mask;
}last[1<<14];
int lastv[15][15][1<<14];
int n,m;
vector<int>g[15];
void get_path(){
	for(int i=0;i<n;i++)for(auto to:g[i])path[i][to][0]=1,lastv[i][to][0]=i;
	for(int mask=0;mask<(1<<n);mask++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(mask&(1<<j))continue;
				if(mask&(1<<i))continue;
				if(i==j)continue;
				if(path[i][j][mask]==0)continue;
				for(auto to:g[j]){
					if(mask&(1<<to))continue;
					if(to==lastv[i][j][mask])continue;
					if(path[i][to][mask|(1<<j)])continue;
					path[i][to][mask|(1<<j)]=1;
					lastv[i][to][mask|(1<<j)]=j;
				}
			}
}
void get_dp(){
	memset(dp,inf,sizeof dp);dp[1]=0;
	for(int mask=0;mask<(1<<n);mask++)
		for(int submask=mask;submask;submask=submask-1&mask){
			int premask=submask^mask;
			int cost=__builtin_popcount(submask)+1;
			if(dp[premask]+cost>=dp[mask])continue;
			for(int x=0;x<n;x++)
				for(int y=0;y<n;y++){
					if(((1<<x)&premask)==0)continue;
					if(((1<<y)&premask)==0)continue;
					if(path[x][y][submask]){
						dp[mask]=dp[premask]+cost;
						last[mask]=(state){x,y,submask};
					}
				}
		}
}
void sjctxdy(int x,int &y,int mask){
	while(mask){
		int tmp=lastv[x][y][mask];
		cout<<tmp+1<<" "<<y+1<<endl;
		mask^=(1<<tmp);y=tmp;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	get_path();
	get_dp();
	cout<<dp[(1<<n)-1]<<endl;
	int mask=(1<<n)-1;
	while(mask!=1){
		int pre=last[mask].mask,x=last[mask].x,y=last[mask].y;
		mask^=pre;//cerr<<mask<<" "<<pre<<endl;
		sjctxdy(x,y,pre);
		cout<<x+1<<" "<<y+1<<endl;
	}
	return 0;
}