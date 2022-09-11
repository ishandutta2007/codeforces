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

const int MAXN=50000;
const int MAXKEY=1000;

int n,s,want;
int key[MAXKEY],nkey;
int val[MAXKEY],nxt[MAXKEY];

bool local=false; int nq=0;
int locval[MAXN],locnxt[MAXN];
void query(int x,int &val,int &nxt) {
	printf("? %d\n",x+1); fflush(stdout);
	++nq;
	if(!local) {
		scanf("%d%d",&val,&nxt);
		if(val==-1&&nxt==-1) { printf("err\n"); exit(0); }
		if(nxt!=-1) --nxt;
	} else {
		val=locval[x],nxt=locnxt[x];
	}
}

int solve() {
	nkey=min(n,MAXKEY);
	srand(time(NULL));
	FOR(i,1,nkey) key[i]=(rand()%1000*1000+rand()%1000)%(n-nkey+1); sort(key,key+nkey); REP(i,nkey) key[i]+=i; bool found=false; REP(i,nkey) if(key[i]==s) found=true; if(!found) key[nkey/2]=s; sort(key,key+nkey);
	REP(i,nkey) query(key[i],val[i],nxt[i]);
	int ans=-1,ansidx=-1,from=-1,fromidx=-1;
	REP(i,nkey) {
		if(val[i]>=want) { if(ans==-1||val[i]<ans) ans=val[i],ansidx=key[i]; }
		if(val[i]<want) { if(from==-1||val[i]>from) from=val[i],fromidx=nxt[i]; }
	}
	//printf("ans=%d ansidx=%d from=%d fromidx=%d\n",ans,ansidx,from,fromidx);
	int at=fromidx;
	while(at!=-1&&at!=ansidx) {
		int curval,curnxt; query(at,curval,curnxt);
		if(curval>=want) { ans=curval,ansidx=at; break; }
		at=curnxt;
	}
	return ans;
}

void run() {
	scanf("%d%d%d",&n,&s,&want); --s;
	printf("! %d\n",solve());
}

int sval[MAXN];
int p[MAXN];
void stress() {
	int maxq=0;
	REP(rep,10000) {
		n=MAXN; local=true; nq=0;
		REP(i,n) sval[i]=rand()%1000*1000000+rand()%1000*1000+rand(); sort(sval,sval+n); REP(i,n) sval[i]+=i;
		want=rand()%1000*1000000+rand()%1000*1000+rand();
		REP(i,n) p[i]=i; REP(i,n) { int idx=rand()%(i+1); swap(p[i],p[idx]); }
		s=p[0]; REP(i,n) locval[p[i]]=sval[i],locnxt[p[i]]=i==n-1?-1:p[i+1];

		//REP(i,n) printf("%d: sval=%d p=%d\n",i,sval[i],p[i]);
		//for(int at=s,i=0;i<n;++i,at=locnxt[at]) printf("%d: %d=%d -> %d\n",i,at,locval[at],locnxt[at]);
		//return;

		int ret=solve();
		int chk=-1; REP(i,n) if(sval[i]>=want&&(chk==-1||sval[i]<chk)) chk=sval[i];
		if(ret!=chk) printf("ret=%d chk=%d\n",ret,chk); else if(nq>maxq) printf("nq=%d\n",nq),maxq=nq; else printf(".");
	}
}

int main() {
	//stress();
	run();
	return 0;
}