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

const int MAXN=100000;
const int MAXLEN=100000;

int n;
char s[MAXLEN+1];
int off[MAXN+1];
int len[MAXN];

int nxt[26]; bool any[26]; bool fst[26]; bool done[26];

char ret[27]; int nret;


bool solve() {
	REP(i,26) any[i]=false,nxt[i]=-1,fst[i]=true,done[i]=false;
	REP(i,n) FOR(j,off[i],off[i+1]) {
		int x=s[j]-'a';
		any[x]=true;
		if(j+1<off[i+1]) {
			int y=s[j+1]-'a';
			if(nxt[x]!=-1&&nxt[x]!=y) return false;
			nxt[x]=y; fst[y]=false;
		}
	}
	nret=0;
	REP(i,26) if(any[i]&&fst[i]) {
		int x=i; while(x!=-1&&!done[x]) { ret[nret++]='a'+x; done[x]=true; x=nxt[x]; } if(x!=-1) return false;
	}
	REP(i,26) if(any[i]&&!done[i]) return false;
	return true;
}

void run() {
	scanf("%d",&n);
	off[0]=0; REP(i,n) { scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i]; }
	if(!solve()) { printf("NO\n"); return; }
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}