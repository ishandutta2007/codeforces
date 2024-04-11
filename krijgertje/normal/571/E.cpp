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

const int MAXN=100;
const int MAXVAL=1000000000;
const int MAXSQRTVAL=31622;
const int MOD=1000000007;

typedef vector<pair<int,int> > pp;
typedef pair<ll,ll> pw;
void print(const pp &a) { printf("("); if(SZ(a)==0) printf("1"); REPSZ(i,a) { if(i!=0) printf("*"); printf("%d",a[i].first); if(a[i].second!=1) printf("^%d",a[i].second); } printf(")"); }


int n;
int aa[MAXN],bb[MAXN];
pp a[MAXN],b[MAXN];


bool isp[MAXSQRTVAL+1];
int p[MAXSQRTVAL+1],np;

ll modpow(ll a,ll n) { if(n==0) return 1; if(n%2==1) return a*modpow(a,n-1)%MOD; return modpow(a*a%MOD,n/2); }
pp getpp(int x) {
	pp ret;
	for(int i=0;p[i]*p[i]<=x;++i) if(x%p[i]==0) { ret.PB(MP(p[i],1)); x/=p[i]; while(x%p[i]==0) ++ret[SZ(ret)-1].second,x/=p[i]; }
	if(x!=1) ret.PB(MP(x,1));
	return ret;
}
// n*a-m*b=g
ll egcd(ll a,ll b,ll &n,ll &m) { if(b==0) { n=1,m=0; return a; } ll g=egcd(b,a%b,m,n); m=-m-n*(a/b); n=-n;  return g; }
const int ARG=0;
const int RES=1;
bool _insersect(pw &a,pw &b,int mode) {
	if(a.second==0&&b.second==0) { bool ret=a.first==b.first; if(mode==ARG) a=b=MP(-1,-1); return ret; }
	if(a.second==0) { bool ret=a.first>=b.first&&(a.first-b.first)%b.second==0; if(mode==ARG) a=MP(0,1),b=MP((a.first-b.first)/b.second,0LL); return ret;}
	if(b.second==0) { bool ret=b.first>=a.first&&(b.first-a.first)%a.second==0; if(mode==ARG) a=MP((b.first-a.first)/a.second,0LL),b=MP(0,1); else a=b; return ret; }
	ll n,m;
	ll g=egcd(a.second,b.second,n,m); // n*a.second-m*b.second=g;
	if((b.first-a.first)%g!=0) return false;
	ll times=(b.first-a.first)/g; n*=times,m*=times;
	ll aa=a.second/g,bb=b.second/g;
	if(n<0) { ll x=(-n+bb-1)/bb; n+=bb*x; m+=aa*x; }
	if(m<0) { ll x=(-m+aa-1)/aa; n+=bb*x; m+=aa*x; }
	if(n>=bb&&m>=aa) { ll x=min(n/bb,m/aa); n-=bb*x; m-=aa*x; }
	if(mode==ARG) a=MP(n,bb),b=MP(m,aa); else a.first+=a.second*n,a.second*=bb; return true;
}
bool intersect(pw &a,pw &b,int mode) {
	//printf("\t\tintersect(%lld+%lldn,%lld+%lldm) = ",a.first,a.second,b.first,b.second);
	bool ret=_insersect(a,b,mode);
	//if(ret) printf("%lld+%lldk / %lld+%lldk (%s)\n",a.first,a.second,b.first,b.second,mode==ARG?"arg":mode==RES?"res":"?"); else printf("err\n");
	return ret;
}
bool _combine(pw &n,pw &m,const pw &a,const pw &b) {
	if(a.first==-1&&a.second==-1&&b.first==-1&&b.second==-1) return true;;
	if(n.first==-1&&n.second==-1&&m.first==-1&&m.second==-1) { n=a,m=b; return true; }
	//n.first+i*n.second=a.first+j*a.second
	//m.first+i*m.second=b.first+j*b.second
	if(b.second*n.second==a.second*m.second) {
		//n.first*b.second+i*n.second*b.second=a.first*b.second+j*a.second*b.second
		//m.first*a.second+i*n.second*b.second=b.first*a.second+j*a.second*b.second
		//n.first*b.second-m.first*a.second=a.first*b.second-b.first*a.second
		if(n.first*b.second-m.first*a.second!=a.first*b.second-b.first*a.second) return false;
		if(n.first*m.second-m.first*n.second!=a.first*m.second-b.first*n.second) return false;
		if(n.second==0) {
			if(a.second==0) {
				if(n.first!=a.first) return false;
				if(m.second==0) {
					if(b.second==0) {
						if(m.first!=b.first) return false;
						n=n,m=m;
					} else {
						if(m.first-b.first<0||(m.first-b.first)%b.second!=0) return false;
						n=n,m=m;
					}
				} else {
					if(b.second==0) {
						if(b.first-m.first<0||(b.first-m.first)%m.second!=0) return false;
						m.first=b.first; m.second=0;
					} else {
						//i=(b.first-m.first+j*b.second)/m.second
						ll x=b.first-m.first;
						ll p,q,g;
						g=egcd(m.second,b.second,p,q);
						if(x%g!=0) return false;
						ll bb=b.second/g,mm=m.second/g,xx=x/g; p*=xx,q*=xx;
						if(p<0) { ll x=(-p+bb-1)/bb; p+=x*bb,q+=x*mm; }
						if(q<0) { ll x=(-q+mm-1)/mm; p+=x*bb,q+=x*mm; }
						if(p>=bb&&q>=mm) { ll x=min(p/bb,q/mm); p-=x*bb,q-=x*mm; }
						m.first+=p*m.second; m.second*=bb;
					}
				}
			} else {
				assert(m.second==0);
				if(n.first-a.first<0||(n.first-a.first)%a.second!=0) return false;
				if(b.second==0&&b.first!=m.first) return false;
				if(b.second!=0&&(m.first-b.first<0||(m.first-b.first)%b.second!=0)) return false;
				n=n,m=m;
			}
		} else {
			if(a.second==0) {
				assert(b.second==0);
				if(a.first-n.first<0||(a.first-n.first)%n.second!=0) return false;
				if(m.second==0&&m.first!=b.first) return false;
				if(m.second!=0&&(b.first-m.first<0||(b.first-m.first)%m.second!=0)) return false;
				n.first=a.first; n.second=0;
				m.first=b.first; m.second=0;
			} else {
				//i=(a.first-n.first+j*a.second)/n.second
				ll x=a.first-n.first;
				ll p,q,g;
				g=egcd(n.second,a.second,p,q);
				if(x%g!=0) return false;
				ll aa=a.second/g,nn=n.second/g,xx=x/g; p*=xx,q*=xx;
				if(p<0) { ll x=(-p+aa-1)/aa; p+=x*aa,q+=x*nn; }
				if(q<0) { ll x=(-q+nn-1)/nn; p+=x*aa,q+=x*nn; }
				if(p>=aa&&q>=nn) { ll x=min(p/aa,q/nn); p-=x*aa,q-=x*nn; }
				n.first+=p*n.second; n.second*=aa;
				m.first+=p*m.second; m.second*=aa;
			}
		}
	} else {
		//i=((m.first-b.first)*a.second+(a.first-n.first)*b.second)/(b.second*n.second-a.second*m.second)
		//j=((m.first-b.first)*n.second+(a.first-n.first)*m.second)/(b.second*n.second-a.second*m.second)
		ll num1=(m.first-b.first)*a.second+(a.first-n.first)*b.second;
		ll num2=(m.first-b.first)*n.second+(a.first-n.first)*m.second;
		ll den=b.second*n.second-a.second*m.second;
		if(num1%den!=0||num2%den!=0) return false;
		ll p=num1/den,q=num2/den;
		if(p<0||q<0) return false;
		n.first+=p*n.second; n.second=0;
		m.first+=p*m.second; m.second=0;
	}
	return true;
}
bool combine(pw &n,pw &m,const pw &a,const pw &b) {
	//printf("\t\tcombine(%lld+%lldi=%lld+%lldi and %lld+%lldj=%lld+%lldj) = ",n.first,n.second,a.first,a.second,m.first,m.second,b.first,b.second);
	bool ret=_combine(n,m,a,b);
	//if(ret) printf("%lld+%lldi / %lld+%lldj\n",n.first,n.second,m.first,m.second); else printf("err\n");
	return ret;
}
bool calc(const pp &a0,const pp &b0,const pp &a1,const pp &b1,pw &res) {
	int i0=0,j0=0,i1=0,j1=0;
	pw n=MP(-1,-1),m=MP(-1,-1);
	while(true) {
		int cur=INT_MAX;
		if(i0<SZ(a0)&&a0[i0].first<cur) cur=a0[i0].first;
		if(j0<SZ(b0)&&b0[j0].first<cur) cur=b0[j0].first;
		if(i1<SZ(a1)&&a1[i1].first<cur) cur=a1[i1].first;
		if(j1<SZ(b1)&&b1[j1].first<cur) cur=b1[j1].first;
		if(cur==INT_MAX) break;
		pw a,b;
		if(i0<SZ(a0)&&a0[i0].first==cur) a.first=a0[i0++].second;
		if(j0<SZ(b0)&&b0[j0].first==cur) a.second=b0[j0++].second;
		if(i1<SZ(a1)&&a1[i1].first==cur) b.first=a1[i1++].second;
		if(j1<SZ(b1)&&b1[j1].first==cur) b.second=b1[j1++].second;
		//printf("\t%lld+x*%lld=%lld+y*%lld\n",a.first,a.second,b.first,b.second);
		if(!intersect(a,b,ARG)) return false;
		if(!combine(n,m,a,b)) return false;
	}
	res=n; return true;
}



void run() {
	REPE(i,MAXSQRTVAL) isp[i]=true; isp[0]=isp[1]=false;
	for(int i=2;i*i<=MAXSQRTVAL;++i) if(isp[i]) for(int j=i*i;j<=MAXSQRTVAL;j+=i) isp[j]=false;
	np=0; REPE(i,MAXSQRTVAL) if(isp[i]) p[np++]=i;

	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&aa[i],&bb[i]);
	REP(i,n) a[i]=getpp(aa[i]);
	REP(i,n) b[i]=getpp(bb[i]);

	pw res=MP(0,1);
	FOR(i,1,n) {
		pw cur;
		if(!calc(a[0],b[0],a[i],b[i],cur)) { printf("-1\n"); return; }
		if(!intersect(res,cur,RES)) { printf("-1\n"); return; }
		//printf("%d: ",i); printf("%lld+%lldn -> %lld+%lldn\n",cur.first,cur.second,res.first,res.second);
	}
	int ret=(ll)aa[0]*modpow(bb[0],res.first)%MOD;
	printf("%d\n",ret);	
}

int main() {
	run();
	return 0;
}