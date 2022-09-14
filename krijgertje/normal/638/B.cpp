

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
const int MAXLEN=26;

bool done[26];
bool have[26];
bool before[26][26];
char nxt[26];

int n;
char s[MAXLEN+1];



void run() {
	memset(done,false,sizeof(done)); memset(have,false,sizeof(have)); memset(before,false,sizeof(before)); memset(nxt,'?',sizeof(nxt));
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",s); int slen=strlen(s);
		REP(j,slen) have[s[j]-'a']=true; REP(j,slen) FOR(k,j+1,slen) before[s[j]-'a'][s[k]-'a']=true; REP(j,slen-1) nxt[s[j]-'a']=s[j+1];
	}
	REP(k,26) REP(i,26) REP(j,26) if(before[i][k]&&before[k][j]) before[i][j]=true;

	while(true) {
		int idx=-1;
		REP(i,26) if(!done[i]&&have[i]) { bool ok=true; REP(j,26) if(!done[j]&&have[j]&&before[j][i]) ok=false; if(ok) { idx=i; break; } }
		if(idx==-1) { puts(""); break; }
		while(true) {
			printf("%c",'a'+idx); done[idx]=true;
			if(nxt[idx]=='?') break; else idx=nxt[idx]-'a';
		}
	}
}

int main() {
	run();
	return 0;
}