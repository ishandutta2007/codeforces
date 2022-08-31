//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

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
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=100000;
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
	llo aa=0;
	llo bb=0;
	llo cc=0;
	llo dd=0;
	llo n;
	cin>>n;
	llo co=0;
	llo co2=0;
	llo co3=0;
	llo co4=0;
	llo st=1;
	llo stt=1;
	llo stt2=1;
	for(llo i=0;i<n;i++){
		string s;
		cin>>s;
		if(s[0]=='W'){
			aa++;
		}
		else if(s[0]=='B'){
			bb++;
		}
		if(s[1]=='B'){
			cc++;
		}
		else if(s[1]=='W'){
			dd++;
		}
		if(s[0]=='W' and s[1]=='B'){
			co++;
		}
		else if(s[0]=='W' and s[1]=='?'){
			co2++;
		}
		else if(s[0]=='?' and s[1]=='B'){
			co3++;
		}
		else if(s[0]=='W' or s[1]=='B'){
			st=0;
		}
		if(s[0]=='?' and s[1]=='?'){
			co4++;
		}

		if(s[0]=='B' or s[1]=='W'){
			stt=0;
		}
		if(s[0]=='W' or s[1]=='B'){
			stt2=0;
		}
		

	}
	llo ans=0;
	for(llo i=0;i<=n;i++){
		if(i>=aa and i>=cc){
			if(n-i>=bb and n-i>=dd){
				llo cur=cal(n-aa-bb,i-aa)*cal(n-cc-dd,i-cc);
				cur%=mod;

				if(st==1){
					llo le=i-co-co2-co3;
					if(le<=co4){
						cur=(cur-cal(co4,le)+mod)%mod;
					}
				}
				ans=(ans+cur)%mod;
			
			}
		}	
	}


 	ans=(ans+stt+stt2)%mod;

	cout<<ans<<endl;

 
	return 0;
}