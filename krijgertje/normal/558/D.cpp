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

const int MAXQ=100000;
const int MAXE=2*MAXQ+2;

typedef struct E { ll x; int by; } E;
bool operator<(const E &a,const E &b) { return a.x<b.x; }

int h,nq;
E e[MAXE]; int ne;

void run() {
	scanf("%d%d",&h,&nq);

	ne=0; e[ne].x=1LL<<(h-1),e[ne].by=0,++ne; e[ne].x=1LL<<h,e[ne].by=0,++ne;
	REP(qi,nq) {
		int lvl; ll l,r; int ans; cin>>lvl>>l>>r>>ans;
		l<<=(h-lvl); ++r; r<<=(h-lvl);
		if(ans==0) {
			e[ne].x=l,e[ne].by=+1,++ne; e[ne].x=r,e[ne].by=-1,++ne;
		} else {
			e[0].by++; e[ne].x=l,e[ne].by=-1,++ne; e[ne].x=r,e[ne].by=+1,++ne; e[1].by--;
		}
	}
	sort(e,e+ne);
//	REP(i,ne) printf("%lld: %d\n",e[i].x,e[i].by);

	int cur=e[0].by; ll cnt=0,fst=-1;
	FOR(i,1,ne) {
		if(e[i].x!=e[i-1].x&&cur==0) {
			//printf("%lld..%lld\n",e[i-1].x,e[i].x);
			cnt+=e[i].x-e[i-1].x;
			if(fst==-1) fst=e[i-1].x;
		}
		cur+=e[i].by;
	}
	if(cnt==0) printf("Game cheated!\n");
	if(cnt==1) cout<<fst<<endl;
	if(cnt>=2) printf("Data not sufficient!\n");
}

int main() {
	run();
	return 0;
}