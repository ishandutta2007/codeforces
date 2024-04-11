#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int pc(LL x){
	int ans=0;
	for(;x;x&=x-1)ans++;
	return ans;
}

struct Cmp{
	bool operator()(LL a,LL b){
		return pc(a)!=pc(b)?pc(a)<pc(b):a>b;
	}
};

const int N=100;
LL l,r;
bool vis[N][2][2];
LL dp[N][2][2];
LL f(int x,int lb,int rb){
	bool &v=vis[x][lb][rb];
	LL &ans=dp[x][lb][rb];
	if(v)return ans;
	if(x<0)return 0;
	v=true;
	ans=-1;
	int lw=lb?(l>>x)&1:0;
	int rw=rb?(r>>x)&1:1;
	for(LL i=lw;i<=rw;i++){
		LL tans=(i<<x)|f(x-1,lb&&(i==lw),rb&&(i==rw));
		if(ans==-1)ans=tans;
		else ans=max(ans,tans,Cmp());
	}
	// cerr<<x<<" "<<lb<<" "<<rb<<" "<<ans<<endl;
	assert(ans!=-1);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		cin>>l>>r;
		memset(vis,false,sizeof(vis));
		cout<<f(62,1,1)<<endl;
	}
	return 0;
}