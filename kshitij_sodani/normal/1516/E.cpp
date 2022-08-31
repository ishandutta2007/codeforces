//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,k;
const llo mod=1e9+7;
llo ans[401];
llo pre[401];
llo pre2[401];
llo dp[401][201];
llo ee(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}
llo cal(llo i,llo j){
	llo cur=pre2[j];
	for(llo p=i;p>i-j;p--){
		cur=(cur*p)%mod;
	}
	return cur;
}
//llo dp2[301];
llo mm[401];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	pre[0]=1;
	pre2[0]=1;
	for(llo i=1;i<=400;i++){
		pre[i]=(pre[i-1]*i)%mod;
		pre2[i]=ee(pre[i],mod-2);
	}
	for(int i=0;i<=400;i++){
		mm[i]=ee(i,mod-2);
	}



	
	/*for(int i=1;i<=300;i++){
		dp2[i]=1;
		for(int j=1;j<i;j++){
			dp2[i]=(dp2[i]*(i-j))%mod;
		}
	}*/
	/*for(int i=1;i<=n;i++){
		cout<<dp2[i]<<",";
	}
	cout<<endl;*/
	dp[0][0]=1;
	for(llo j=1;j<=k;j++){
		for(llo i=1;i<=2*k;i++){
			for(llo ii=2;ii<=i;ii++){
				llo xx=dp[i-ii][j-1];//*dp2[ii];
				xx%=mod;
				dp[i][j]=(dp[i][j]+xx*mm[ii])%mod;
			}
		}
	}
	for(llo i=0;i<=2*k;i++){
		for(llo j=0;j<=k;j++){
			if(i<j){
				continue;
			}

			//i in j compartments
			if(i<=n and dp[i][j]>0){
				//cout<<i<<":"<<j<<":"<<dp[i][j]<<":"<<cal(n,i+j)<<endl;
				llo cot=(dp[i][j]*cal(n,i))%mod;
				//if(i+j>0){
					cot=(cot*pre[i])%mod;
					cot=(cot*pre2[j])%mod;
				//}
				//cout<<cot<<endl;
				ans[i-j]=(ans[i-j]+cot)%mod;
			}
		}
	}
	for(llo i=2;i<=k;i++){
		ans[i]=(ans[i-2]+ans[i])%mod;
	}
	for(llo i=1;i<=k;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;



	/*vector<llo> ss;
	for(llo i=0;i<n;i++){
		ss.pb(i);
	}*/






 
 
	return 0;
}