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

const int MAXK=2000000;
const int MOD=1000000007;

int pmn[MAXK+1];

int n,k;

vector<pair<int,int> > dv;

int sum;
int mempw[MAXK+1];

int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int getpw(int x) { if(mempw[x]!=-1) return mempw[x]; return mempw[x]=pw(x,n); }
void process(int d,int ck,int mu) {
	//printf("ck=%d d=%d mu=%d\n",ck,d,mu);
	int was=ck/d-1,now=ck/d;
	sum=(sum+(ll)mu*(getpw(now)-getpw(was)))%MOD; if(sum<0) sum+=MOD;
}

void rec(int mlt,int at,int ck,int sgn) {
	if(at>=SZ(dv)) { process(mlt,ck,sgn); return; }
	rec(mlt,at+1,ck,sgn);
	rec(mlt*dv[at].first,at+1,ck,-sgn);
	//REPE(i,dv[at].second) { rec(mlt,at+1); mlt*=dv[at].first; }
}

void run() {
	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXK) if(pmn[i]==-1) for(int j=i;j<=MAXK;j+=i) if(pmn[j]==-1) pmn[j]=i;

	scanf("%d%d",&n,&k);
	memset(mempw,-1,sizeof(mempw));
	sum=0;
	int ans=0;
	FORE(i,1,k) {
		dv.clear();
		int x=i; while(x!=1) { int y=pmn[x],cnt=0; while(pmn[x]==y) x/=y,++cnt; dv.PB(MP(y,cnt)); }
		rec(1,0,i,1);
		//printf("dv:"); REPSZ(j,dv) printf(" %d*%d",dv[j].first,dv[j].second); puts("");
		//printf("%d: %d\n",i,sum);
		ans=(ans+(sum^i))%MOD;
	}
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}