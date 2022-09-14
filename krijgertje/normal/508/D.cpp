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

const int N=62*62;
const int MAXM=200000;

int m;
int fst[N];
int outdeg[N],indeg[N];
int nxt[MAXM];
int to[MAXM];

char s[4];
int encode(char c) { if(islower(c)) return c-'a'; else if(isupper(c)) return 26+c-'A'; else if(isdigit(c)) return 52+c-'0'; else assert(false); return -1; }
char decode(int x) { if(x<26) return 'a'+x; else if(x<52) return 'A'+x-26; else if(x<62) return '0'+x-52; else assert(false); return '?'; }

int a[MAXM+1],na;
int b[MAXM+1],nb;

void run() {
	scanf("%d",&m);
	REP(i,N) fst[i]=-1,outdeg[i]=0,indeg[i]=0;
	REP(i,m) {
		scanf("%s",s);
		int a=encode(s[0])*62+encode(s[1]);
		int b=encode(s[1])*62+encode(s[2]);
		nxt[i]=fst[a]; fst[a]=i; to[i]=b;
		++outdeg[a],++indeg[b];
	}
//	REP(i,N) if(fst[i]!=-1) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	int s=-1,t=-1;
	na=nb=0;
	REP(i,N) {
		if(outdeg[i]>indeg[i]) { if(s==-1) s=i; else { printf("NO\n"); return; } }
		if(indeg[i]>outdeg[i]) { if(t==-1) t=i; else { printf("NO\n"); return; } }
	}
	assert(s==-1&&t==-1||s!=-1&&t!=-1);
	if(s==-1&&t==-1) REP(i,N) if(fst[i]!=-1) {
		s=to[fst[i]]; t=i; fst[i]=nxt[fst[i]]; b[nb++]=s; break;
	}

	a[na++]=s; 
	while(true) {
		int at=a[na-1];
//		printf("at=%d\n",at);
		if(at==t) break;
		if(fst[at]==-1) { printf("NO\n"); return; }
		a[na++]=to[fst[at]];
		fst[at]=nxt[fst[at]];
	}
	while(na>0) {
		int at=a[na-1];
//		printf("at=%d\n",at);
		while(fst[at]!=-1) {
			a[na++]=to[fst[at]];
			fst[at]=nxt[fst[at]];
			while(true) {
				int at2=a[na-1];
//				printf("\tat2=%d\n",at2);
				if(at2==at) break;
				if(fst[at2]==-1) { printf("NO\n"); return; }
				a[na++]=to[fst[at2]];
				fst[at2]=nxt[fst[at2]];
			}
		}
		b[nb++]=at; --na;
	}


	if(nb<m+1) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%c%c",decode(b[nb-1]/62),decode(b[nb-1]%62));
	for(int i=nb-2;i>=0;--i) printf("%c",decode(b[i]%62));
	puts("");
}

int main() {
	run();
	return 0;
}