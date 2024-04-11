#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[32];
long long dp[32][1<<19];

int co(int x){
	int r=0;
	while(x!=0){
		r+=x&1;
		x>>=1;
	}
	return r;
}

long long calc(int v, int mask){
	if(dp[v][mask]!=-1)
		return dp[v][mask];
	int f=__builtin_ctz(mask),i,s,k=co(mask);
	dp[v][mask]=0;
	for(i=0;i<graph[v].size();++i){
		s=graph[v][i];
		if(s==f&&k>2){
			dp[v][mask]++;
			continue;
		}
		if(((mask>>s)&1)||s<f)continue;
		dp[v][mask]+=calc(s,mask|(1<<s));
	}
	return dp[v][mask];
}

int main(){
	int n,m,a,b;
	long long r=0;
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d",&a,&b);
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(a=0;a<n;++a){
		r+=calc(a,1<<a);
	}
	cout<<r/2<<endl;
	return 0;
}