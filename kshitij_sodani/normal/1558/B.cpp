//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;

llo dp[4000001];
//vector<llo> pre[4000001];
llo val[4000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,mod;
	cin>>n>>mod;
	dp[1]=1;
	llo su=1;
	//pre[2]+=1;
	llo su2=0;
	//pre[2].pb(1);
	for(llo i=2;i<=n;i++){
	
		dp[i]+=su;

		if(dp[i]>=mod){
			dp[i]-=mod;
		}
		/*if(2*i<=n){
			pre[2*i].pb(i);
		}*/

		su2=(su2+val[i])%mod;
		su2=(su2+1)%mod;
		//cout<<su2<<":"<<endl;
		dp[i]=(dp[i]+su2)%mod;
		for(llo j=2*i;j<=n;j+=i){
		//	cout<<j<<"::"<<dp[i]-dp[i-1]<<endl;
			val[j]=(val[j]+dp[i]-dp[i-1]+mod);//
			if(val[j]>=mod){
				val[j]-=mod;
			}
			if(val[j]>=mod){
				val[j]-=mod;
			}
		}
		/*for(auto j:pre[i]){

				su2=(su2+dp[j]);
				if(su2>=mod){
					su2-=mod;
				}
				if(j>1){
					su2=(su2-dp[j-1]+mod);

				}
				if(su2>=mod){
					su2-=mod;
				}
			//}
			if(j+i<=n){
				pre[j+i].pb(j);
			}
		}*/
		/*pre[i].clear();

		dp[i]+=su2;
		if(dp[i]>=mod){
			dp[i]-=mod;
		}*/

		/*for(llo j=2*i;j<=2*i;j+=i){
			pre[j]+=1;
			if(pre[j]>=mod){
				pre[j]-=mod;
			}
			
		}*/


		su+=dp[i];
		if(su>=mod){
			su-=mod;
		}
	}
/*	for(llo i=1;i<=n;i++){
			cout<<dp[i]<<":";
	}
	cout<<endl;*/
		cout<<dp[n]<<endl;




 
 
 
	return 0;
}