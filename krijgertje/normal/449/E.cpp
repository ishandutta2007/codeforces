#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

// lim = min(h,w)
// ret = sum((h-i+1)*(w-i+1)*a[i],i=1..lim) = sum(((h+1)*(w+1)-(h+w+2)*i+i*i)*a[i],i=1..lim) = (h+1)*(w+1)*sum(a[i],i=1..lim) - (h+w+2)*sum(i*a[i],i=1..lim) + sum(i*i*a[i],i=1..lim) = (h+1)*(w+1)*sum0[lim]-(h+w+2)*sum1[lim]+sum2[lim];
// sum0[x]=sum(a[i],i=1..x), sum1[x]=sum(i*a[i],i=1..x), sum2[x]=sum(i*i*a[i],i=1..x)
// a(L) = sum of unit squares contained in all squares which can be inscribed in a square with sides L
// a(L) = L*L+sum(b(L,i),i=1..L-1)
// b(L,i) = number of unit squares contained in the square defined by L and i
// b(L,i) = L*L-4*i*(L-i)+4c(i,L-i)
// c(x,y) = number of unit squares below diagonal in rectangle of size x*y = number of lattice points inside + on diagonal of triangle with sides x and y = (x*y-x-y+gcd(x,y))/2
// b(L,i) = L*L-4*i(L-i)+2*(i*(L-i)-i-(L-i)+gcd(i,L-i)) = L*L-2*i*L+2*i*i-2*L+2*gcd(i,L-i)
// a(L) = L*L+sum(L*L-2*L-2*i*L+2*i*i+2*gcd(i,L-i),i=1..L-1) = L*L+(L*L-2*L)*sum(1,i=1..L-1)-2*L*sum(i,i=1..L-1)+2*sum(i*i,i=1..L-1)+2*sum(gcd(L,i),i=1..L-1)
//      = L*L+(L*L-2*L)*(L-1)-L*L*(L-1)+((L-1)*L*(2*L-1))/3+2*d(L)
// d(L) = sum(gcd(L,i),i=1..L-1) = sum(d*#times gcd(L,i)=d,d|L) = sum(d*#times gcd(L/d,i)=1,d|L) = sum(d*phi(L/d),d|L)

const int MOD=1000000007;
const int MAXN=1000000;


ll sum0[MAXN+1];
ll sum1[MAXN+1];
ll sum2[MAXN+1];

int n;

void run() {
	scanf("%d",&n);
	REP(i,n) {
		int h,w; scanf("%d%d",&h,&w);
		int lim=min(h,w);
		ll ret=(ll)(h+1)*(w+1)%MOD*sum0[lim]-(h+w+2)*sum1[lim]+sum2[lim];
		ret=ret%MOD; if(ret<0) ret+=MOD;
		printf("%d\n",(int)ret);
	}
}

int p[MAXN+1];
int phi[MAXN+1];
ll d[MAXN+1];
ll a[MAXN+1];

ll calcd(int L,int x,int d) {
	if(x==1) return d*phi[L/d];
	ll ret=0;
	int cp=p[x],cnt=0;
	while(p[x]==cp) x/=cp,cnt++;
	REPE(i,cnt) {
		ret+=calcd(L,x,d);
		d*=cp;
	}
	return ret;
}

void precalc() {
	REPE(i,MAXN) p[i]=i; p[0]=p[1]=-1;
	REPE(i,MAXN) if(p[i]==i) for(int j=i+i;j<=MAXN;j+=i) p[j]=i;
	FORE(i,1,MAXN) { phi[i]=1; int x=i; while(x!=1) { int cp=p[x],now=1; while(p[x]==cp) x/=cp,now*=cp; phi[i]*=now-now/cp; } }
	FORE(i,1,MAXN) d[i]=calcd(i,i,1)-i;
	for(ll i=1;i<=MAXN;++i) a[i]=(i*i+(i*i-2*i)*(i-1)-i*i*(i-1)+((i-1)*i*(2*i-1))/3+2*d[i])%MOD;
	sum0[0]=0; FORE(i,1,MAXN) sum0[i]=(sum0[i-1]+a[i])%MOD;
	sum1[0]=0; FORE(i,1,MAXN) sum1[i]=(sum1[i-1]+a[i]*i)%MOD;
	sum2[0]=0; FORE(i,1,MAXN) sum2[i]=(sum2[i-1]+a[i]*i%MOD*i)%MOD;
	//FORE(i,1,MAXN) printf("%3d: p=%3d, phi=%3d, d=%4lld, a=%12lld, sum0=%lld, sum1=%lld,sum2=%lld\n",i,p[i],phi[i],d[i],a[i],sum0[i],sum1[i],sum2[i]);
}

int main() {
	precalc();
	run();
	return 0;
}