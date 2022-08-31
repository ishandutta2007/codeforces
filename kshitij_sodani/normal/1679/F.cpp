#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=998244353;

llo n,m;
llo vis[10][10];
llo ss[10];
llo dp[2][1<<10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		vis[aa][bb]=1;
		vis[bb][aa]=1;
		ss[aa]^=(1<<bb);
		ss[bb]^=(1<<aa);
	}
	vector<pair<llo,llo>> aa;
	for(llo i=0;i<(1<<10);i++){
		for(llo j=0;j<10;j++){
			if((ss[j]&i)&((1<<(j))-1)){
				continue;
			}
			
			llo xx=(ss[j]&i)|(1<<j);
			aa.pb({xx,i});
		}
	}
	for(llo i=0;i<10;i++){
		dp[0][1<<i]=1;
	}
	for(llo j=1;j<n;j++){

		for(auto i:aa){
			dp[1][i.a]+=dp[0][i.b];
			if(dp[1][i.a]>=mod){
				dp[1][i.a]-=mod;
			}
		}
		for(llo i=0;i<(1<<10);i++){
			dp[0][i]=dp[1][i];
			dp[1][i]=0;
		}
	}
	llo ans=0;
	for(llo i=0;i<(1<<10);i++){
		ans=(ans+dp[0][i]);
	}
	ans%=mod;
	cout<<ans<<endl;






 
 
	return 0;
}