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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,want,have;
int p[3000];

bool been[3000];

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&p[i]); --p[i]; }
	scanf("%d",&want);

	have=0;
	memset(been,false,sizeof(been));
	REP(i,n) if(!been[i]) {
		int len=0;
		for(int at=i;!been[at];at=p[at],++len) been[at]=true;
		have+=len-1;
	}

	if(have<=want) {
		printf("%d\n",want-have);
		bool first=true;
		while(have<want) {
			int x=0;
			memset(been,false,sizeof(been));
			for(int at=x;!been[at];at=p[at]) been[at]=true;
			int y=-1;
			REP(i,n) if(!been[i]) { y=i; break; }
			assert(y!=-1);
			if(first) first=false; else printf(" "); printf("%d %d",x+1,y+1);
			swap(p[x],p[y]);
			++have;
		}
		puts("");
	} else {
		printf("%d\n",have-want);
		bool first=true;
		while(have>want) {
			int x=-1;
			REP(i,n) if(p[i]!=i) { x=i; break; }
			assert(x!=-1);
			memset(been,false,sizeof(been));
			for(int at=x;!been[at];at=p[at]) been[at]=true;
			int y=-1;
			REP(i,n) if(been[i]&&i!=x) { y=i; break; }
			assert(y!=-1);
			if(first) first=false; else printf(" "); printf("%d %d",x+1,y+1);
			swap(p[x],p[y]);
			--have;
		}
		puts("");
	}

}

int main() {
	run();
	return 0;
}