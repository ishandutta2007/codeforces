#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll k){
	ll r=0;
	for(ll i=2;;++i){
		ll w=k/i/i/i;
		if(!w)break;
		r+=w;
	}
	return r;
}

int main(){
	ll m;
	cin>>m;
	ll s=7,e=1e16;
	while(e-s>1){
		ll k=(s+e)/2;
		if(f(k)<m)s=k;
		else e=k;
	}
	s++;
	if(f(s)==m)cout<<s<<endl;
	else puts("-1");
	return 0;
}