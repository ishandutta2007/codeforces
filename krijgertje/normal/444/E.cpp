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

typedef struct N { int have,need; } N;
typedef struct E { int a,b,len; } E;
typedef struct G { int par,rnk,have,need; } G;

int n;
N node[3000];
E edge[2999];
G grp[3000];

int p[2999];
bool elencmp(const int &a,const int &b) { return edge[a].len<edge[b].len; }
int find(int a) { if(grp[a].par==a) return a; return grp[a].par=find(grp[a].par); }

void run() {
	scanf("%d",&n);
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		edge[i].a=a; edge[i].b=b; edge[i].len=c;
	}
	REP(i,n) node[i].need=1,scanf("%d",&node[i].have);

	REP(i,n-1) p[i]=i; sort(p,p+n-1,elencmp);
	REP(i,n) grp[i].par=i,grp[i].rnk=0,grp[i].have=node[i].have,grp[i].need=node[i].need;
	int sumhave=0; REP(i,n) sumhave+=node[i].have;

	int ret=0;
	REP(i,n-1) {
		ret=edge[p[i]].len;
		int a=find(edge[p[i]].a),b=find(edge[p[i]].b);
		if(a!=b) {
			if(grp[a].need+grp[b].need>sumhave-grp[a].have-grp[b].have) break;
			if(grp[a].rnk<grp[b].rnk) swap(a,b);
			grp[a].have+=grp[b].have,grp[a].need+=grp[b].need,grp[b].par=a,grp[a].rnk+=grp[a].rnk==grp[b].rnk?1:0;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}