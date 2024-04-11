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

const int MAXBAM=100000;
const int MAXDAY=5000;
typedef struct X { int h,a; } X;

int nbam,nday,nhit,maxdec;
X bam[MAXBAM];

ll need[MAXDAY];

//bool debug;
bool ok(ll want) {
	int cnt=0;
	REP(i,nday) need[i]=0;
	REP(i,nbam) {
		//?=nday-want/bam[i].a
		//x<=want-bam[i].a*(nday-?)
		ll atday=nday,atwant=want;
		while(true) {
			ll step=atwant/bam[i].a;
			ll today=atday-step;
			if(today<0) today=0;
			atwant-=bam[i].a*(atday-today);
			atday=today;
			if(atday==0) break;
			need[atday]++; if(++cnt>nhit*nday) return false;
			atwant+=maxdec;
			//if(debug) printf("%d: %lld -> %lld\n",i,atday,atwant);
		}
		if(bam[i].h>atwant) {
			//if(debug) printf("%d: %lld -> %d to %lld\n",i,atday,bam[i].h,atwant);
			ll cur=(bam[i].h-atwant+maxdec-1)/maxdec;
			need[atday]+=cur; if((cnt+=cur)>nhit*nday) return false;
		}
	}
	for(int i=nday-1;i>=0;--i) {
		need[i-1]+=need[i];
		if(need[i]>nhit*(nday-i)) return false;
	}
	return true;
}

void run() {
	scanf("%d%d%d%d",&nbam,&nday,&nhit,&maxdec);
	REP(i,nbam) scanf("%d%d",&bam[i].h,&bam[i].a);

	ll l=0,h=0;
	REP(i,nbam) { ll cur=bam[i].h+(ll)nday*bam[i].a; if(bam[i].a-1>l) l=bam[i].a-1; if(cur>h) h=cur; }
	//debug=true; ok(11); debug=false;
	while(l+1<h) {
		ll m=l+(h-l)/2;
		//printf("%lld..%lld -> %lld\n",l,h,m);
		if(ok(m)) h=m; else l=m;
	}
	cout<<h<<endl;
}

int main() {
	run();
	return 0;
}