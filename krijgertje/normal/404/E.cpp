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

int n;
char s[1000003];
int mx[1000001];

void input() {
	gets(s); n=strlen(s);
	if(s[n-1]=='L') REP(i,n) s[i]=s[i]=='L'?'R':'L';
}

int calc1() {
	int end=0; REP(i,n-1) if(s[i]=='L') --end; else ++end;
	memset(mx,-1,sizeof(mx)); int gmx=end;
	for(int at=end,cmx=end,i=n-1;i>=0;--i) {
		if(i<n-1) at-=s[i]=='L'?-1:+1;
		if(at>cmx) cmx=at;
		if(at>gmx) gmx=at;
		if(at<=0) mx[-at]=max(mx[-at],cmx-at);
	}
	if(end>=gmx) return 1;
	int ret=0;
	for(int i=n,cend=end;i>=1;--i) if(mx[i]!=-1) {
		++cend;
//		printf("\t%d: %d (%d)\n",i,cend,mx[i]);
		if(mx[i]>cend+i-1) break;
		if(cend>=gmx) ++ret;
	}
	return ret;
}

int calc2() {
	int ll=0,rr=n+1;
	while(ll<rr) {
		int m=(ll+rr+1)/2;
		int at=0,gmx=0;
		REP(i,n-1) { int nat=at+(s[i]=='L'?-1:+1); if(nat!=-m) at=nat; if(at>gmx) gmx=at; }
		if(at+1>gmx) ll=m; else rr=m-1;
	}
	return ll==n+1?1:ll;
}

void run() {
	input();
	int a1=calc1();
//	int a2=calc2();
//	if(a1!=a2) { REP(i,n) printf("%c",s[i]); puts(""); printf("have=%d, expect=%d\n",a1,a2); exit(1); }
	printf("%d\n",a1);
}

int main() {
	run();
	return 0;
}