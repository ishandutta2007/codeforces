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
#define SZ(x) ((int)x.size())
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int n;
pair<ll,int> x[100005];
ll a,m,cf,cm;
pair<ll,pair<int,ll> > r;
ll s[100005],rr[100005];

ll cost(ll t, int n){
	int k=lower_bound(x,x+n,mp(t,-1))-x;
	return t*k-s[k];
}

int main(){
	scanf("%d%lld%lld%lld%lld",&n,&a,&cf,&cm,&m);
	fore(i,0,n)scanf("%lld",&x[i].fst),x[i].snd=i;
	sort(x,x+n);
	fore(i,0,n)s[i+1]=s[i]+x[i].fst;
	r=mp(0,mp(0,0LL));
	fore(i,0,n+1){
		ll q=m-(a*i-(s[n]-s[n-i]));
		if(q<0)break;
		ll ss=0,ee=a+1;
		while(ee-ss>1){
			ll mm=(ss+ee)/2;
			if(cost(mm,n-i)<=q)ss=mm;
			else ee=mm;
		}
		r=max(r,mp(cf*i+cm*ss,mp(i,ss)));
	}
	printf("%lld\n",r.fst);
	fore(i,0,n)x[i].fst=max(x[i].fst,r.snd.snd);
	fore(i,n-r.snd.fst,n)x[i].fst=a;
	fore(i,0,n)rr[x[i].snd]=x[i].fst;
	fore(i,0,n)printf("%lld%c",rr[i]," \n"[i==n-1]);
	return 0;
}