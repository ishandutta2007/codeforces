#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=1e9+7;

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
llo fac[500001];
llo fac2[500001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
int n;
int it[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0]=1;
	llo ma=410000;
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

 

	cin>>n;
	llo ans=0;
	for(int i=0;i<=n;i++){
		cin>>it[i];
		if(it[i]>0){
			//i C i+.........
			ans=(ans+cal(i+it[i],i+1))%mod;
		}
	}
	cout<<ans<<endl;






	return 0;
}