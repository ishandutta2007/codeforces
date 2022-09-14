#include <stdio.h>
#include <assert.h>

typedef long long ll;
typedef struct pll { ll first,second; } pll;

// a*x+b*y=g, x==0&&y==1||x==1&&y==0||1<=abs(x)<b/g&&1<=abs(y)<a/g&&x*y<0
ll min(ll x,ll y) { return x<y?x:y; }
ll egcd(ll a,ll b,ll *x,ll *y) {
	if(b==0) { *x=1,*y=0; return a; }
	ll g=egcd(b,a%b,x,y);
	ll z=*x; *x=*y; *y=z; *y-=(*x)*(a/b); return g;
}


pll solve(ll a,ll b,ll MOD) { // a*x=b (mod MOD)
	a=(a%MOD+MOD)%MOD;
	b=(b%MOD+MOD)%MOD;
	ll x,y,g=egcd(a,MOD,&x,&y);
	if(x<0) x+=MOD/g,y-=a/g;
	if(b%g!=0) return (pll){-1LL,-1LL};
	return (pll){x*(b/g)%(MOD/g),MOD/g};
}

int a,h,w;
void run() {
	scanf("%d%d%d",&a,&h,&w);
	//(a+h)*nhor = w-h mod (w+a)
	pll nhor=solve(a+h,w-h,w+a);
	if(nhor.first==-1&&nhor.second==-1) { printf("-1\n"); return; }
	pll nvert={((a+h)*nhor.first+h-w)/(w+a),(a+h)*nhor.second/(w+a)};
	//printf("(%lld,%lld) (%lld,%lld)\n",nhor.first,nhor.second,nvert.first,nvert.second);
	assert(((a+h)*nhor.first+h-w)%(w+a)==0); assert((a+h)%nhor.second/(w+a)==0);
	if(nhor.first==0) nhor.first+=nhor.second,nvert.first+=nvert.second;
	if(nvert.first<=0) { ll t=(1-nvert.first+nvert.second-1)/nvert.second; nhor.first+=t*nhor.second,nvert.first+=t*nvert.second; }
	if(w-nhor.first*a<0||h-nvert.first*a<0) { printf("-1\n"); return; }
	ll t=min((w-nhor.first*a)/(nhor.second*a),(h-nvert.first*a)/(nvert.second*a));
	nhor.first+=t*nhor.second,nvert.first+=t*nvert.second;
	//printf("%lld -> %.9lf / %lld -> %.9lf\n",nhor.first,1.0*(w-nhor.first*a)/(nhor.first+1),nvert.first,1.0*(h-nvert.first*a)/(nvert.first+1));
	printf("%.9lf\n",1.0*(w-nhor.first*a)/(nhor.first+1));
}

int main() {
	run();
    return 0;
}