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

const int MAXN=100;
const int MAXNAMELEN=10;
const int MAXM=100;
const int MAXMSGLEN=100;
char buff[1000];

int n,m;
char name[MAXN][MAXNAMELEN+1];
int by[MAXM]; char msg[MAXM][MAXMSGLEN+1];
set<int> cant[MAXM];
int ret[MAXM];

bool solve() {
	REP(i,m) ret[i]=by[i];
	while(true) {
		bool change=false;
		REP(i,m) if(ret[i]==-1&&SZ(cant[i])>=n) return false;
		REP(i,m) if(ret[i]==-1&&SZ(cant[i])>=n-1) {
			REP(j,n) if(cant[i].count(j)==0) { ret[i]=j; break; } assert(ret[i]!=-1);
			if(i-1>=0) cant[i-1].insert(ret[i]); if(i+1<m) cant[i+1].insert(ret[i]); change=true;
		}
		if(!change) break;
	}
	REP(i,m) if(ret[i]==-1) {
		REP(j,n) if(cant[i].count(j)==0) { ret[i]=j; break; } assert(ret[i]!=-1);
		if(i-1>=0) cant[i-1].insert(ret[i]); if(i+1<m) cant[i+1].insert(ret[i]);
	}
	return true;
}

void run() {
	gets(buff); sscanf(buff,"%d",&n);
	gets(buff); { char *at=buff; REP(i,n) { while(*at==' ') ++at; sscanf(at,"%s",name[i]); at+=strlen(name[i]); } }
	gets(buff); sscanf(buff,"%d",&m);
	REP(i,m) { gets(buff); int col=0; while(buff[col]!='\0'&&buff[col]!=':') ++col; buff[col]='\0'; by[i]=-1; REP(j,n) if(strcmp(name[j],buff)==0) by[i]=j; strcpy(msg[i],buff+col+1); }
	REP(i,m) { 
		cant[i].clear(); char *at=msg[i];
		while(*at!='\0') {
			if(!isalpha(*at)&&!isdigit(*at)) { ++at; continue; }
			int len=0; while(isalpha(*at)||isdigit(*at)) buff[len++]=*at,++at; buff[len]='\0';
			REP(j,n) if(strcmp(name[j],buff)==0) cant[i].insert(j);
		}
		if(i!=0&&by[i-1]!=-1) cant[i].insert(by[i-1]);
		if(i+1<m&&by[i+1]!=-1) cant[i].insert(by[i+1]);
	}

	//REP(i,n) printf("%d=%s\n",i,name[i]);
	//REP(i,m) { printf("%s (by %d,forbidden:",msg[i],by[i]); REPSZ(j,cant[i]) printf(" %d",cant[i][j]); printf(")\n"); }

	if(!solve()) { printf("Impossible\n"); return; }
	REP(i,m) printf("%s:%s\n",name[ret[i]],msg[i]);
}

int main() {
	gets(buff); int n; sscanf(buff,"%d",&n); FORE(i,1,n) run();
	return 0;
}