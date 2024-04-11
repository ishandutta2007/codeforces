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

const int MAXN=50000;
typedef struct E { long double z; int idx,type; } E;
bool operator<(const E &a,const E &b) { if(a.z!=b.z) return a.z<b.z; if(a.type!=b.type) return a.type>b.type; return a.idx<b.idx; }

int n,want;
double cx,cy;
double a[MAXN],b[MAXN];
E e[2*MAXN]; int ne;

int bit[2*MAXN+1];
int pos[MAXN];
void bitmod(int x,int by) { ++x; /*printf("bitmod(%d,%d)\n",x,by);*/ while(x<=ne) { bit[x]+=by; x+=x&-x; } }
int bitget(int x) { ++x; /*printf("bitget(%d)=",x);*/ int ret=0; while(x>0) { ret+=bit[x]; x-=x&-x; } /*printf("%d\n",ret);*/ return ret; }

void build(long double r) {
	ne=0;
	REP(i,n) {
		// (1+a*a)*x*x+(2*a*b)*x+(b*b-r*r)=0
		// (+-sqrt(r*r*(1+a*a)-a*b)-a*b)/(1+a*a)
		long double aa=(long double)a[i],bb=(long double)b[i];
		long double d=r*r*(1+aa*aa)-bb*bb;
		if(d<0) continue;
		long double x1=(-sqrt(d)-aa*bb)/(1+aa*aa),x2=(+sqrt(d)-aa*bb)/(1+aa*aa);
		long double y1=aa*x1+bb,y2=aa*x2+bb;
		long double z1=y1>=0?x1+r:3*r-x1,z2=y2>=0?x2+r:3*r-x2;
		//printf("%d: (%Lf,%Lf) (%Lf,%Lf) -> %Lf..%Lf\n",i,x1,y1,x2,y2,z1,z2);
		e[ne].z=min(z1,z2),e[ne].idx=i,e[ne].type=+1,++ne;
		e[ne].z=max(z1,z2),e[ne].idx=i,e[ne].type=-1,++ne;
	}
	sort(e,e+ne);
	//REP(i,ne) printf("%lf: %c%d\n",e[i].z,e[i].type==1?'+':'-',e[i].idx);
}

int calccnt(long double r) {
	build(r);
	memset(bit,0,sizeof(bit));
	memset(pos,-1,sizeof(pos)); REP(i,ne) if(e[i].type==-1) pos[e[i].idx]=i;
	int ret=0;
	REP(i,ne) {
		if(e[i].type==+1) {
			ret+=bitget(pos[e[i].idx]);
			bitmod(pos[e[i].idx],+1);
		} else {
			bitmod(pos[e[i].idx],-1);
		}
	}
	//printf("%.15lf = %d\n",r,ret);
	return ret;
}

double inter(int i,int j) {
	// x=(b[j]-b[i])/(a[i]-a[j])
	double x=(b[j]-b[i])/(a[i]-a[j]),y=a[i]*x+b[i];
	return sqrt(x*x+y*y);
}
double calcsum(double r) {
	build(r);
	memset(pos,-1,sizeof(pos)); REP(i,ne) if(e[i].type==-1) pos[e[i].idx]=i;
	double ret=0; int cnt=0;
	map<int,int> state;
	REP(i,ne) {
		if(e[i].type==+1) {
			int to=pos[e[i].idx];
			for(map<int,int>::iterator it=state.begin();it!=state.end()&&it->first<to;++it) {
				//printf("%d %d\n",e[i].idx,it->second);
				++cnt,ret+=inter(e[i].idx,it->second);
			}
			state.insert(MP(to,e[i].idx));
		} else {
			state.erase(i);
		}
	}
	ret+=(want-cnt)*r;
	return ret;
}

void run() {
	scanf("%d%lf%lf%d",&n,&cx,&cy,&want); cx/=1000,cy/=1000;
	REP(i,n) scanf("%lf%lf",&a[i],&b[i]),a[i]/=1000,b[i]/=1000;
	REP(i,n) b[i]+=a[i]*cx-cy;
	//REP(i,n) printf("y=%lfx+%lf\n",a[i],b[i]);

	int n0=0; REP(i,n) if(fabs(b[i])<1e-12) ++n0;
	ll cnt0=(ll)n0*(n0-1)/2; if(cnt0>=want) { printf("0\n"); return; }

	long double l=0,h=1; // (l,h]
	while(calccnt(h)<want) l=h,h+=h;
	REP(i,70) { long double m=l+(h-l)/2; if(calccnt(m)<want) l=m; else h=m; }

	double ret=calcsum(l);
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}