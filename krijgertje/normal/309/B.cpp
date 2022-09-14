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

char buff[6000003];

int nwords,nrows,ncols;
int wordstart[1000000];
int wordlen[1000000];

int nxt[1000001];
int cur[1000001];
int res[1000000];

void input() {
	gets(buff); sscanf(buff,"%d%d%d",&nwords,&nrows,&ncols);
	gets(buff);
	int spos=0,wpos=0;
	while(true) {
		if(isalpha(buff[spos])) {
			if(wordlen[wpos]==0) wordstart[wpos]=spos;
			++wordlen[wpos];
		} else {
			if(wordlen[wpos]!=0) ++wpos;
			if(buff[spos]!=' ') break;
		}
		++spos;
	}
}

void calcnxt() {
	int linelen=0,wpos=0;
	REP(i,nwords) {
		while(wpos<nwords&&linelen+wordlen[wpos]+(linelen==0?0:1)<=ncols) { linelen+=wordlen[wpos]+(linelen==0?0:1); ++wpos; }
		nxt[i]=wpos;
		if(wpos==i) ++wpos;
		else {
			linelen-=wordlen[i];
			if(wpos!=i+1) linelen--;
		}
	}
	nxt[nwords]=nwords;
//	REP(i,nwords) printf("nxt: %d -> %d\n",i,nxt[i]);
}

void calcres() {
	REP(i,nwords) res[i]=i;
	REPE(i,nwords) cur[i]=nxt[i];
	for(int i=0;(1<<i)<=nrows;++i) {
//		printf("\t%d\n",1<<i);
		if(nrows&(1<<i)) {
			REP(j,nwords) res[j]=cur[res[j]];
//			REP(j,nwords) printf("\tres: %d -> %d\n",j,res[j]);
		}
		REP(j,nwords) cur[j]=cur[cur[j]];
//		REPE(j,nwords) printf("\cur: %d -> %d\n",j,cur[j]);
	}
//	REP(i,nwords) printf("res: %d -> %d\n",i,res[i]);
}

void output() {
	int wpos=0;
	FOR(i,1,nwords) if(res[i]-i>res[wpos]-wpos) wpos=i;
	REP(r,nrows) {
		FOR(i,wpos,nxt[wpos]) {
			if(i!=wpos) printf(" ");
			REP(j,wordlen[i]) printf("%c",buff[wordstart[i]+j]);
		}
		puts("");
		wpos=nxt[wpos];
	}
}

void run(int casenr) {
	input();
	calcnxt();
	calcres();
	output();
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}