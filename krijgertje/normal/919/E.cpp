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

const int MAXP=1000003;


int egcd(int a,int b,int &x,int &y) {
	if(b==0) { x=1,y=0; return a; }
	int g=egcd(b,a%b,y,x); y-=x*(a/b); return g;
}

ll crt(int a1,int n1,int a2,int n2) {
	int m1,m2,g=egcd(n1,n2,m1,m2); assert(g==1);
	ll x=(ll)a1*m2*n2+(ll)a2*m1*n1,mod=(ll)n1*n2;
	return (x%mod+mod)%mod;
}


int inv[MAXP];
int lg[MAXP],nlg;
int pw[MAXP];

int a,b,p; ll x;


void run() {
	scanf("%d%d%d%lld",&a,&b,&p,&x);
	inv[1]=1; FOR(i,2,p) inv[i]=(p-(ll)(p/i)*inv[p%i]%p)%p;

	pw[0]=1; FOR(i,1,p-1) pw[i]=(ll)pw[i-1]*a%p;
	//printf("pw:"); REP(i,p-1) printf(" %d",pw[i]); puts("");
	nlg=0; REP(i,p) lg[i]=-1; REP(i,p-1) { if(lg[pw[i]]!=-1) { assert(pw[i]==1); break; } lg[pw[i]]=i,++nlg; }
	assert((p-1)%nlg==0);

	ll ret=0;
	FOR(u,1,p) { // n=u+v*p, n=s+t*nlg  -> n=u mod p,  n=s mod nlg
		int s=lg[(ll)b*inv[u]%p]; if(s==-1) continue;
		ll n=crt(u,p,s,nlg),m=(ll)p*nlg;
		//printf("u=%d s=%d -> n=%lld+x*%lld\n",u,s,n,m);
		if(n>x) continue;
		ret+=1+(x-n)/m;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}