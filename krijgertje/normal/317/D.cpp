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

int g[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

void update(int &ret,int by,int reason) {
	ret^=by;
//	printf("update %d (%d)\n",by,reason);
}

void run(int casenr) {
	int n; scanf("%d",&n);
	int ret=0;
	set<int> skip;
	int left=n;
	FORE(i,1,n) {
		if(i*i>n) { if(left%2==1) update(ret,1,-1); break; }
		--left;
		if(i==1) { update(ret,1,i); continue; }
		if(skip.count(i)) continue;
		int cnt=1;
		for(ll x=(ll)i*i;x<=n;x*=i) { ++cnt; if(x*x<=n) skip.insert((int)x); else --left; }
		update(ret,g[cnt],i);
	}
	printf("%s\n",ret!=0?"Vasya":"Petya");
}

map<int,int> mem;

int calc(int mask) {
	if(mask==0) return 0;
	if(mem.count(mask)) return mem[mask];
//	printf("mask = %x\n",mask);
	int have=0;
	for(int i=1;i<=30&&(1<<i)<=mask;++i) if(mask&(1<<i)) {
		int nmask=mask;
		for(int j=1;i*j<=30&&(1<<(i*j))<=mask;++j) nmask=nmask&~(1<<(i*j));
//		printf("\t%d: %x => %x\n",i,mask,nmask);
		have|=1<<calc(nmask);
	}
	int ret=0; while(have&(1<<ret)) ++ret;
//	printf("%x = %d\n",mask,ret);
	return mem[mask]=ret;
}

void preprocess() {
	for(int i=0;i<30;++i) { int mask=0; FORE(j,1,i) mask|=1<<j; printf("%d: %d\n",i,calc(mask)); }
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//preprocess();
	run(1);
	return 0;
}