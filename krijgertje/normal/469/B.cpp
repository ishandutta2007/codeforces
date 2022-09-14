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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int na,nb,lt,ht;
int la[50],ha[50];
int lb[50],hb[50];

int upto[1001];

void run() {
	scanf("%d%d%d%d",&na,&nb,&lt,&ht);
	REP(i,na) scanf("%d%d",&la[i],&ha[i]);
	REP(i,nb) scanf("%d%d",&lb[i],&hb[i]);

	FORE(i,lt,ht) upto[i]=-1;
	REP(i,na) REP(j,nb) {
		// for which t: la[i]..ha[i] intersects lb[j]+t..hb[j]+t
		// la[i]<=hb[j]+t and lb[j]+t<=ha[i] -> t in la[i]-hb[j]..ha[i]-lb[j]
		int clt=max(lt,la[i]-hb[j]),cht=min(ht,ha[i]-lb[j]);
		if(clt<=cht&&cht>upto[clt]) upto[clt]=cht;
	}
	FOR(i,lt,ht) if(upto[i]>upto[i+1]) upto[i+1]=upto[i];
	int ret=0; FORE(i,lt,ht) if(upto[i]>=i) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}