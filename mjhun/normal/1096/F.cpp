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

#define MOD 998244353

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*a%MOD;
		e>>=1;
		a=a*a%MOD;
	}
	return r;
}

ll inv(ll a){return pm(a,MOD-2);}

int n;
int p[200005];
int s[200005],q;
ll r;

#define MAXN 200005

int ft[MAXN+1];
void upd(int i0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}

ll inversions(){
	ll r=0;
	for(int i=n-1;i>=0;--i)if(p[i]>=0){
		r+=get(p[i]);
		upd(p[i],1);
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",p+i),p[i]--;
	fore(i,0,n){
		if(p[i]>=0)s[p[i]+1]++;
		else q++;
	}
	fore(i,0,n)s[i+1]+=s[i];
	int iq=inv(q);
	if(q){
		int qq=0;
		fore(i,0,n){
			if(p[i]<0)qq++;
			else r=(r+1LL*qq*(q-(p[i]-s[p[i]]))%MOD*iq)%MOD;
		}
		qq=0;
		for(int i=n-1;i>=0;--i){
			if(p[i]<0)qq++;
			else r=(r+1LL*qq*(p[i]-s[p[i]])%MOD*iq)%MOD;
		}
	}
	r+=inversions();
	r%=MOD;
	r=(r+1LL*q*(q-1)/2%MOD*inv(2))%MOD;
	printf("%lld\n",r);
	return 0;
}