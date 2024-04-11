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

const int MAXQ=10000;
const int MAXN=MAXQ+1+5+2;
const int MAXM=6*(MAXQ+1)+5;

typedef struct Q { int lim,cnt; } Q;
bool operator<(const Q &a,const Q &b) { return a.lim<b.lim; }

int nq;
Q q[MAXQ+2];

int n,m,head[MAXN],nxt[2*MAXM],to[2*MAXM],cap[2*MAXM];
void init() { REP(i,n) head[i]=-1; m=0; }

void addedge(int a,int b,int c) {
	//printf("addedge(%d,%d,%d)\n",a,b,c);
	nxt[m]=head[a]; head[a]=m; to[m]=b; cap[m]=c; ++m;
	nxt[m]=head[b]; head[b]=m; to[m]=a; cap[m]=0; ++m;
}
int flow[MAXN],back[MAXN]; bool done[MAXN];
int mf(int s,int t) {
	int ret=0;
	while(true) {
		REP(i,n) flow[i]=0,back[i]=-1,done[i]=false; flow[s]=INT_MAX; back[s]=-2;
		while(true) {
			int idx=-1; REP(i,n) if(!done[i]&&flow[i]>0&&(idx==-1||flow[i]>flow[idx])) idx=i; if(idx==-1) break;
			done[idx]=true; for(int x=head[idx];x!=-1;x=nxt[x]) {
				if(done[to[x]]||flow[idx]<=flow[to[x]]||cap[x]<=flow[to[x]]) continue;
				flow[to[x]]=min(flow[idx],cap[x]); back[to[x]]=x^1;
			}
		}
		if(flow[t]==0) return ret;
		ret+=flow[t];
		for(int x=t;x!=s;x=to[back[x]]) {
			cap[back[x]]+=flow[t];
			cap[back[x]^1]-=flow[t];
		}
	}
}

bool test() {
	REP(i,1<<5) {
		int have=0,need=0; REP(x,5) if(i&(1<<x)) need+=q[nq-1].cnt/5;
		FOR(j,1,nq) {
			int sum=0;
			REP(x,5) {
				if((i&(1<<x))==0) continue;
				int cap=(q[j].lim-x+5)/5-(q[j-1].lim-x+5)/5;
				sum+=cap;
			}
			//printf("\t%d %d\n",sum,q[j].cnt-q[j-1].cnt);
			have+=min(sum,q[j].cnt-q[j-1].cnt);
		}
		//printf("%x: have=%d, need=%d\n",i,have,need);
		if(have<need) return false;
	}
	return true;
}

void run() {
	scanf("%d%d%d",&q[0].cnt,&q[0].lim,&nq); ++nq;
	FOR(i,1,nq) scanf("%d%d",&q[i].lim,&q[i].cnt); q[nq].lim=0,q[nq].cnt=0,++nq;
	sort(q,q+nq);
	//FOR(i,1,nq) printf("%d..%d = %d\n",q[i-1].lim+1,q[i].lim,q[i].cnt-q[i-1].cnt);
	FOR(i,1,nq) if(q[i].cnt<q[i-1].cnt) { printf("unfair\n"); return; }

	/*n=nq-1+5+2; init();
	FOR(i,1,nq) {
		if(q[i].cnt>q[i-1].cnt) addedge(i-1,nq-1+5+0,q[i].cnt-q[i-1].cnt);
		REP(x,5) {
			int cap=(q[i].lim-x+5)/5-(q[i-1].lim-x+5)/5;
			if(cap>0) addedge(nq-1+x,i-1,cap);
		}
	}
	REP(x,5) addedge(nq-1+5+1,nq-1+x,q[nq-1].cnt/5);
	int ret=mf(nq-1+5+1,nq-1+5+0);
	//printf("%d\n",ret);
	printf("%s\n",ret>=q[nq-1].cnt?"fair":"unfair"); */
	printf("%s\n",test()?"fair":"unfair");
}

int main() {
	run();
	return 0;
}