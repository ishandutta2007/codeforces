#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int llo;
#define endl "\n"
llo m;
llo e(llo a,llo b,llo c){
	if(b==0){
		return 1%c;
	}
	llo aa=1;
	if(b%2==1){
		aa=a;
	}
	llo ans=e(a,b/2,c);
	ans=(ans*ans)%c;
	ans=(ans*aa)%c;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n>>m;
	llo it[n];
	llo co[m];
	memset(co,0,sizeof(co));
	for(llo i=0;i<n;i++){
		cin>>it[i];
	//	it[i]%=m;
		//co[it[i]]+=1;
	}
	sort(it,it+n);
	if(n>m){
		cout<<0<<endl;
		return 0;
	}
	llo prod=1;
	for(llo i=0;i<n;i++){
		it[i]%=m;
		for(llo j=0;j<m;j++){
			llo k=(j+it[i])%m;
			if(co[j]>0){
			//	cout<<i<<" "<<j<<" "<<(it[i]-j+3*m)%m<<endl;
				prod=prod*e((it[i]-j+3*m)%m,co[j],m);
				prod%=m;
			}
		}
		co[it[i]]+=1;
	}
	cout<<prod<<endl;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
	return 0;
}