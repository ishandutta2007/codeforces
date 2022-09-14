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

const int MAXDAY=200000;
const int MAXN=200000;

typedef struct X { int cost,idx; } X;
bool operator<(const X &a,const X &b) { return a.cost<b.cost; }

int nday,n,want,have;
int conv[2][MAXDAY];
X x[2][MAXN]; int nx[2]; int z[2],zday[2];
int a,b;

bool can(int cday) {
	REP(i,2) z[i]=INT_MAX,zday[i]=-1;
	REP(i,2) REP(j,cday) if(conv[i][j]<z[i]) z[i]=conv[i][j],zday[i]=j;
	a=0,b=0; int todo=want; ll left=have;
	while(todo>0&&left>0&&(a<nx[0]||b<nx[1])) {
		if(b>=nx[1]||a<nx[0]&&(ll)x[0][a].cost*z[0]<=(ll)x[1][b].cost*z[1]) {
			left-=(ll)x[0][a].cost*z[0]; --todo; ++a;
		} else {
			left-=(ll)x[1][b].cost*z[1]; --todo; ++b;
		}
	}
	//printf("can(%d) -> %d %d -> %d %lld\n",cday,z[0],z[1],todo,left);
	return todo==0&&left>=0;
}

void run() {
	scanf("%d%d%d%d",&nday,&n,&want,&have);
	REP(i,2) REP(j,nday) scanf("%d",&conv[i][j]);
	REP(i,2) nx[i]=0;
	REP(i,n) { int type,cost; scanf("%d%d",&type,&cost),--type; x[type][nx[type]].cost=cost,x[type][nx[type]].idx=i,++nx[type]; }
	REP(i,2) sort(x[i],x[i]+nx[i]);

	int l=0,h=nday+1;
	while(l+1<h) { int m=l+(h-l)/2; if(can(m)) h=m; else l=m; }

	if(h==nday+1) { printf("-1\n"); return; }
	assert(can(h));
	printf("%d\n",h);
	REP(j,a) printf("%d %d\n",x[0][j].idx+1,zday[0]+1);
	REP(j,b) printf("%d %d\n",x[1][j].idx+1,zday[1]+1);
}

int main() {
	run();
	return 0;
}