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
#include <chrono>
#include <random>
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

const int MAXLEN=10000;

char t[MAXLEN+1]; int len;
char ans[MAXLEN+1];

int qid[MAXLEN],resid[MAXLEN],nid;
int cnt[MAXLEN];

char q[MAXLEN+1];
char res[MAXLEN+1];

int resmp[MAXLEN][26],nresmp;

int respos[MAXLEN];

bool local=false;
char sloc[MAXLEN+1];
int ploc[MAXLEN];


void query() {
	if(!local) {
		printf("? %s\n",q); fflush(stdout);
		scanf("%s",res);
	} else {
		REP(i,len) res[i]=q[ploc[i]]; res[len]='\0';
	}
}

void solve() {
	REP(i,len) qid[i]=0,resid[i]=0; nid=1;
	while(nid<len) {
		REP(i,nid) cnt[i]=0;
		REP(i,len) { q[i]='a'+cnt[qid[i]]%26; ++cnt[qid[i]]; } q[len]='\0';
		query();
		//printf("%s -> %s\n",q,res);
		REP(i,len) REP(j,26) resmp[i][j]=-1; nresmp=0;
		REP(i,len) { int j=res[i]-'a'; if(resmp[resid[i]][j]==-1) resmp[resid[i]][j]=nresmp++; resid[i]=resmp[resid[i]][j]; }
		REP(i,len) { int j=q[i]-'a'; assert(resmp[qid[i]][j]!=-1); qid[i]=resmp[qid[i]][j]; }
		nid=nresmp;
	}
	//printf("qid  :"); REP(i,len) printf(" %d",qid[i]); puts("");
	//printf("resid:"); REP(i,len) printf(" %d",resid[i]); puts("");

	REP(i,len) respos[resid[i]]=i;
	REP(i,len) ans[i]=t[respos[qid[i]]]; ans[len]='\0';
}

void run() {
	scanf("%s",t); len=strlen(t);
	solve();
	printf("! %s\n",ans); fflush(stdout);
}


void stress() {
	std::mt19937 rnd(12391);
	local=true;
	REP(rep,10) {
		len=rnd()%MAXLEN+1;
		REP(i,len) sloc[i]='a'+rnd()%26; sloc[len]='\0';
		REP(i,len) ploc[i]=i; REP(i,len) swap(ploc[i],ploc[rnd()%(i+1)]);
		REP(i,len) t[i]=sloc[ploc[i]]; t[len]='\0';
		solve();
		bool ok=true; REP(i,len) if(ans[i]!=sloc[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("%d: err\n",rep);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}