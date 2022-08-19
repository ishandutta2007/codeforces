#include <bits/stdc++.h>

using ll=long long;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(x) x.begin(),x.end()

using namespace std;

using pi=pair<int,int>;
using vi=vector<int>;

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void print(ll x,int z){
	printf("%lld",x);
	if(z==1)printf("\n");
	if(z==2)printf(" ");
}

void chmin(int&a,int b){
	if(a>b)a=b;
}

const int inf=INT_MAX/2;
const int Nmax=500010;
const int Pmax=110;
int pos[Nmax],dp[2][Nmax],bit[Pmax];

signed main(){
	int n=read(),k=read(),p=read();
	FOR(i,1,n+1)pos[i]=(read()+pos[i-1])%p;
	
	int cur=0;
	dp[cur][0]=0;
	FOR(i,1,n+1)dp[cur][i]=inf;
	
	REP(_,k){
		int ent=inf;
		REP(i,p)bit[i]=inf;
		int nx=cur^1;
		REP(i,n+1){
			dp[nx][i]=ent;
			for(int j=pos[i];j>=0;j-=((j+1)&(-j-1)))
				chmin(dp[nx][i],bit[j]);
			dp[nx][i]+=pos[i];
			//cerr<<_<<" "<<nx<<" "<<i<<" "<<dp[nx][i]<<endl;
			for(int j=pos[i];j<p;j+=((j+1)&(-j-1)))
				chmin(bit[j],dp[cur][i]-pos[i]);
			chmin(ent,dp[cur][i]+p-pos[i]);
		}
		cur=nx;
	}
	
	print(dp[cur][n],1);
}