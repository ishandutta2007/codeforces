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
const int MAXLEN=100;

int n,ndel;
char s[MAXN][MAXLEN+1];
bool del[MAXN];
char ret[MAXLEN+1];

bool solve() {
	int retlen=-1;
	REP(i,n) if(del[i]) { int clen=strlen(s[i]); if(retlen!=-1&&retlen!=clen) return false; retlen=clen; }
	REP(j,retlen) {
		ret[j]='!';
		REP(i,n) if(del[i]) { char c=s[i][j]; if(ret[j]=='!') ret[j]=c; else if(ret[j]!=c) ret[j]='?'; }
	}
	ret[retlen]='\0';
	REP(i,n) if(!del[i]&&strlen(s[i])==retlen) { bool match=true; REP(j,retlen) if(ret[j]!='?'&&ret[j]!=s[i][j]) match=false; if(match) return false; }
	return true;
}

void run() {
	scanf("%d%d",&n,&ndel); REP(i,n) scanf("%s",s[i]);
	REP(i,n) del[i]=false; REP(i,ndel) { int x; scanf("%d",&x); --x; del[x]=true; }
	if(!solve()) printf("No\n"); else printf("Yes\n%s\n",ret);
}

int main() {
	run();
	return 0;
}