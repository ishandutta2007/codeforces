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

const int MAXN=1000000;
const int MAXQ=1000000;
typedef struct Q { int l,r,idx; } Q;
bool operator<(const Q &a,const Q &b) { if(a.l!=b.l) return a.l>b.l; return a.idx<b.idx; }

int n,nq;
int a[MAXN];
int b[MAXN+1];
int v[MAXN],nv;
Q q[MAXQ];
int ret[MAXQ];
int fst[MAXN];

int fw[MAXN+1];
void fwmod(int idx,int val) { /*printf("modifying %d by %d\n",idx,val);*/ ++idx; while(idx<=n) { fw[idx]^=val; idx+=idx&-idx; } }
int fwget(int idx) { /*printf("getting %d",idx);*/ ++idx; int ret=0; while(idx>0) { ret^=fw[idx]; idx-=idx&-idx; } /*printf(" -> %d\n",ret);*/ return ret; }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	b[0]=0; REP(i,n) b[i+1]=b[i]^a[i];
	nv=0; REP(i,n) v[nv++]=a[i]; sort(v,v+nv); nv=unique(v,v+nv)-v;
	REP(i,nv) fst[i]=-1;
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,--q[i].r,q[i].idx=i;
	sort(q,q+nq);

	int upto=n; memset(fw,0,sizeof(fw));
	REP(i,nq) {
		while(upto>q[i].l) {
			--upto;
			int pos=lower_bound(v,v+nv,a[upto])-v;
			if(fst[pos]!=-1) fwmod(fst[pos],a[upto]);
			fst[pos]=upto;
			fwmod(fst[pos],a[upto]);
		}
		ret[q[i].idx]=fwget(q[i].r)^b[q[i].r+1]^b[q[i].l];
	}
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}