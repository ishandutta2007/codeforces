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

const int MAXN=5000;
const int MAXM=MAXN-1;

int n;
int head[MAXN];
int nxt[2*MAXM],to[2*MAXM];

int cnt[MAXM+1];
int val[MAXM+1][MAXN+1];


void go(int at,int e) {
	cnt[e]=0,val[e][0]=0;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		int ne=x>>1;
		if(ne==e) continue;
		go(to[x],ne);
		// i1, cnt[e]-i1 / i2,cnt[ne]-i2   i1+i2==i, i1+cnt[ne]-i==+i2
		//nval[e][i]=min(val[e][i1]+val[ne][i-i1],val[e][i1]+1+val[ne][i1+cnt[ne]-i])
		for(int i=cnt[e]+cnt[ne];i>=0;--i) {
			int nval=INT_MAX;
			for(int i1=max(0,i-cnt[ne]);i1<=i&&i1<=cnt[e];++i1) if(val[e][i1]!=INT_MAX&&val[ne][i-i1]!=INT_MAX&&val[e][i1]+val[ne][i-i1]<nval) nval=val[e][i1]+val[ne][i-i1];
			for(int i1=max(0,i-cnt[ne]);i1<=i&&i1<=cnt[e];++i1) if(val[e][i1]!=INT_MAX&&val[ne][i1+cnt[ne]-i]!=INT_MAX&&val[e][i1]+val[ne][i1+cnt[ne]-i]+1<nval) nval=val[e][i1]+val[ne][i1+cnt[ne]-i]+1;
			val[e][i]=nval;
		}
		cnt[e]+=cnt[ne];
	}
	if(cnt[e]==0) cnt[e]=1,val[e][0]=INT_MAX,val[e][1]=0;
	//printf("gone(%d,%d)",at,e); REPE(i,cnt[e]) printf(" %d",val[e][i]); puts("");
}

void run() {
	scanf("%d",&n);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	if(n==2) { printf("1\n"); return; }
	int root=-1; REP(i,n) if(head[i]!=-1&&nxt[head[i]]!=-1) { root=i; break; } assert(root!=-1);

	go(root,n-1);
	printf("%d\n",val[n-1][cnt[n-1]/2]);
}

int main() {
	run();
	return 0;
}