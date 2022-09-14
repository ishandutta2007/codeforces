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

const int MAXLEN=1000;
const int MAXHAVE=50;
const int MAXNEED=MAXHAVE/2;
const int MAXX=1+MAXNEED*MAXLEN;
const int MOD=1000000007;

typedef struct X { bool match; int nxt[10]; int fail; } X;
void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
void sub(int &a,const int &b) { if((a-=b)<0) a+=MOD; }

char s[MAXLEN+1]; int slen;
char l[MAXHAVE+1],h[MAXHAVE+1]; int havelen,needlen;

X x[MAXX]; int nx,root;
int q[MAXX],qtail,qhead;
int createx() { x[nx].match=false; x[nx].fail=-1; REP(k,10) x[nx].nxt[k]=-1; return nx++; }

int ways[MAXHAVE+1][MAXX][2][2];

int calc(char *lim,bool caneq) {
	memset(ways,0,sizeof(ways));
	ways[0][root][0][1]=1;
	REP(i,havelen) REP(j,nx) REP(res,2) REP(eq,2) if(ways[i][j][res][eq]!=0) REP(k,10) {
		if(eq&&k>lim[i]-'0') continue;
		int nj=x[j].nxt[k];
		inc(ways[i+1][nj][res||x[nj].match?1:0][eq&&k==lim[i]-'0'?1:0],ways[i][j][res][eq]);
	}
	int ret=0;
	REP(j,nx) REP(eq,caneq?2:1) inc(ret,ways[havelen][j][1][eq]);
	return ret;
}

void run() {
	scanf("%s%s%s",s,l,h); slen=strlen(s); havelen=strlen(l); needlen=havelen/2;

	nx=0;
	root=createx();
	REPE(i,slen-needlen) {
		int at=root;
		REP(j,needlen) {
			int k=s[i+j]-'0';
			if(x[at].nxt[k]==-1) x[at].nxt[k]=createx();
			at=x[at].nxt[k];
		}
		x[at].match=true;
	}
	qhead=qtail=0;
	REP(k,10) if(x[root].nxt[k]==-1) x[root].nxt[k]=root; else q[qhead++]=x[root].nxt[k],x[x[root].nxt[k]].fail=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		REP(k,10) if(x[at].nxt[k]!=-1) {
			q[qhead++]=x[at].nxt[k];
			x[x[at].nxt[k]].fail=x[x[at].fail].nxt[k];
			x[x[at].nxt[k]].match|=x[x[at].fail].match;
		} else {
			x[at].nxt[k]=x[x[at].fail].nxt[k];
		}
	}

	int ret=0;
	inc(ret,calc(h,true));
	sub(ret,calc(l,false));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}