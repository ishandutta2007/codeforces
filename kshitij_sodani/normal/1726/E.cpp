#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
const llo mod=998244353;


llo dp[300001];
llo dp2[300001];

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
llo fac[600001];
llo fac2[600001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
llo pre[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	pre[0]=1;
	for(llo i=1;i<=300000;i++){
		pre[i]=(pre[i-1]*2)%mod;
	}
	llo ma=600000;
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
	llo t;
	cin>>t;
	dp[0]=1;
	dp[1]=1;
	dp2[0]=1;
	for(llo i=2;i<=300000;i++){
		dp[i]=(dp[i-1]+dp[i-2]*(i-1))%mod;
		if(i%2==0){
			dp2[i]=(dp2[i-2]*(i-1))%mod;
		}
	}
	while(t--){
		llo n;
		cin>>n;
		vector<llo> ss;
		for(llo i=0;i<n;i++){
			ss.pb(i);
		}
		llo ans=0;
		for(llo i=0;i<=n;i+=2){
			llo x=(i/2);
			if(x%2==1){
				continue;
			}
			//x+2 compartments
			//2*x booked
			//n-2*x in x+2
			llo xx=cal(n-2*x+x,x);
			if(i==0){
				xx=1;
			}
			//cout<<xx<<":"<<endl;
			llo cur=xx;
			cur=(cur*dp2[x])%mod;
			cur=(cur*pre[x/2])%mod;
			
			cur=(cur*dp[n-i])%mod;
			//cout<<i<<":"<<cur<<endl;
			ans=(ans+cur)%mod;
		}
		cout<<ans<<endl;

		/*while(true){
			llo st=1;
		
			for(llo i=0;i<n;i++){
				if(ss[i]==i){
					st=0;
				}
			}
			if(st==1){
				for(llo i=0;i<n;i++){
					ind[ss[i]]=i;
				}
				llo ok=1;
				for(llo i=0;i<n;i++){
					if(abs(ss[i]-ind[i])>1){
						ok=0;
					}
				}
				ans+=ok;
			}
			if(next_permutation(ss.begin(),ss.end())){
				continue;
			}
			break;
		}
		cout<<ans<<endl;*/
	}






	return 0;
}