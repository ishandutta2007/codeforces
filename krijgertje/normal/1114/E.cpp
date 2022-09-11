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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MINVAL=0;
const int MAXVAL=1000000000;
const int MAXQ=60;
const int MAXN=1000000;

int n;
int nq;

bool local;
int locval[MAXN];

bool querygreaterequal(int x) {
	if(x==0) return true;
	++nq;
	if(!local) {
		printf("> %d\n",x-1); fflush(stdout);
		int ret; scanf("%d",&ret); return ret==1;
	} else {
		REP(i,n) if(locval[i]>x-1) return true;
		return false;
	}
}

int queryvalue(int idx) {
	++nq;
	if(!local) {
		printf("? %d\n",idx+1); fflush(stdout);
		int ret; scanf("%d",&ret); return ret;
	} else {
		assert(0<=idx&&idx<n);
		return locval[idx];
	}
}

pair<int,int> solve() {
	nq=0;
	int lo=MINVAL,hi=MAXVAL+1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(querygreaterequal(mi)) lo=mi; else hi=mi; } int mx=lo;
	//printf("mx=%d\n",mx);

	std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
	vector<int> vals; while(nq<MAXQ) { int idx=rnd()%n; vals.PB(queryvalue(idx)); }
	sort(vals.begin(),vals.end()); vals.erase(unique(vals.begin(),vals.end()),vals.end());
	//printf("vals:"); REPSZ(i,vals) printf(" %d",vals[i]); puts("");

	int g=0; FORSZ(i,1,vals) g=gcd(g,vals[i]-vals[0]);
	return MP(mx-g*(n-1),g);
}

void run() {
	scanf("%d",&n);
	pair<int,int> ans=solve();
	printf("! %d %d\n",ans.first,ans.second); fflush(stdout);
}

void stress() {
	std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
	REP(rep,1000) {
		int a=rnd()%10,d=rnd()%10;
		n=rnd()%2==0?rnd()%10+2:rnd()%(MAXN-1)+2;
		REP(i,n) locval[i]=a+i*d;
		REP(i,n) { int idx=rnd()%(i+1); swap(locval[i],locval[idx]); }
		local=true; pair<int,int> have=solve(),want=MP(a,d);
		if(have==want) { printf("."); continue; }
		printf("err (rep=%d)\n",rep);
		printf("have=(%d,%d)\n",have.first,have.second);
		printf("want=(%d,%d)\n",want.first,want.second);
		exit(0);
	}
}

int main() {
	run();
	//stress();
	return 0;
}