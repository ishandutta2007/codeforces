#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll a,b;int n;
ll l,t,m;

ll ct(ll k){
	return a*k+k*(k-1)/2*b;
}

bool can(ll r){
	if((r-1)*b+a>t)return false;
	return (ct(r)-ct(l)+t-1)/t<=m;
}

int main(){
	scanf("%lld%lld%d",&a,&b,&n);
	while(n--){
		scanf("%lld%lld%lld",&l,&t,&m);l--;
		ll s=l,e=1LL<<20;
		while(e-s>1){
			ll m=(s+e)/2;
			if(can(m))s=m;
			else e=m;
		}
		if(s==l)puts("-1");
		else printf("%lld\n",s);
	}
	return 0;
}