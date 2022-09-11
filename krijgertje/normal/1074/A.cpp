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

const int MAXN=100000;
const int MAXCOORD=1000000000;

int nver,nhor;
int verx[MAXN];
int horx1[MAXN],horx2[MAXN],hory[MAXN];

pair<int,int> e[2*MAXN]; int ne;


int solve() {
	int cur=0; ne=0;
	REP(i,nhor) {
		if(horx1[i]!=1) continue;
		++cur;
		if(horx2[i]+1<=MAXCOORD) e[ne++]=MP(horx2[i]+1,-1);
	}
	REP(i,nver) {
		e[ne++]=MP(verx[i]+1,+1);
	}
	sort(e,e+ne);
	int ret=cur;
	for(int l=0,r=l;l<ne;l=r) {
		while(r<ne&&e[l].first==e[r].first) ++r;
		FOR(i,l,r) cur+=e[i].second;
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d",&nver,&nhor);
	REP(i,nver) scanf("%d",&verx[i]);
	REP(i,nhor) scanf("%d%d%d",&horx1[i],&horx2[i],&hory[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}