#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;


int n,MOD,l,r;

// Cat(a,b)=(a+b)!(a-b+1)/b!/(a+1)!
// Cat(a,b)=(b>0)=C(a+b,b)-C(a+b,b-1)

// n,d -> a=b+d, a+b=n -> b=n-a -> a=(n+d)/2, b=(n-d)/2, l<=d<=r -> 2*a-n=d -> (l+n)/2<=a<=(r+n)/2
// (EXCEPT ra=n) sum(Cat(a,n-a),a=la..ra)=sum(C(n,a)-C(n,a+1),a=la..ra)=sum(C(n,a),a=la..ra)-sum(C(n,a),a=la+1..ra+1)=C(n,la)-C(n,ra+1)

int egcd(int x,int y,int &a,int &b) { // a*x+b*y=g
	if(y==0) { a=1,b=0; return x; }
	int g=egcd(y,x%y,b,a); b-=a*(x/y); return g;
}
int inv(int x) {
	int a,b,g=egcd(x,MOD,a,b); assert(g==1); if(a<0) a+=MOD; return a; // a*x+b*MOD=g
}

vector<int> p;
typedef struct VAL {
	vector<int> a; int b;
	VAL() { a=vector<int>(SZ(p),0); b=1; }
	VAL(int x) { a=vector<int>(SZ(p),0); REPSZ(i,p) while(x%p[i]==0) ++a[i],x/=p[i]; b=x; }
} VAL;
VAL operator*(const VAL &u,const VAL &v) { VAL ret; REPSZ(i,p) ret.a[i]=u.a[i]+v.a[i]; ret.b=(ll)u.b*v.b%MOD; return ret; }
VAL operator/(const VAL &u,const VAL &v) { VAL ret; REPSZ(i,p) ret.a[i]=u.a[i]-v.a[i]; ret.b=(ll)u.b*inv(v.b)%MOD; return ret; }


VAL fact[MAXN+1];
void precalc() {
	{ p.clear(); int x=MOD; for(int i=2;i*i<=x;++i) if(x%i==0) { p.PB(i); while(x%i==0) x/=i; } if(x!=1) p.PB(x); }
	fact[0]=VAL(1); FORE(i,1,MAXN) fact[i]=fact[i-1]*VAL(i);
}
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int C(int n,int k) {
	VAL res=fact[n]/fact[k]/fact[n-k];
	int ret=res.b; REPSZ(i,p) ret=(ll)ret*pw(p[i],res.a[i])%MOD; /*printf("C(%d,%d)=%d\n",n,k,ret);*/ return ret;
}


int ways[MAXN+1]; // only using A and B

void run() {
	scanf("%d%d%d%d",&n,&MOD,&l,&r);
	precalc();

	//REPE(i,n) { printf("f%d: %d",i,fact[i].b); REPSZ(j,p) REP(k,fact[i].a[j]) printf(" %d",p[j]); puts(""); }

	REPE(i,n) {
		ways[i]=0;
		int la=(l+i+1)/2,ra=min(i,(r+i)/2);
		if(la>ra) continue;
		if(ra==i) ++ways[i],--ra;
		if(la>ra) continue;
		//printf("%d: %d..%d (%d)\n",i,la,ra,ways[i]);
		ways[i]=(ways[i]+(ll)C(i,la)+MOD-C(i,ra+1))%MOD;
	}
	//REPE(i,n) printf("%d: %d\n",i,ways[i]);

	int ret=0;
	REPE(i,n) ret=(ret+(ll)ways[i]*C(n,i))%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}