#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll doit(ll x0, ll y0, ll x1, ll y1, ll k){
	ll x=abs(x1-x0),y=abs(y1-y0);
	ll d=x+y-min(x,y);
	if(k<d)return -1;
	ll r=-1;
	assert((x+y)%2==0);
	ll xx=(x+y)/2,yy=abs(x-y)/2;
	ll t=xx+yy;
	if(t%2==k%2)r=k;
	else r=k-2;
	return r;
}

int main(){
	int q;
	scanf("%d",&q);
	fore(_,0,q){
		ll x,y,k;
		scanf("%lld%lld%lld",&x,&y,&k);
		ll d=x+y-min(x,y);
		if(k<d){puts("-1");continue;}
		ll r=-1;
		if((x+y)%2==0){
			ll xx=(x+y)/2,yy=abs(x-y)/2;
			ll t=xx+yy;
			if(t%2==k%2)r=k;
			else r=k-2;
		}
		else {
			r=max(r,doit(1,0,x,y,k-1));
			r=max(r,doit(-1,0,x,y,k-1));
			r=max(r,doit(0,1,x,y,k-1));
			r=max(r,doit(0,-1,x,y,k-1));
		}
		printf("%lld\n",r);
	}
	return 0;
}