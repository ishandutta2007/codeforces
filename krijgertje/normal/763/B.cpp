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

const int MAXN=500000;
const int MAXM=4*MAXN;
typedef struct R { int x1,y1,x2,y2; } R;
typedef struct E { int z,l,r,idx; } E;
bool operator<(const E &p,const E &q) { if(p.z!=q.z) return p.z<q.z; return p.l<q.l; }

int n,m;
R r[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int deg[MAXN];

E a[MAXN],b[MAXN];

int rem[MAXN],ret[MAXN];
int q[MAXN],qhead,qtail;


void addedge(int p,int q) { gnxt[2*m+0]=ghead[p],ghead[p]=2*m+0,gto[2*m+0]=q,++deg[p]; gnxt[2*m+1]=ghead[q],ghead[q]=2*m+1,gto[2*m+1]=p,++deg[q]; ++m; }
void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
	REP(i,n) ghead[i]=-1,deg[i]=0; m=0;

	REP(t,2) {
		//printf("t=%d\n",t);
		REP(i,n) a[i].z=r[i].x2,a[i].l=r[i].y1,a[i].r=r[i].y2,a[i].idx=i,b[i].z=r[i].x1,b[i].l=r[i].y1,b[i].r=r[i].y2,b[i].idx=i;
		sort(a,a+n); sort(b,b+n);
		//printf("\ta:"); REP(i,n) printf(" %d",a[i].idx); puts("");
		//printf("\tb:"); REP(i,n) printf(" %d",b[i].idx); puts("");
		int at=0;
		REP(i,n) {
			while(at<n&&b[at].z<a[i].z) ++at;
			while(at<n&&b[at].z==a[i].z&&b[at].r<=a[i].l) ++at;
			while(at<n&&b[at].z==a[i].z&&b[at].l<a[i].r) {
				//printf("\tedge %d to %d\n",a[i].idx,b[at].idx);
				addedge(a[i].idx,b[at].idx);
				if(b[at].r<=a[i].r) ++at; else break;
			}
			//printf("\tno edge %d to %d\n",a[i].idx,at<n?b[at].idx:-1);
		}
		REP(i,n) swap(r[i].x1,r[i].y1),swap(r[i].x2,r[i].y2);
	}
	//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }
	
	REP(i,n) rem[i]=deg[i],ret[i]=-1;
	qhead=qtail=0; REP(i,n) if(rem[i]<4) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			--rem[at],--rem[to];
			if(rem[to]==3) q[qhead++]=to;
		}
	}
	if(qtail!=n) { printf("NO\n"); return; }
	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		int mask=0; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(ret[to]!=-1) mask|=1<<ret[to]; }
		ret[at]=0; while(mask&(1<<ret[at])) ++ret[at];
	}
	printf("YES\n");
	REP(i,n) printf("%d\n",ret[i]+1);
}

int main() {
	run();
	return 0;
}