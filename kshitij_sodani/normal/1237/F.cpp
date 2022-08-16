//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m,k;
llo vis[4001];
llo vis2[4001];
const llo mod=998244353;
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
llo fac[200001];
llo fac2[200001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]);//*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
llo dp[4001][4001];
llo dp2[4001][4001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	//cin>>n>>m>>k;
	/*for(llo i=0;i<n;i++){
		vis[i]=0;
	}
	for(llo i=0;)*/

	fac[0]=1;
	llo ma=4000;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
 
	for(llo i=ma;i>=0;i--){
		if(i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
		//cout<<fac2[i]<<":";
	}


	for(llo i=0;i<k;i++){
		llo aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		aa--;
		bb--;
		cc--;
		dd--;
		vis[aa]=1;
		vis[cc]=1;
		vis2[bb]=1;
		vis2[dd]=1;
	}
	vector<llo> aa;
	vector<llo> bb;
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			aa.pb(i);
		}
	}
	for(llo i=0;i<m;i++){
		if(vis2[i]==0){
			bb.pb(i);
		}
	}
	if(aa.size()==0 or bb.size()==0){
		cout<<1<<endl;
	}
	else{
		n=aa.size();
		m=bb.size();
		dp[0][0]=1;
	//	cout<<n<<":"<<m<<endl;
		for(llo i=1;i<=aa.size();i++){
			for(llo j=0;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				if(j>0){
					if(i>1){
						if(aa[i-1]==aa[i-2]+1){
							dp[i][j]+=dp[i-2][j-1];
							if(dp[i][j]>=mod){
								dp[i][j]-=mod;
							}
						}
					}
				}
			}
		}
		/*for(auto i:aa){
			cout<<i<<":";
		}
		cout<<endl;

		for(llo i=0;i<=m;i++){
			cout<<dp[aa.size()][i]<<",";
		}
		cout<<endl;*/
		dp2[0][0]=1;
		for(llo i=1;i<=bb.size();i++){
			for(llo j=0;j<=n;j++){
				dp2[i][j]=dp2[i-1][j];
				if(j>0){
					if(i>1){
						if(bb[i-1]==bb[i-2]+1){
							dp2[i][j]+=dp2[i-2][j-1];
							if(dp2[i][j]>=mod){
								dp2[i][j]-=mod;
							}
						}
					}
				}
			}
		}
		llo ans=0;
		for(llo i=0;i<=m;i++){
			for(llo j=0;j<=n;j++){
				if(m-2*j>=i and n-2*i>=j){
					//cout<<i<<":"<<j<<endl;
					llo cur=dp[aa.size()][i]*dp2[bb.size()][j];
					cur%=mod;
					//cout<<cur<<endl;
					cur=(cur*cal(m-2*j,i))%mod;
					cur=(cur*cal(n-2*i,j))%mod;
					ans=(ans+cur)%mod;
				}
				/*if(dp[aa.size()][i]>0 and dp2[bb.size()][j]>0){
					
				}*/
			}
		}
		cout<<ans<<endl;

	}






	return 0;
}