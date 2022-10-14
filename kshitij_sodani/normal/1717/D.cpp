#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo dp[100001];
const llo mod=1e9+7;
llo solve(llo n,llo k){
	if(k==0){
		return 1;
	}
	llo ans=0;
	for(llo i=0;i<=n-1;i++){
		ans=(ans+solve(i,k-1));
	}
	return ans+1;
}


//llo pre[200001];
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
 	if(x<y){
 		return 0;
 	}
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=200000;
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


	llo n,k;
	cin>>n>>k;
	k=min(k,n);
	//llo cur=cal(n-1,k);
	
	llo ans=1;
	for(llo j=0;j<=k-1;j++){
		//cal j c j to n-1 c j
		ans=(ans+(cal(n,j+1)))%mod;
		continue;
		/*for(llo i=0;i<=n-1;i++){
			
			ans=(ans+cal(n-i-1,j))%mod;
		}
		ans=(ans+(cal(n-i-1+k-1,k-1)))%mod;*/
	}
	cout<<ans<<endl;
	/*ans=(ans+cur*k)%mod;
	cout<<cur<<":"<<endl;

	for(llo i=0;i<=k-1;i++){
		cur=cal(n-1,i);
		ans=(ans+(i+1)*cur)%mod;
	}
	cout<<ans<<endl;
*/



	return 0;
}