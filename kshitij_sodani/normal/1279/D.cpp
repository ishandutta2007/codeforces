#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
typedef unsigned long long int llo;
llo mod=998244353;
llo e(llo a,llo b,llo c){
	if(b==0){
		return 1;
	}
	llo aa=1;
	if(b%2==1){
		aa=a%mod;
	}
	llo ans=e(a,b/2,c);
	return (((ans*ans)%mod)*aa)%mod;
}
int main(){
		ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout<<1<<endl;
	llo n;
	llo m;
	
	llo aa;
 
	
	//cout<<1<<endl;
	cin>>n;
	vector<llo> it[n];
	map<llo,llo> ss;
	for(llo i=0;i<n;i++){
		cin>>m;
		for(llo j=0;j<m;j++){
			cin>>aa;
			it[i].pb(aa);
			if(ss.find(aa)==ss.end()){
				ss[aa]=1;
			}
			else{
				ss[aa]+=1;
			}
		}
	}
	llo ans=0;
	for(llo i=0;i<n;i++){
		llo d=it[i].size();
		for(llo j=0;j<d;j++){
			ans+=ss[it[i][j]]*e(d,mod-2,mod);
			ans%=mod;
		}
	}
	cout<<((ans*e((n*n),mod-2,mod))%mod)<<endl;
}