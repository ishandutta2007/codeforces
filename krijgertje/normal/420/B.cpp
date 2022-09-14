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

int nperson,nmsg;

char type[100000]; int id[100000];

bool seen[100000];
bool online[100000]; int nonline;
bool can[100000]; int only;

int ret[100000],nret;

void run() {
	scanf("%d%d",&nperson,&nmsg);
	REP(i,nmsg) { scanf(" %c%d",&type[i],&id[i]); --id[i]; }

	memset(seen,false,sizeof(seen));
	memset(online,false,sizeof(online)); nonline=0;
	REP(i,nmsg) {
		int x=id[i];
		if(seen[x]) continue;
		seen[x]=true;
		if(type[i]=='-') { online[x]=true; ++nonline; }
	}
	//REP(x,nperson) printf("%d: seen=%d, online=%d\n",x+1,seen[x]?1:0,online[x]?1:0);
	REP(x,nperson) can[x]=!seen[x]||nonline==0||online[x]; only=-1;
	REP(i,nmsg) {
		int x=id[i];
		if(type[i]=='+') {
			assert(!online[x]);
			if(nonline==0) only=only==-1||only==x?x:-2;
			if(nonline!=0) can[x]=false;
			online[x]=true; ++nonline;
		} else {
			assert(online[x]);
			if(nonline==1) only=only==-1||only==x?x:-2;
			if(nonline>=2) can[x]=false;
			online[x]=false; --nonline;
		}
	}
	//printf("only=%d\n",only+1);
	REP(x,nperson) if(seen[x]&&only!=-1&&only!=x) can[x]=false;
	nret=0; REP(x,nperson) if(can[x]) ret[nret++]=x+1;
	printf("%d\n",nret);
	if(nret>=1) { REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts(""); }
}

int main() {
	run();
	return 0;
}