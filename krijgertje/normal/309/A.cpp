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

int n,len,t;
int offset[1000000];

int dist(int a,int b) { if(b>a) return b-a; else return b-a+len; }

void run(int casenr) {
	scanf("%d%d%d",&n,&len,&t);
	REP(i,n) scanf("%d",&offset[i]);
	len*=2; t*=2; REP(i,n) offset[i]*=2;

	double ret=0;
	int hlen=len/2; int times=t/hlen; ret+=.5*times*n*(n-1)/2; t%=hlen;

	int at=0;
	REP(i,n) {
		if(at==i) { ++at; if(at==n) at=0; }
		while(at!=i&&dist(offset[i],offset[at])<=2*t) { ++at; if(at==n) at=0; }
		int cnt=at>i?at-i-1:at-i+n-1;
		ret+=.25*cnt;
	}
	
	printf("%.2lf\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}