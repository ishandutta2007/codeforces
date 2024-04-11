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

typedef struct T {
	char name[21];
	int state[100];
} T;
T teams[2];

int nq;

void run() {
	scanf("%s%s",&teams[0].name,&teams[1].name);
	REP(i,2) memset(teams[i].state,0,sizeof(teams[i].state));
	scanf("%d",&nq);
	REP(qi,nq) {
		int min; char t; int who; char type; scanf("%d %c%d %c",&min,&t,&who,&type);
		int tidx=t=='h'?0:1; int delta=type=='y'?1:2;
		if(teams[tidx].state[who]>=2) continue;
		teams[tidx].state[who]+=delta;
		if(teams[tidx].state[who]>=2) printf("%s %d %d\n",teams[tidx].name,who,min); 
	}

}

int main() {
	run();
	return 0;
}