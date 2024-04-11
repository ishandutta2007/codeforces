//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=998244353;
llo n;
llo dp[1000001];
llo co[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	cin>>n;
	dp[0]=1;
	llo su=0;
	for(llo i=1;i<=n;i++){
		for(llo j=i;j<=n;j+=i){
			co[j]++;
		}
	}
	for(llo i=1;i<=n;i++){
		dp[i]=su+co[i];
		dp[i]%=mod;
		su=(su+dp[i])%mod;

	}
	cout<<dp[n]<<endl;








	return 0;
}