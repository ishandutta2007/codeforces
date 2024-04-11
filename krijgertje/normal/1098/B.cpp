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

const int MAXCELLS=300000;
const char CHARS[4]={'A','C','G','T'};

int h,w;
char s[MAXCELLS+1];
char ans[MAXCELLS+1];

char t[MAXCELLS+1];

void solve() {
	//REP(x,h) REP(y,w) ans[x*w+y]=tolower(s[x*w+y]); ans[h*w]='\0';
	int best=INT_MAX; REP(i,h*w) ans[i]='?'; t[h*w]=ans[h*w]='\0';

	REP(a,4) FOR(b,a+1,4) REP(c,4) FOR(d,c+1,4) {
		if(c==a||c==b||d==a||d==b) continue;
		REP(x,h) {
			int u=x%2==0?a:c,v=x%2==0?b:d;
			int match[2]; match[0]=match[1]=0; REP(y,w) if(s[x*w+y]==CHARS[u]) ++match[y%2]; else if(s[x*w+y]==CHARS[v]) ++match[1-y%2];
			if(match[1]>match[0]) swap(u,v); REP(y,w) t[x*w+y]=y%2==0?CHARS[u]:CHARS[v];
		}
		{ int cur=0; REP(i,h*w) if(s[i]!=t[i]) ++cur; if(cur<best) { best=cur; REP(i,h*w) ans[i]=t[i]; } }
		REP(y,w) {
			int u=y%2==0?a:c,v=y%2==0?b:d;
			int match[2]; match[0]=match[1]=0; REP(x,h) if(s[x*w+y]==CHARS[u]) ++match[x%2]; else if(s[x*w+y]==CHARS[v]) ++match[1-x%2];
			if(match[1]>match[0]) swap(u,v); REP(x,h) t[x*w+y]=x%2==0?CHARS[u]:CHARS[v];
		}
		{ int cur=0; REP(i,h*w) if(s[i]!=t[i]) ++cur; if(cur<best) { best=cur; REP(i,h*w) ans[i]=t[i]; } }
	}
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",s+x*w);
	solve();
	REP(x,h) printf("%.*s\n",w,ans+x*w);
}

int main() {
	run();
	return 0;
}