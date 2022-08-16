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
llo fac[300001];
llo fac2[300001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;

	fac[0]=1;
	llo ma=300000;
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
	/*for(llo i=ma;i>=0;i--){

	}*/

	while(t--){
		llo n,k;
		cin>>n>>k;
		llo ans=0;
		llo aa=ee(n,mod-2);
		//llo ans=0;
		for(llo i=2;i<=n;i++){
			aa=(aa*(ee(n-(i-1),mod-2)))%mod;
			if(true){
				llo le=n-1;
				//if(i>=3){
					le-=(k)*(i-2);
				//	le-=(i-1);

				//}
				
				if(le>=0){
					//le in i+1 compartments
					//one compartment <k
					llo co=0;
					for(llo j=1;j<k;j++){
						llo xx=le-j;
						if(xx>=0){
							co=(co+cal(xx+i-1,i-1))%mod;
						}
						//cout<<j<<",,"<<cal(xx+i-1,i-1)<<":"<<xx<<endl;
					}
					llo cur=(co*(i-1))%mod;
				//	cout<<i<<":"<<cur<<endl;
					cur=(cur*aa)%mod;
					cur=(cur*fac[i-1])%mod;
					cur=(cur*2)%mod;
					cur=(cur*i)%mod;
					ans=(ans+cur)%mod;
				}
			}
			if(i>=3){

				llo le=n-1;
				le-=(k*(i-3));
				llo co=0;
				if(le>=0){
					for(llo j=k;j<=2*k-2;j++){
						pair<llo,llo> aa={1,k-1};
						pair<llo,llo> bb={j-(k-1),j-1};
						llo yy=min(aa.b,bb.b)-max(aa.a,bb.a)+1;
						llo xx=le-j;
					//	cout<<j<<":"<<yy<<"<"<<xx<<endl;
						if(xx>=0){
							co=(co+yy*cal(xx+i-2,i-2))%mod;
						}
					}

					llo cur=(co*(i-2))%mod;
				//cout<<i<<"?"<<co<<endl;
					cur=(cur*aa)%mod;
					cur=(cur*fac[i-1])%mod;
					//cur=(cur*2)%mod;
					cur=(cur*i)%mod;
					ans=(ans+cur)%mod;

				}

			}
		}

	

		cout<<ans<<endl;
	}








	return 0;
}