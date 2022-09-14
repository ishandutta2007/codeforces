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

const int MAXN=100000;
const int MAXQ=100000;
const int MAXXOR=(1<<20)-1;
typedef struct Q { int l,r,idx; int b; } Q;
bool operator<(const Q &x,const Q &y) { if(x.b!=y.b) return x.b<y.b; return x.r<y.r; }

int n,nq,want,BSZ;
int a[MAXN],b[MAXN+1];
Q q[MAXQ]; ll ret[MAXQ];

int cnt[MAXXOR+1]; ll val;
void inc(int idx) {
	//printf("\tinc(%d)\n",idx);
	val+=cnt[b[idx]^want]; ++cnt[b[idx]];
}
void dec(int idx) {
	//printf("\tdec(%d)\n",idx);
	--cnt[b[idx]]; val-=cnt[b[idx]^want];
}

void run() {
	scanf("%d%d%d",&n,&nq,&want); BSZ=(int)sqrt(n);
	REP(i,n) scanf("%d",&a[i]);
	b[0]=0; REP(i,n) b[i+1]=a[i]^b[i];
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].r,q[i].idx=i,q[i].b=q[i].l/BSZ; sort(q,q+nq);
	for(int at=0,to=0;at<nq;at=to) {
		while(to<nq&&q[at].b==q[to].b) ++to;
		//printf("queries %d..%d\n",at,to-1);
		memset(cnt,0,sizeof(cnt)); val=0; int l=q[at].r,r=q[at].r; inc(l);
		FOR(i,at,to) {
			//printf("%d..%d\n",q[i].l,q[i].r-1);
			while(r<q[i].r) inc(++r);
			while(l<q[i].l) dec(l++);
			while(l>q[i].l) inc(--l);
			ret[q[i].idx]=val;
		}
	}
	REP(i,nq) printf("%I64d\n",ret[i]);
}

int main() {
	run();
	return 0;
}