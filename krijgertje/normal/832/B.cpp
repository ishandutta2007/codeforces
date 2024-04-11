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

const int MAXLEN=100000;

char good[26+1]; int ngood;
bool isgood[26];

char p[MAXLEN+1]; int plen,staridx;
int nq;
char q[MAXLEN+1]; int qlen;

bool match(char cp,char cq) { return cp=='?'&&isgood[cq-'a']||cp!='?'&&cp==cq; }

bool solve() {
	if(staridx==-1) {
		if(qlen!=plen) return false;
		REP(i,plen) if(!match(p[i],q[i])) return false;
		return true;
	} else {
		int nbef=staridx,naft=plen-staridx-1,nmid=qlen-nbef-naft;
		if(qlen<nbef+naft) return false;
		REP(i,nbef) if(!match(p[i],q[i])) return false;
		REP(i,naft) if(!match(p[plen-i-1],q[qlen-i-1])) return false;
		REP(i,nmid) if(isgood[q[nbef+i]-'a']) return false;
		return true;
	}
}


void run() {
	scanf("%s",good); ngood=strlen(good); REP(i,26) isgood[i]=false; REP(i,ngood) isgood[good[i]-'a']=true;
	scanf("%s",p); plen=strlen(p); staridx=-1; REP(i,plen) if(p[i]=='*') staridx=i;
	scanf("%d",&nq);
	REP(i,nq) { scanf("%s",q); qlen=strlen(q); printf("%s\n",solve()?"YES":"NO"); }
}

int main() {
	run();
	return 0;
}