//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo dp[51][51*51];
int n;
llo mod;
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
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>mod;

	fac[0]=1;
	llo ma=n;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
 
	for(llo i=ma;i>=0;i--){

		if(true){//i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
		//cout<<fac2[i]<<":";
	}
	//cout<<fac[2]<<":"<<fac2[2]<<endl;

	dp[0][(n*(n-1))/2]=1;
	int mi=(n*(n-1))/2;

	for(int i=1;i<=n;i++){
		llo su=0;
		int ac=n*n;

		for(int j=0;j<=ac;j++){
			for(int k=-(i-1);k<=(i-1);k++){
				int xx=(i-1)-abs(k)+1;
				if(j+k>ac or j+k<0){
					continue;
				}
				dp[i][j+k]+=dp[i-1][j]*xx;
				dp[i][j+k]%=mod;
			}


			/*su+=dp[i-1][j];
			if(su>=mod){
				su-=mod;
			}
			if(j-i>0){
				su-=dp[i-1][j-i-1];
				su+=mod;
				if(su>=mod){
					su-=mod;
				}
			}
			dp[i][j]=su;*/
		}
	}
	//cout<<dp[1][mi]<<":"<<endl;
/*	for(int i=0;i<=n;i++){
		for()
	}*/
	/*for(int j=mi-1;j<=n*n;j++){
		cout<<dp[2][j]<<":";
	}
	cout<<endl;*/
	for(int i=0;i<=n;i++){
		for(int j=n*n-1;j>=0;j--){
			dp[i][j]+=dp[i][j+1];
			if(dp[i][j]>=mod){
				dp[i][j]%=mod;
			}
		}
	}
	llo ans=0;
	
	for(int i=0;i<n;i++){
		llo cur=1;//cal(n,i);
		for(int j=n-i+1;j<=n;j++){
			cur=(cur*j)%mod;
		}
		//cur=(cur*fac[i])%mod;
		//cout<<i<<":"<<cur<<endl;
		llo nn=n-i;
		llo cot=0;
		for(int k=0;k<nn;k++){
			for(int l=k+1;l<nn;l++){
				cot=(cot+dp[nn-1][l-k+1+mi])%mod;
				/*if(nn==2){
				cout<<i<<":"<<k<<":"<<l<<":"<<dp[nn][l-k+1+mi]<<endl;
				}*/
			}
		}
		ans=(ans+cot*cur)%mod;

		/*for(int j=0;j<=n*n;j++){

		}*/

	}

	cout<<ans<<endl;


	return 0;
}