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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXLEN=6;

int n;
char name[MAXN][MAXLEN+1]; int pname[MAXN];
int ex[MAXN];

int usedby[MAXN+1];
vector<int> wrongex,wrongrg,otherex,otherrg;

pair<int,int> ret[MAXN+1]; int nret;

int parse(char *s) { int ret=0; for(int i=0;s[i]!='\0';++i) if(!isdigit(s[i])||s[i]=='0'&&i==0) return -1; else ret=ret*10+s[i]-'0'; if(ret<1||ret>n) return -1; return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s%d",&name[i],&ex[i]);

	FORE(i,1,n) usedby[i]=-1;
	REP(i,n) { int x=parse(name[i]); pname[i]=x; if(x==-1) continue; usedby[x]=i; }
	int numex=0; REP(i,n) numex+=ex[i];
	int unusedex=-1,unusedrg=-1;
	FORE(i,1,numex) if(usedby[i]==-1) { unusedex=i; break; }
	FORE(i,numex+1,n) if(usedby[i]==-1) { unusedrg=i; break; }
	REP(i,n) if(ex[i]==1) if(pname[i]==-1) otherex.PB(i); else if(pname[i]>numex) wrongex.PB(i);
	REP(i,n) if(ex[i]==0) if(pname[i]==-1) otherrg.PB(i); else if(pname[i]<=numex) wrongrg.PB(i);

	//printf("unused: %d/%d, numex=%d\n",unusedex,unusedrg,numex);
	//printf("usedby:"); FORE(i,1,n) printf(" %d",usedby[i]); puts("");
	//printf("wrongex:"); REPSZ(i,wrongex) printf(" %s",name[wrongex[i]]); puts("");
	//printf("otherex:"); REPSZ(i,otherex) printf(" %s",name[otherex[i]]); puts("");
	//printf("wrongrg:"); REPSZ(i,wrongrg) printf(" %s",name[wrongrg[i]]); puts("");
	//printf("otherrg:"); REPSZ(i,otherrg) printf(" %s",name[otherrg[i]]); puts("");

	nret=0; int altname=-1;
	while(true) {
		if(unusedex!=-1&&SZ(wrongex)>0) {
			int at=wrongex.back(); wrongex.pop_back(); ret[nret++]=MP(at,unusedex); usedby[unusedex]=at; usedby[pname[at]]=-1; unusedex=-1; unusedrg=pname[at];
			continue;
		}
		if(unusedrg!=-1&&SZ(wrongrg)>0) {
			int at=wrongrg.back(); wrongrg.pop_back(); ret[nret++]=MP(at,unusedrg); usedby[unusedrg]=at; usedby[pname[at]]=-1; unusedrg=-1; unusedex=pname[at];
			continue;
		}
		if(SZ(wrongex)>0&&SZ(wrongrg)>0) {
			int at=wrongex.back(); wrongex.pop_back(); ret[nret++]=MP(at,n+1); usedby[pname[at]]=-1; unusedrg=pname[at]; otherex.PB(at); altname=at;
			continue;
		}
		break;
	}
	if(SZ(wrongex)>0&&SZ(wrongrg)==0) FORE(i,1,numex) if(SZ(wrongex)>0&&usedby[i]==-1) {
		int at=wrongex.back(); wrongex.pop_back(); ret[nret++]=MP(at,i); usedby[i]=at; usedby[pname[at]]=-1;
	}
	if(SZ(wrongrg)>0&&SZ(wrongex)==0) FORE(i,numex+1,n) if(SZ(wrongrg)>0&&usedby[i]==-1) {
		int at=wrongrg.back(); wrongrg.pop_back(); ret[nret++]=MP(at,i); usedby[i]=at; usedby[pname[at]]=-1;
	}
	FORE(i,1,numex) if(SZ(otherex)>0&&usedby[i]==-1) {
		int at=otherex.back(); otherex.pop_back(); ret[nret++]=MP(at==altname?-1:at,i); usedby[i]=at;
	}
	FORE(i,numex+1,n) if(SZ(otherrg)>0&&usedby[i]==-1) {
		int at=otherrg.back(); otherrg.pop_back(); ret[nret++]=MP(at,i); usedby[i]=at;
	}
	
	printf("%d\n",nret);
	REP(i,nret) if(ret[i].first==-1) printf("move %d %d\n",n+1,ret[i].second); else printf("move %s %d\n",name[ret[i].first],ret[i].second);
}

int main() {
	run();
	return 0;
}