//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo dp[501*501];
llo dp2[501*501];
llo dp3[501*501];
llo mi;
llo n;
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
llo ans=0;
llo fac[200001];
llo fac2[200001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
void run(llo kk){
	//n-i-kk==1
	llo i=n-(kk+1);
	if(i<0){
		return;
	}
	llo cur=1;//cal(n,i);
	for(llo j=n-i+1;j<=n;j++){
		cur=(cur*j)%mod;
	}
	llo nn=n-i;
	llo cot=0;

	for(llo j=n*n;j>=0;j--){
		dp3[j]=dp[j]+dp3[j+1];
		if(dp3[j]>=mod){
			dp3[j]-=mod;
		}
	}

	for(llo k=0;k<nn;k++){
		for(llo l=k+1;l<nn;l++){
			cot=(cot+dp3[l-k+1+mi])%mod;
			/*if(nn==2){
			cout<<i<<":"<<k<<":"<<l<<":"<<dp[nn][l-k+1+mi]<<endl;
			}*/
		}
	}
	ans=(ans+cot*cur)%mod;



}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>mod;
	mi=(n*(n-1))/2;
	/*fac[0]=1;
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
	}*/
	//cout<<fac[2]<<":"<<fac2[2]<<endl;

	dp[(n*(n-1))/2]=1;
	
	run(0);
	for(llo i=1;i<=n;i++){
		llo su=0;
		llo ac=n*n;

	
		for(llo j=0;j<=ac;j++){
			/*dp2[j]=0;
			for(llo k=j;k>=(j-(i-1)) and k>=0;k--){
				dp2[j]=(dp2[j]+dp[i-1][k])%mod;
			}
			continue;*/
			su+=dp[j];
			if(su>=mod){
				su-=mod;
			}
			if(j-i>=0){
				su-=dp[j-i];
				su+=mod;
				if(su>=mod){
					su-=mod;
				}
			}
			dp2[j]=su;
		}
		su=0;
	/*	if(i==1){
			for(llo j=mi-1;j<=n*n;j++){
				cout<<dp2[j]<<":";
			}
			cout<<endl;
		}*/
		for(llo j=ac;j>=0;j--){
			/*for(llo k=j;k<=j+(i-1) and k<=ac;k++){
				dp[i][j]+=(dp2[k])%mod;
			}
			continue;*/
			su+=dp2[j];
			if(su>=mod){
				su-=mod;
			}
			if(j+i<=ac){
				su-=dp2[j+i];
				su+=mod;
				if(su>=mod){
					su-=mod;
				}
			}
			dp[j]=su;
		}
		run(i);
		/*if(i==2){
			for(llo j=mi-1;j<=n*n;j++){
				cout<<dp[j]<<":";
			}
			cout<<endl;
		}*/
	}
	//cout<<dp[1][mi]<<":"<<endl;
/*	for(llo i=0;i<=n;i++){
		for()
	}*/
/*	for(llo j=mi-1;j<=n*n;j++){
		cout<<dp[2][j]<<":";
	}
	cout<<endl;*/
	/*for(llo i=0;i<=n;i++){
		for(llo j=n*n-1;j>=0;j--){
			dp[i][j]+=dp[i][j+1];
			if(dp[i][j]>=mod){
				dp[i][j]%=mod;
			}
		}
	}*/
	
	
/*	for(llo i=0;i<n;i++){
		llo cur=1;//cal(n,i);
		for(llo j=n-i+1;j<=n;j++){
			cur=(cur*j)%mod;
		}

		llo nn=n-i;
		llo cot=0;
		for(llo k=0;k<nn;k++){
			for(llo l=k+1;l<nn;l++){
				cot=(cot+dp[nn-1][l-k+1+mi])%mod;

			}
		}
		ans=(ans+cot*cur)%mod;


	}*/

	cout<<ans<<endl;


	return 0;
}