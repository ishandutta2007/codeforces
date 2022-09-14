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
const int MAXDIG=6;
const int MAXM=MAXDIG*(MAXDIG-1)/2;
const int MAXMFN=MAXM+MAXDIG+2;
const int MAXMFM=MAXM+2*MAXM+MAXDIG;

typedef struct MF {
	int n,m;
	int head[MAXMFN],nxt[2*MAXMFM],to[2*MAXMFM],cap[2*MAXMFM];
	int back[MAXMFN],flow[MAXMFN];
	int q[MAXMFN],qhead,qtail;
	void init(int _n) { n=_n,m=0; REP(i,n) head[i]=-1; }
	void addedge(int a,int b,int c) {
		nxt[m]=head[a]; head[a]=m; to[m]=b; cap[m]=c; ++m;
		nxt[m]=head[b]; head[b]=m; to[m]=a; cap[m]=0; ++m;
	}
	int calc(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) back[i]=-1,flow[i]=0; qhead=qtail=0;
			back[s]=-2,flow[s]=INT_MAX,q[qhead++]=s;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=head[at];x!=-1;x=nxt[x]) if(back[to[x]]==-1&&cap[x]>0) {
					back[to[x]]=x^1,flow[to[x]]=min(flow[at],cap[x]),q[qhead++]=to[x];
				}
			}
			if(flow[t]==0) break;
			ret+=flow[t];
			for(int x=t;x!=s;x=to[back[x]]) {
				cap[back[x]]+=flow[t];
				cap[back[x]^1]-=flow[t];
			}
		}
		return ret;
	}
} MF;

int n,ndig;
char buff[MAXDIG+1];
int cnt[MAXDIG+1][MAXDIG+1];
int have[MAXDIG+1],fst[MAXDIG+1],at[MAXDIG+1];
int a[MAXM],b[MAXM],m;
MF mf;

int intlen(int x) { int ret=0; while(x>0) x/=10,++ret; return ret; }

void run() {
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	REP(i,n-1) { scanf("%s",buff); int a=strlen(buff); scanf("%s",buff); int b=strlen(buff); if(a>b) swap(a,b); ++cnt[a][b]; }
	memset(have,0,sizeof(have));
	FORE(i,1,n) ++have[intlen(i)]; ndig=intlen(n);
	m=0; FORE(i,1,ndig) FORE(j,i+1,ndig) a[m]=i,b[m]=j,++m;
	fst[1]=1; FORE(i,2,ndig) fst[i]=fst[i-1]*10;
	//FORE(i,1,ndig) { printf("%d: have=%d, fst=%d, cnts",i,have[i],fst[i]); FORE(j,i,ndig) printf(" %d",cnt[i][j]); puts(""); }
	FORE(i,1,ndig) if(cnt[i][i]>have[i]-1) { printf("-1\n"); return; }
	
	REP(i,1<<m) {
		int left=i,cur=1<<1;
		while(true) {
			bool found=false;
			REP(j,m) if(left&(1<<j)) if(((cur&(1<<a[j]))!=0)^((cur&(1<<b[j]))!=0)) if(cnt[a[j]][b[j]]!=0) {
				left^=1<<j; cur|=1<<a[j]; cur|=1<<b[j]; found=true;
				break;
			}
			if(!found) break;
		}
		//printf("%x -> cur=%x, left=%x\n",i,cur,left);
		if(left!=0) continue;
		bool all=true; FORE(j,1,ndig) if(have[j]!=0&&(cur&(1<<j))==0) all=false; if(!all) continue;
		int want=0;
		mf.init(m+ndig+2);
		REP(j,m) { int cap=cnt[a[j]][b[j]]-((i&(1<<j))?1:0); mf.addedge(m+ndig,j,cap); mf.addedge(j,m+a[j]-1,cap); mf.addedge(j,m+b[j]-1,cap); }
		FORE(j,1,ndig) { int cap=have[j]-1-cnt[j][j]; mf.addedge(m+j-1,m+ndig+1,cap); want+=cap; }
		int flow=mf.calc(m+ndig,m+ndig+1);
		if(flow!=want) continue;
		REP(j,m) if(i&(1<<j)) printf("%d %d\n",fst[a[j]],fst[b[j]]);
		FORE(i,1,ndig) at[i]=fst[i]+1;
		FORE(i,1,ndig) REP(k,cnt[i][i]) printf("%d %d\n",fst[i],at[i]++);
		REP(j,mf.m) if(mf.to[j^1]<m&&mf.to[j]>=m&&mf.to[j]<m+ndig) {
			int now=mf.cap[j^1],to=mf.to[j]-m+1,from=a[mf.to[j^1]]+b[mf.to[j^1]]-to;
			REP(k,now) printf("%d %d\n",fst[from],at[to]++);
		}
		return;
	}
	printf("-1\n"); return;
}


int main() {
	run();
	return 0;
}