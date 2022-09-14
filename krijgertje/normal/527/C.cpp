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

const int MAXN=200000;
const int MAXSZ=200000;
const char types[2]={'H','V'};

int w,h,n;
char type[MAXN]; int pos[MAXN];

ll ret[MAXN];
int prv[MAXSZ+1],nxt[MAXSZ+1];

void run() {
	scanf("%d%d%d",&w,&h,&n);
	REP(i,n) scanf(" %c%d",&type[i],&pos[i]);

	REP(i,n) ret[i]=1;
	REP(t,2) {
		int sz=types[t]=='H'?h:w;
		REPE(i,sz) prv[i]=nxt[i]=-2; prv[0]=nxt[0]=prv[sz]=nxt[sz]=-1;
		REP(i,n) if(type[i]==types[t]) nxt[pos[i]]=prv[pos[i]]=-1;
		{ int lst=0; for(int i=1;i<=sz;++i) if(prv[i]==-1) { prv[i]=lst; lst=i; } }
		{ int lst=sz; for(int i=sz-1;i>=0;--i) if(nxt[i]==-1) { nxt[i]=lst; lst=i; } }
		int now=0; FORE(i,1,sz) if(prv[i]>=0&&i-prv[i]>now) now=i-prv[i];
		//printf("prv:"); REPE(i,sz) printf("%2d ",prv[i]); puts("");
		//printf("nxt:"); REPE(i,sz) printf("%2d ",nxt[i]); puts("");
		for(int i=n-1;i>=0;--i) {
			ret[i]*=now;
			if(type[i]==types[t]) {
				int x=pos[i]; assert(prv[x]>=0&&nxt[x]>=0);
				if(nxt[x]-prv[x]>now) now=nxt[x]-prv[x];
				nxt[prv[x]]=nxt[x]; prv[nxt[x]]=prv[x]; prv[x]=nxt[x]=-2;
			}
		}
	}
	REP(i,n) cout<<ret[i]<<endl;
}

int main() {
	run();
	return 0;
}