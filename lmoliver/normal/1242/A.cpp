#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(LL N=(LL)(S);N<=(LL)(E);N++)

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

int main(){
	ios::sync_with_stdio(false);
	LL n;
	cin>>n;
	LL ans=n;
	F(i,2,min((LL)1e6,n-1)){
		if(n%i==0){
			ans=gcd(ans,gcd(i,n/i));
		}
	}
	cout<<ans<<endl;
	return 0;
}