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

const int MAXN=25;
const int MAXN1=MAXN/2;
const int MAXX=531441; // 3^MAXN1

typedef struct X { int A,B,C,ab,ac; } X;
bool operator<(const X &p,const X &q) {
	if(p.B-p.A!=q.B-q.A) return p.B-p.A<q.B-q.A;
	if(p.C-p.A!=q.C-q.A) return p.C-p.A<q.C-q.A;
	return p.A<q.A;
}

int n,n1,n2;
int a[MAXN],b[MAXN],c[MAXN];

X x[MAXX]; int nx;

void run() {
	scanf("%d",&n);
	n1=n/2,n2=n-n1;
	REP(i,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);

	nx=0;
	REP(i,1<<n1) for(int j=0;j<(1<<n1);j=(i+j+1)&~i) {
		int A=0,B=0,C=0;
		REP(k,n1) {
			if(j&(1<<k)) A+=a[k],B+=b[k];
			else if(i&(1<<k)) A+=a[k],C+=c[k];
			else B+=b[k],C+=c[k];
		}
		x[nx].A=A,x[nx].B=B,x[nx].C=C,x[nx].ab=j,x[nx].ac=i,++nx;
	}
	sort(x,x+nx);
	//REP(i,nx) printf("%d %d %d [%x %x] -> %d %d\n",x[i].A,x[i].B,x[i].C,x[i].ab,x[i].ac,x[i].B-x[i].A,x[i].C-x[i].A);

	X ret; ret.A=ret.B=ret.C=INT_MIN,ret.ab=ret.ac=-1;
	REP(i,1<<n2) for(int j=0;j<(1<<n2);j=(i+j+1)&~i) {
		int A=0,B=0,C=0;
		REP(k,n2) {
			if(j&(1<<k)) A+=a[n1+k],B+=b[n1+k];
			else if(i&(1<<k)) A+=a[n1+k],C+=c[n1+k];
			else B+=b[n1+k],C+=c[n1+k];
		}
		int l=0,h=nx-1; // [l,h]
		while(l<=h) {
			int m=l+(h-l)/2;
			if(A-B!=x[m].B-x[m].A) { if(A-B<x[m].B-x[m].A) h=m-1; else l=m+1; continue; }
			if(A-C!=x[m].C-x[m].A) { if(A-C<x[m].C-x[m].A) h=m-1; else l=m+1; continue; }
			//printf("%d %d %d / %d %d %d [%x %x] [%x %x]\n",A,B,C,x[m].A,x[m].B,x[m].C,x[m].ab,x[m].ac,j<<n1,i<<n1);
			X cur; cur.A=A+x[m].A,cur.B=B+x[m].B,cur.C=C+x[m].C,cur.ab=x[m].ab+(j<<n1),cur.ac=x[m].ac+(i<<n1); if(cur.A>ret.A) ret=cur; 
			l=m+1; continue;
		}
	}
	if(ret.A==INT_MIN) { printf("Impossible\n"); return; }
	REP(k,n) if(ret.ab&(1<<k)) printf("LM\n"); else if(ret.ac&(1<<k)) printf("LW\n"); else printf("MW\n");
}

int main() {
	run();
	return 0;
}