#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(ll i = a, qwer = n;i<qwer;i++)
using namespace std;
typedef long long ll;

ll n;
ll r;
ll l[200005];
ll t[200005];
vector<ll> sol;
ll ss;  // sol size

int main() {
	scanf("%lld%lld",&n,&r);
	fore(i,0,n)scanf("%lld",l+i);
	fore(i,0,n)scanf("%lld",t+i);
	fore(i,0,n)if(t[i]<l[i]){puts("-1");return 0;}
	ll k=0,x=0,tp=0;ll tt=0;
	while(k<n){
		if(tp+2*(l[k]-x)<=t[k]){
			tt+=2*(l[k]-x);
			k++;
			x=tp=0;
			continue;
		}
		// no llego
		ll x1=t[k]-tp-l[k]+2*x;
		//printf(" %lld\n",x1);
		assert(x1>=x&&x1<l[k]);
		tt+=2*(x1-x);
		tp+=2*(x1-x);
		x=x1;
		if(ss<100000){
			// normal
			ss++;
			sol.pb(tt);
			tt+=r;
			x+=r;
			bool w=false;
			while(k<n&&x>=l[k]){
				w=true;
				x-=l[k];
				k++;
			}
			if(w)tp=x;
			else tp+=r;
		}
		else {
			// comprimo
			// tengo que usar techo((l[k]-x)/r)
			ll q=(l[k]-x+r-1)/r;
			ss+=q;
			tt+=r*q;
			x+=r*q;
			bool w=false;
			while(k<n&&x>=l[k]){
				w=true;
				x-=l[k];
				k++;
			}
			if(w)tp=x;
			else tp+=r;
		}
	}
	printf("%lld\n",ss);
	if(ss<=100000){
		fore(i,0,ss){
			if(i)putchar(' ');
			printf("%lld",sol[i]);
		}
		puts("");
	}
	return 0;
}