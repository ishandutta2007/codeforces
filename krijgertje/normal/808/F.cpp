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
const int MAXC=100000;
const int MAXGN=2+MAXN;
const int MAXGM=MAXN+(MAXN/2)*((MAXN+1)/2);
typedef struct R { int p,c,l; } R;
bool operator<(const R &a,const R &b) { return a.l<b.l; }

int n,want;
R r[MAXN];
bool isp[2*MAXC+1];

typedef struct G {
	int n,m,head[MAXGN],nxt[2*MAXGM],to[2*MAXGM],cap[2*MAXGM];
	void init(int _n) { n=_n; REP(i,n) head[i]=-1; m=0; }
	void addedge(int a,int b,int c) {
		//printf("addedge(%d,%d,%d)\n",a,b,c);
		nxt[m]=head[a]; head[a]=m; to[m]=b; cap[m]=c; ++m;
		nxt[m]=head[b]; head[b]=m; to[m]=a; cap[m]=0; ++m;
	}
	int flow[MAXGN],back[MAXGN]; bool done[MAXGN];
	int q[MAXGN],qhead,qtail;
	int mf(int s,int t) {
		int ret=0,iter=0;
		while(true) {
			++iter;
			REP(i,n) flow[i]=0,back[i]=-1,done[i]=false; qhead=qtail=0; flow[s]=INT_MAX; back[s]=-2; q[qhead++]=s; done[s]=true;
			while(qtail<qhead) {
				int idx=q[qtail++]; for(int x=head[idx];x!=-1;x=nxt[x]) {
					if(done[to[x]]||flow[idx]<=flow[to[x]]||cap[x]<=flow[to[x]]) continue;
					flow[to[x]]=min(flow[idx],cap[x]); back[to[x]]=x^1; done[to[x]]=true; q[qhead++]=to[x];
				}
			}
			if(flow[t]==0) break;
			ret+=flow[t];
			for(int x=t;x!=s;x=to[back[x]]) {
				cap[back[x]]+=flow[t];
				cap[back[x]^1]-=flow[t];
			}
		}
		//printf("iter=%d\n",iter);
		return ret;
	}
} G;
G g;

bool test(int cnt) {
	vector<pair<int,int> > odd,even; int bestone=-1;
	REP(i,cnt) {
		if(r[i].c==1) { if(bestone==-1||r[i].p>bestone) bestone=r[i].p; }
		else if(r[i].c%2==1) odd.PB(MP(r[i].c,r[i].p));
		else even.PB(MP(r[i].c,r[i].p));
	}
	if(bestone!=-1) odd.PB(MP(1,bestone));
	//printf("odd: "); REPSZ(i,odd) printf("(%d,%d)",odd[i].first,odd[i].second); puts("");
	//printf("evn: "); REPSZ(i,even) printf("(%d,%d)",even[i].first,even[i].second); puts("");
	int sid=0,tid=1; vector<int> oddid(SZ(odd)); REPSZ(i,odd) oddid[i]=2+i; vector<int> evenid(SZ(even)); REPSZ(i,even) evenid[i]=2+SZ(odd)+i;
	g.init(2+SZ(odd)+SZ(even));
	REPSZ(i,odd) g.addedge(sid,oddid[i],odd[i].second);
	REPSZ(i,even) g.addedge(evenid[i],tid,even[i].second);
	REPSZ(i,odd) REPSZ(j,even) if(isp[odd[i].first+even[j].first]) g.addedge(oddid[i],evenid[j],want+1);
	int have=0; REPSZ(i,odd) have+=odd[i].second; REPSZ(i,even) have+=even[i].second;
	int cost=g.mf(sid,tid); have-=cost;
	//printf("%d - %d = %d\n",have+cost,cost,have);
	return have>=want;
}

void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d%d%d",&r[i].p,&r[i].c,&r[i].l); sort(r,r+n);
	REPE(i,2*MAXC) isp[i]=true; isp[0]=isp[1]=false; FORE(i,2,2*MAXC) if(isp[i]) for(int j=i+i;j<=2*MAXC;j+=i) isp[j]=false;

	//test(3); return;

	if(!test(n)) { printf("-1\n"); return; }
	int l=0,h=n;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(!test(m)) l=m; else h=m;
	}
	printf("%d\n",r[h-1].l);
}

int main() {
	run();
	return 0;
}