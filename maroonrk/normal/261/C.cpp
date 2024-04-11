#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)

typedef long long ll;

const int s=41;	

ll dp[s][s];

int main(){
	ll n,t;
	scanf("%I64d%I64d",&n,&t);
	n++;
	ll k=-1;
	REP(i,s)
		if((1LL<<i)==t)
			k=i;
	if(k==-1){
		printf("0\n");
		return 0;
	}
	
	REP(i,s)REP(j,s)dp[i][j]=0;
	dp[0][0]=1;
	FOR(i,1,s)
		REP(j,s){
			dp[i][j]=dp[i-1][j];
			if(j>0)
				dp[i][j]+=dp[i-1][j-1];
		}
	
	ll ans=0;
	ll p=0,q=0;
	while(p+(1LL<<q)<=n){
		ans+=dp[q][k];
		p+=(1LL<<q++);
	}
	n-=p;
	for(int i=s-1;i>=0;i--){
		if(n&(1LL<<i)){
			ans+=dp[i][k--];
			if(k<0)
				break;
		}
	}
	if(t==1)
		ans--;
	printf("%I64d\n",ans);
}