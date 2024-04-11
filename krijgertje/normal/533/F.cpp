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

const int MAXLEN=200000;

int slen,tlen;
char s[MAXLEN+1],t[MAXLEN+1];

int prv[26];
int sdiff[MAXLEN];
int tdiff[MAXLEN+1];

int nxt[MAXLEN+1];

int fst[26],nfst;
int at[26],nat;
int pos[26];

int ret[MAXLEN],nret;

void advance(int &tidx,int &sidx) {
	while(nxt[tidx]!=tidx&&(tdiff[tidx]==-1||tdiff[tidx]!=sdiff[sidx])) tidx=nxt[tidx];
	if(tdiff[tidx]!=-1&&tdiff[tidx]==sdiff[sidx]) ++tidx;
	++sidx;
}

int to[26];
bool ok(int idx) {
	REP(j,nat) if(tdiff[at[j]]!=-1) return false;
	REP(i,26) to[i]=-1;
	REP(i,nfst) {
		int a=t[fst[i]]-'a',b=s[idx+fst[i]]-'a';
		if(to[a]!=-1&&to[a]!=b) return false;
		if(to[b]!=-1&&to[b]!=a) return false;
		to[a]=b; to[b]=a;
	}
	//REP(i,26) if(to[i]!=-1) printf("%c->%c ",'a'+i,'a'+to[i]); puts("");
	return true;
}

void run() {
	scanf("%d%d%s%s",&slen,&tlen,&s,&t);

	REP(i,26) prv[i]=-1;
	REP(i,slen) { int x=s[i]-'a'; sdiff[i]=prv[x]==-1?-1:i-prv[x]; prv[x]=i; }
	REP(i,26) prv[i]=-1;
	REP(i,tlen) { int x=t[i]-'a'; tdiff[i]=prv[x]==-1?-1:i-prv[x]; prv[x]=i; } tdiff[tlen]=-1;

	REPE(i,tlen) {
		if(i==0||tdiff[i-1]==-1) { nxt[i]=i; continue; }
		nxt[i]=nxt[i-1];
		while(nxt[nxt[i]]!=nxt[i]&&tdiff[nxt[i]]!=tdiff[i-1]) nxt[i]=nxt[nxt[i]];
		if(nxt[i]+1!=i&&tdiff[nxt[i]]==tdiff[i-1]) ++nxt[i];
	}

	//REPE(i,tlen) printf("%2d ",i); puts("");
	//REP(i,tlen) printf("%2d ",tdiff[i]); puts("");
	//REPE(i,tlen) printf("%2d ",nxt[i]); puts("");
	//REP(i,slen) printf("%2d ",sdiff[i]); puts("");

	nfst=0; REP(i,tlen) if(tdiff[i]==-1) fst[nfst++]=i;
	nat=0; REP(i,tlen) if((i==0||tdiff[i-1]==-1)&&tdiff[i]!=-1) at[nat++]=i;
	REP(j,nat) { pos[j]=at[j]; while(pos[j]<tlen&&tdiff[pos[j]]!=-1) advance(at[j],pos[j]); }

	nret=0;
	REPE(i,slen-tlen) {
		//printf("%d:",i); REP(j,nat) printf(" %d/%d",at[j],pos[j]); puts("");
		if(ok(i)) ret[nret++]=i;
		if(i<slen-tlen) REP(j,nat) advance(at[j],pos[j]);
	}

	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");

}

int main() {
	run();
	return 0;
}