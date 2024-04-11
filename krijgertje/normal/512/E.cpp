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

const int MAXN=1000;
const int MAXE=2*(MAXN+MAXN-3);

typedef struct G {
	int n,m;
	int nfst[MAXN]; // n->e
	int nnxt[MAXE]; // e->e
	int fnxt[MAXE]; // e->e
	int to[MAXE]; // e->n
	bool dead[MAXE];

	int add[MAXN][2],nadd;
	int rem[MAXN][2],nrem;

	void ngon(int _n) {
		n=_n;
		REP(b,n) {
			nfst[b]=2*b+0; int a=(b+n-1)%n,c=(b+1)%n;
			nnxt[2*b+0]=2*a+1; fnxt[2*b+0]=2*c+0; to[2*b+0]=c;
			nnxt[2*b+1]=2*c+0; fnxt[2*b+1]=2*a+1; to[2*b+1]=b;
		}
		m=2*n;
		REPE(i,MAXE) dead[i]=false;
	}

	void addedge(int a,int b,int x,int y) {
		if(x==-1) x=m++; if(y==-1) y=m++;
		nnxt[x]=nnxt[b]; fnxt[x]=a; to[x]=to[a^1];
		nnxt[y]=nnxt[a]; fnxt[y]=b; to[y]=to[b^1];
		nnxt[b]=x; fnxt[nnxt[x]^1]=x;
		nnxt[a]=y; fnxt[nnxt[y]^1]=y;
	}

	void removeedge(int x,int y) {
		assert(x!=nfst[to[y]]); assert(y!=nfst[to[x]]);
		nnxt[fnxt[y]]=nnxt[x]; fnxt[nnxt[x]^1]=fnxt[y];
		nnxt[fnxt[x]]=nnxt[y]; fnxt[nnxt[y]^1]=fnxt[x];
	}

	void simplify() {
		for(int x=nfst[0];nnxt[x]!=nfst[0];x=nnxt[x]) {
			while(to[x]+1!=to[nnxt[x]]) {
				int p=fnxt[x],q=p^1; assert(to[p]==to[nnxt[x]]);
				rem[nrem][0]=to[p^1]; rem[nrem][1]=to[q^1]; ++nrem; removeedge(p,q);
				//printf("remove\n"); dead[p]=dead[q]=true; print(); dead[p]=dead[q]=false;
				add[nadd][0]=to[x^1]; add[nadd][1]=to[fnxt[fnxt[x]]^1]; ++nadd; addedge(x,fnxt[fnxt[x]],p,q);
				//printf("simplify\n"); print();
			}
		}
	}

	bool been[MAXE];
	void print() {
		REP(i,n) { printf("N%d:",i); for(int x=nfst[i];x!=-1;x=(nnxt[x]==nfst[i]?-1:nnxt[x])) printf(" %d",to[x]); puts(""); }
		REP(i,m) been[i]=dead[i];
		REP(i,m) if(!been[i]) { printf("E"); for(int x=i;!been[x];x=fnxt[x]) { been[x]=true; printf(" %d",to[x]); } puts(""); }
	}
} G;
G g1,g2;
bool ok(int c,int a,int b) { return a<b?a<c&&c<b:c<b||a<c; }

int n;

void run() {
	scanf("%d",&n);
	g1.ngon(n);
	REP(i,n-3) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		int p=g1.nfst[a]; while(ok(g1.to[g1.nnxt[p]],a,b)) p=g1.nnxt[p];
		int q=g1.nfst[b]; while(ok(g1.to[g1.nnxt[q]],b,a)) q=g1.nnxt[q];
		g1.addedge(p,q,-1,-1);
	}
	g2.ngon(n);
	REP(i,n-3) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		int p=g2.nfst[a]; while(ok(g2.to[g2.nnxt[p]],a,b)) p=g2.nnxt[p];
		int q=g2.nfst[b]; while(ok(g2.to[g2.nnxt[q]],b,a)) q=g2.nnxt[q];
		g2.addedge(p,q,-1,-1);
	}
	g1.simplify(); //printf("g1\n"); g1.print(); 
	g2.simplify(); //printf("g2\n"); g2.print();

	printf("%d\n",g1.nrem+g2.nadd);
	REP(i,g1.nrem) printf("%d %d\n",g1.rem[i][0]+1,g1.rem[i][1]+1);
	for(int i=g2.nadd-1;i>=0;--i) printf("%d %d\n",g2.add[i][0]+1,g2.add[i][1]+1);
}

int main() {
	run();
	return 0;
}