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

int na,nb;

int solve() {
	int ntot=na+nb;

	// cnt=floor(ntot/sz) -> (ntot)/(cnt+1)<sz<=ntot/cnt
	
	int ret=0;
	for(int cnt=1;;cnt=ntot/(ntot/(cnt+1))) {
		//printf("cnt=%d\n",cnt);
		int x=na%cnt,y=nb%cnt;
		if((ntot-x-y)%cnt==0&&(na-x)%cnt==0&&(nb-y)%cnt==0) {
			int mxsz=(ntot-x-y)/cnt,mxa=(na-x)/cnt,mxb=(nb-y)/cnt;
			if(x+y<mxsz&&x<=mxa&&y<=mxb) {
				int mxk=min(min(na/cnt+nb/cnt,(mxsz-x-y-1)/(cnt+1)),(mxa-x)/(cnt+1)+(mxb-y)/(cnt+1));
				//printf("cnt=%d->mxsz=%d mxk=%d\n",cnt,mxsz,mxk);
				ret+=mxk+1;
			}
		}
		if(cnt==ntot) break;
	}
	return ret;
}

void run() {
	scanf("%d%d",&na,&nb);
	printf("%d\n",solve());
}

int solvestupid() {
	int ntot=na+nb,ret=0;
	FORE(sz,1,ntot) {
		int rem=ntot%sz,cnt=ntot/sz;
		int x=na%cnt,y=nb%cnt,ca=(na-x)/cnt,cb=(nb-y)/cnt;
		while(ca+cb>sz) if(x+cnt<=na&&x+cnt<=ca-1) x+=cnt,--ca; else if(y+cnt<=nb&&y+cnt<=cb-1) y+=cnt,--cb; else break;
		if(x+y==rem&&ca+cb==sz&&x<=ca&&y<=cb) ++ret;
	}
	return ret;
}

void stress() {
	for(na=1;na<=1000;++na) for(nb=1;nb<=1000;++nb) {
		int have=solve();
		int want=solvestupid();
		if(have==want) { if(nb==1) printf("."); continue; }
		printf("err: na=%d nb=%d have=%d want=%d\n",na,nb,have,want);
	}

}

int main() {
	run();
	//stress();
	return 0;
}