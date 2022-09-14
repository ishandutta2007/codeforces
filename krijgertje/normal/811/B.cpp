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

const int MAXN=10000;
const int MAXQ=10000;
typedef struct Q { int l,r,x,pos,idx; } Q;
bool operator<(const Q &a,const Q &b) { return a.x<b.x; }

int n,nq;
int p[MAXN];
Q q[MAXQ];
int r[MAXN];
bool ret[MAXQ];

int b[MAXN+1];
int bget(int x) { ++x; int ret=0; while(x>0) { ret+=b[x]; x-=x&-x; } return ret; }
void bmod(int x) { ++x; while(x<=n) { b[x]++; x+=x&-x; } }

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	REP(i,nq) { scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].pos); --q[i].l,--q[i].r,--q[i].pos; q[i].x=p[q[i].pos],q[i].idx=i; }
	sort(q,q+nq);
	REP(i,n) r[p[i]]=i;

	int at=0; memset(b,0,sizeof(b));
	REP(i,nq) {
		while(at<=q[i].x) bmod(r[at++]);
		int before=bget(q[i].l-1);
		int inside=bget(q[i].r)-before;
		int npos=q[i].l+inside-1;
		//printf("q%d: x=%d pos=%d before=%d inside=%d npos=%d\n",q[i].idx,q[i].x,q[i].pos,before,inside,npos);
		ret[q[i].idx]=q[i].pos==npos;
	}
	REP(i,nq) printf("%s\n",ret[i]?"Yes":"No");
}

int main() {
	run();
	return 0;
}