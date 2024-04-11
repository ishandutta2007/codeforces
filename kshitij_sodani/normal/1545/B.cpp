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
llo t;
llo it[1000001];

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
llo fac[300000+1];
llo fac2[300000+1];
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


	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		vector<llo> aa;
		llo kk=0;
		llo mm=0;
		llo co3=0;
		llo co4=0;
		vector<llo> ss;
		for(llo i=0;i<n;i++){

			it[i]=s[i]-'0';
			if(it[i]==0){
				ss.pb(i%2);
			}
		}
		if(ss.size()==0){
			cout<<1<<endl;
			continue;
		}
		/*for(auto j:ss){
			cout<<j<<",";
		}
		cout<<endl;*/
		llo xx=n-ss.size();
		for(llo i=0;i+1<ss.size();i++){
			if(ss[i]==ss[i+1]){
				xx--;
			}
		}
		if(ss[0]%2==1){
			xx--;
		}
		xx/=2;
		cout<<cal(xx+ss.size(),ss.size())<<endl;
		//xx in ss.size()+1


	//	cout<<ss.size()<<":"<<endl;
		continue;
		cout<<kk<<":"<<co3<<endl;
		cout<<mm<<":"<<co3<<endl;
		if(aa.size()==0){
			cout<<1<<endl;
			continue;
		}
		vector<llo> bb;
		bb.pb(aa[0]);
		for(llo i=0;i+1<aa.size();i++){
			bb.pb(aa[i+1]-aa[i]-1);
		}
		bb.pb(n-1-aa.back());
	/*	for(auto j:bb){
			cout<<j<<",";
		}
		cout<<endl;*/
		llo su=0;
		llo co=0;
		llo su2=0;
		llo co2=0;
		for(llo i=0;i<bb.size();i++){
			if(i%2==0){
				su+=bb[i];
				co++;
			}
			else{
				su2+=bb[i];
				co2++;
			}
		}
		for(llo i=0;i<bb.size();i+=2){
			if(i+1==bb.size()){
				cout<<bb[i]<<",";
			}
			else{
				cout<<bb[i]+bb[i+1]<<",";//endl;
			}

		}

		/*cout<<su<<":"<<co<<endl;
		cout<<su2<<":"<<co2<<endl;*/
		cout<<endl;
	}



 
 
 
 
 
 
 
	return 0;
}