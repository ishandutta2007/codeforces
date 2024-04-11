#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;ll k;
ll a[128];
priority_queue<pair<ll,int> > z;

int main(){
	scanf("%d%lld",&n,&k);
	fore(i,0,n)scanf("%lld",a+i);
	sort(a,a+n);
	ll s=0;
	fore(i,0,n)s+=a[i];
	if(a[n-1]*n-s<=k){
		printf("%lld\n",(k+s)/n);
		return 0;
	}
	fore(i,0,n)z.push(mp(a[i]-1,i));
	z.push(mp(0,-1));
	ll p=a[n-1]*n-s,q=n,l=a[n-1];
	while(z.top().fst){
		auto _=z.top();z.pop();
		ll t=_.fst;int i=_.snd;
		p-=q*(l-t);
		p+=(a[i]+t)/(t+1);
		p-=((-a[i])%(t+1)+t+1)%(t+1);
		p+=((-a[i])%t+t)%t;
		q-=(a[i]+t)/(t+1);
		q+=(a[i]+t-1)/t;
		ll r=t-(p-k+q-1)/q;
		if(r>z.top().fst&&r<=l){printf("%lld\n",r);return 0;}
		if(t>1){
			ll y=(a[i]+t-1)/t;
			z.push(mp((a[i]-1)/y,i));
		}
		l=t;
	}
	puts("1");
	return 0;
}