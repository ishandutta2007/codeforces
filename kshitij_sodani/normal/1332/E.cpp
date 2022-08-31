#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
llo mod=998244353;
llo e(llo aa,llo bb){
	//cout<<aa<<" "<<bb<<" "<<mod<<endl;
	if(bb==0){
		return 1;
	}
	llo x=e(aa,bb/2);
	x=x*x;
	x%=mod;
	if(bb%2==1){
		x*=aa;
		x%=mod;
	}
	return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	llo n,m,l,r;
	cin>>n>>m>>l>>r;
	if((n*m)%2==0){
		llo xx=r/2-(l-1)/2;
		llo yy=r-l+1-xx;
		//cout<<xx<<" "<<yy<<endl;
		if(xx==yy){
			llo ac=e(xx,(n*m));
			ac*=e(2,(n*m-1));
			ac%=mod;
			cout<<ac<<endl;
		}
		else{
			llo ac=e(xx+yy,(n*m));
			ac=(ac+1+mod)%mod;
			ac*=e(2,mod-2);
			cout<<ac%mod<<endl;
		}
	}	
	else{
		cout<<e((r-l+1)%mod,(n*m))<<endl;
	}


















	return 0;
}