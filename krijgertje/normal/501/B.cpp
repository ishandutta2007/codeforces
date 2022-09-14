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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int nq;
char from[1000][21],to[1000][21];

int nid,idfrom[1000],idto[1000];

void run() {
	scanf("%d",&nq);
	REP(qi,nq) scanf("%s%s",&from[qi],&to[qi]);
	nid=0;
	REP(qi,nq) {
		int cur=-1; REP(i,nid) if(strcmp(from[qi],to[idto[i]])==0) { cur=i; break; } if(cur==-1) { cur=nid++; idfrom[cur]=qi; }
		idto[cur]=qi;
	}
	printf("%d\n",nid);
	REP(i,nid) printf("%s %s\n",from[idfrom[i]],to[idto[i]]);

}

int main() {
	run();
	return 0;
}