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

char s[MAXLEN+1]; int slen;

int nxt[MAXLEN];
int fst[MAXLEN];

int head[2][2],nsame[MAXLEN];
void join(int i,int j) { int a=s[fst[i]]=='L'?0:1,b=s[i]=='L'?1:0,c=s[fst[j]]=='L'?0:1,d=s[j]=='L'?1:0; assert(b==c); nxt[i]=fst[j]; fst[j]=fst[i]; nsame[j]=head[a][d]; head[a][d]=j; }
void printall() { REP(i,2) REP(j,2) for(int x=head[i][j];x!=-1;x=nsame[x]) { printf("%c%c:%d..%d:","LR"[i],"LR"[j],fst[x],x); for(int y=fst[x];y!=-1;y=nxt[y]) printf(" %d",y); puts(""); } }

void run() {
	scanf("%s",s); slen=strlen(s);

	int ret=slen-1;
	int atL=0,atR=0;
	REP(i,slen) {
		nxt[i]=-1;
		if(s[i]=='L') {
			if(atL<=i) atL=i+1;
			while(atL<slen&&s[atL]!='R') ++atL;
			if(atL<slen) nxt[i]=atL++,--ret;
		}
		if(s[i]=='R') {
			if(atR<=i) atR=i+1;
			while(atR<slen&&s[atR]!='L') ++atR;
			if(atR<slen) nxt[i]=atR++,--ret;
		}
	}
	REP(i,slen) fst[i]=i;
	REP(i,slen) if(nxt[i]!=-1) fst[nxt[i]]=fst[i];

	REP(i,2) REP(j,2) head[i][j]=-1;
	REP(i,slen) if(nxt[i]==-1) { int a=s[fst[i]]=='L'?0:1,b=s[i]=='L'?1:0; nsame[i]=head[a][b]; head[a][b]=i; }

	while(head[0][1]!=-1&&head[1][0]!=-1) { int a=head[0][1],b=head[1][0]; head[0][1]=nsame[a],head[1][0]=nsame[b]; join(a,b); }
	while(head[0][0]!=-1&&head[1][1]!=-1) {
		int a=head[0][0],b=head[1][1]; head[0][0]=nsame[a],head[1][1]=nsame[b];
		if(fst[a]>fst[b]) swap(a,b);
		int c=fst[a]; fst[a]=nxt[c]; nxt[c]=fst[b]; fst[b]=c; join(a,b);
	}
	while(head[0][0]!=-1&&nsame[head[0][0]]!=-1) { int a=head[0][0],b=nsame[a]; head[0][0]=nsame[b]; join(a,b); }
	while(head[1][1]!=-1&&nsame[head[1][1]]!=-1) { int a=head[1][1],b=nsame[a]; head[1][1]=nsame[b]; join(a,b); }
	if(head[0][1]!=-1&&head[1][1]!=-1) { int a=head[0][1],b=head[1][1]; head[0][1]=nsame[a],head[1][1]=nsame[b]; join(a,b); }
	if(head[0][0]!=-1&&head[0][1]!=-1) { int a=head[0][0],b=head[0][1]; head[0][0]=nsame[a],head[0][1]=nsame[b]; join(a,b); }
	if(head[1][0]!=-1&&head[0][0]!=-1) { int a=head[1][0],b=head[0][0]; head[1][0]=nsame[a],head[0][0]=nsame[b]; join(a,b); }
	if(head[1][1]!=-1&&head[1][0]!=-1) { int a=head[1][1],b=head[1][0]; head[1][1]=nsame[a],head[1][0]=nsame[b]; join(a,b); }

	int s=-1; REP(i,2) REP(j,2) if(head[i][j]!=-1) { assert(s==-1); int a=head[i][j]; head[i][j]=nsame[a]; s=fst[a]; }

	printf("%d\n",ret);
	for(int x=s;x!=-1;x=nxt[x]) { if(x!=s) printf(" "); printf("%d",x+1); } puts("");
}

int main() {
	run();
	return 0;
}