#include<bits/stdc++.h>
#define int long long
#define cnt first
#define ans second
using namespace std;
typedef pair<int,int> node;
int const N=23,M=1050,MOD=998244353;
int l,r,k,pw[N],d[N];
node f[N][M];
node dfs(int x,int s,int z,int l){
	if(!x)return{__builtin_popcount(s)<=k,0};
	if(!z&&!l&&~f[x][s].cnt)return f[x][s];
	node res={0,0};
	for(int i=0;i<=(l?d[x]:9);i++){
		node t=dfs(x-1,s|(z&&!i?0:1<<i),z&&!i,l&&i==(l?d[x]:9));
		res.cnt=(res.cnt+t.cnt)%MOD;
		res.ans=(res.ans+t.cnt*pw[x-1]%MOD*i%MOD+t.ans)%MOD;
	}
	if(!z&&!l)f[x][s]=res;
	return res;
}
int solve(int x){
	int tot=0;
	memset(f,-1,sizeof f);
	while(x)d[++tot]=x%10,x/=10;
	return dfs(tot,0,1,1).second;
}
signed main(){
	for(int i=0;i<N;i++)
		pw[i]=i?pw[i-1]*10%MOD:1;
	cin>>l>>r>>k;
	cout<<(solve(r)-solve(l-1)+MOD)%MOD<<"\n";
}//