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

const int MAXN=50;
const int MAXM=500;

int n,m,want;
int head[MAXN],nxt[2*MAXM],to[2*MAXM],ocap[MAXM],cap[2*MAXM];

int flow[MAXN],back[MAXN];
int q[MAXN],qhead,qtail;

int maxflow(int s,int t) {
	int ret=0;
	while(true) {
		qhead=qtail=0; memset(flow,-1,sizeof(flow)); memset(back,-1,sizeof(back));
		flow[s]=INT_MAX,back[s]=-2,q[qhead++]=s;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=head[at];x!=-1;x=nxt[x]) if(cap[x]>0&&flow[to[x]]==-1) {
				flow[to[x]]=min(flow[at],cap[x]),back[to[x]]=x^1,q[qhead++]=to[x];
			}
		}
		if(flow[t]==-1) return ret;
		ret+=flow[t];
		for(int x=t;x!=s;x=to[back[x]]) {
			cap[back[x]]+=flow[t];
			cap[back[x]^1]-=flow[t];
		}
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&want);
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; ocap[i]=c;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	double l=0,h=1000000;
	REP(i,100) {
		double mid=l+(h-l)/2;
		REP(j,m) cap[2*j+0]=(int)min(floor(ocap[j]/mid),1.0*want),cap[2*j+1]=0;
		if(maxflow(0,n-1)>=want) l=mid; else h=mid;
	}
	double ret=(l+(h-l)/2)*want;
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}