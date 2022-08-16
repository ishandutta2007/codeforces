//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const llo mod=1e9+7;
 
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

llo fac[1000001];
llo fac2[1000001];
llo cal(llo x,llo y){
 	if(x<y or x<0 or y<0){
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
	llo ma=1000000;
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

 	llo n;
 	cin>>n;
 	llo ans=0;
 	llo cur=1;
 	for(llo i=2;i<=n;i+=2){
 		cur=(cur*(i-1))%mod;
 		cur=(cur*i)%mod;
 		if(i==n){
 			ans=(ans+cur)%mod;
 			continue;
 		}
 		/*if((n-i)>=((n+1)/2)){
 			continue;
 		}*/
 		llo cur2=cal(i,n-i);
 		if(i<n){
 			cur2+=cal(i-1,n-i-1);
 		}
 		cur2%=mod;
 	//	cout<<i<<":"<<cur2<<endl;
 		ans=(ans+cur*cur2)%mod;
 		//ans=(ans+)%mod;

 	}
 	ans=(ans*2)%mod;
 	cout<<ans<<endl;
 
 
 
 
 
 
 
 
 
	return 0;
}