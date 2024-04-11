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
llo it[200001];
llo yy[200001];

llo mod=998244353;
llo pre[2010];
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
llo fac[2010];
llo fac2[2010];
llo pre2[2010][2010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	if(k==1){
		cout<<0<<endl;
		return 0;
	}
	yy[0]=1;
	for(llo i=1;i<=n;i++){
		yy[i]=(yy[i-1]*(k-2))%mod;
	}

	fac[0]=1;
	for(llo i=1;i<=2000;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
	for(llo i=0;i<=2000;i++){
		fac2[i]=ee(fac[i],mod-2);
		//cout<<fac2[i]<<":";
	}
	//cout<<endl;
	for(llo i=0;i<=2000;i++){
		for(llo j=0;j<=i;j++){
			pre2[i][j]=(fac[i]*fac2[j])%mod;
			pre2[i][j]=(pre2[i][j]*fac2[i-j])%mod;
		}
	}

	llo nn=n;
	llo cur=1;
	for(llo i=0;i<n;i++){
		if(it[i]==it[(i+1)%n]){
			nn-=1;
			cur=(cur*k)%mod;
		}
	}
	llo ans=0;
	for(llo i=0;i<=nn;i++){
		for(llo j=0;j<i;j++){
			if(j+i>nn){
				continue;
			}
			llo cot=cur;
			cot*=pre2[nn][i];
			cot%=mod;
			cot*=pre2[nn-i][j];
			cot%=mod;
			cot*=yy[nn-i-j];
			ans=(ans+cot)%mod;
			//cout<<i<<":"<<j<<":"<<cot<<endl;
		}
	}
	cout<<ans<<endl;









 
	return 0;
}