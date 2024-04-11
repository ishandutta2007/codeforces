
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo mod=998244353;

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
//llo val[100];
llo it[300001];
llo pre[300001];
llo pre2[300001];
llo cal(llo aa,llo bb){
	llo cc=pre[aa]*pre2[bb];
	cc%=mod;
	cc=(cc*pre2[aa-bb])%mod;
	return cc;
}
llo dd[300001];
//llo ee[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<2*n;i++){
		cin>>it[i];
	}
	pre[0]=1;
	for(llo i=1;i<=2*n;i++){

		pre[i]=(pre[i-1]*i)%mod;
	}
	for(llo i=0;i<=2*n;i++){
		pre2[i]=ee(pre[i],mod-2);
	}


	sort(it,it+n*2);
	llo ans=0;
	llo tot=cal(2*n,n);

	for(int i=0;i<2*n;i++){
		llo val=(it[i]*tot)%mod;
		if(i<n){
			val=mod-val;
		}
		ans=(ans+val)%mod;
	}
	cout<<ans<<endl;







	return 0;
}