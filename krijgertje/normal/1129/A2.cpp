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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXSTATION=5000;
const int MAXCANDY=20000;

int nstation,ncandy;
int a[MAXCANDY],b[MAXCANDY];
ll ans[MAXSTATION];

int mndst[MAXSTATION],cnt[MAXSTATION];

ll c[MAXSTATION];
ll cmxrgt[MAXSTATION];
ll cmxlft[MAXSTATION];

void solve() {
	REP(i,nstation) cnt[i]=0,mndst[i]=INT_MAX;
	REP(i,ncandy) { int fr=a[i],to=b[i],dst=(to-fr+nstation)%nstation; ++cnt[fr],mndst[fr]=min(mndst[fr],dst); }
	
	// max(d[s,i]+(cnt[i]-1)*nstation+mndst[i] | cnt[i]>0)
	
	REP(i,nstation) c[i]=cnt[i]==0?LLONG_MIN:i+(ll)(cnt[i]-1)*nstation+mndst[i];
	cmxrgt[nstation-1]=c[nstation-1]; for(int i=nstation-2;i>=0;--i) cmxrgt[i]=max(c[i],cmxrgt[i+1]);
	cmxlft[0]=LLONG_MIN; FOR(i,1,nstation) cmxlft[i]=max(c[i-1],cmxlft[i-1]);
	//printf("c:"); REP(i,nstation) if(c[i]==LLONG_MIN) printf(" -"); else printf(" %lld",c[i]); puts("");
	
	REP(i,nstation) {
		ll before=cmxlft[i]==LLONG_MIN?LLONG_MIN:cmxlft[i]+nstation-i;
		ll after=cmxrgt[i]==LLONG_MIN?LLONG_MIN:cmxrgt[i]-i;
		ans[i]=max(before,after);
	}
}

void run() {
	scanf("%d%d",&nstation,&ncandy);
	REP(i,ncandy) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	solve();
	REP(i,nstation) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}