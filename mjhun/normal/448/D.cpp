#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll n,m,k;

ll cnt(ll x){
	ll r=0;
	fore(i,1,n+1)r+=min(x/i,m);
	return r;
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	ll s=1,e=n*m+5;
	while(e-s>1){
		ll md=(s+e)/2;
		if(cnt(md-1)>=k)e=md;
		else s=md;
	}
	printf("%lld\n",s);
	return 0;
}