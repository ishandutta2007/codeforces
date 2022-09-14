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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=100000;
typedef struct C { int a,b,c,d; } C;


int want,have;
int n,m;
int l[MAXN],r[MAXN];
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];

int cidx[MAXN],cside[MAXN];
C comp[MAXN]; int nc;

int q[MAXN],qhead,qtail;

int L,R;

void constrain(int &a,int &b,int A,int B) { if(A>a) a=A; if(B<b) b=B; }
bool check(int b,int c) {
	int a=0,d=INT_MAX;
	//if(have==1334309) printf("checking -> %d..%d / %d..%d\n",a,b,c,d);
	REP(i,nc) {
		if(comp[i].b<comp[i].d) {
			constrain(a,b,comp[i].a,comp[i].b);
			constrain(c,d,comp[i].c,comp[i].d);
		} else {
			constrain(a,d,comp[i].a,comp[i].b);
			if(comp[i].d<c) constrain(a,b,comp[i].c,comp[i].d);
			else if(comp[i].c>b) constrain(c,d,comp[i].c,comp[i].d);
		}
	}
	//if(have==1334309) printf("checked -> %d..%d / %d..%d\n",a,b,c,d);
	if(a>b||c>d) return false;
	L=a,R=c;
	if(L+R<want) { int cur=min(want-L-R,b-a); L+=cur; }
	if(L+R<want) { int cur=min(want-L-R,d-c); R+=cur; }
	return L+R>=want&&L+R<=have;
}

bool calc() {
	nc=0; REP(i,n) cidx[i]=cside[i]=-1;
	REP(i,n) if(cidx[i]==-1) {
		qhead=qtail=0;
		comp[nc].a=comp[nc].c=0,comp[nc].b=comp[nc].d=INT_MAX;
		cidx[i]=nc; cside[i]=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			if(cside[at]==0&&l[at]>comp[nc].a) comp[nc].a=l[at];
			if(cside[at]==0&&r[at]<comp[nc].b) comp[nc].b=r[at];
			if(cside[at]==1&&l[at]>comp[nc].c) comp[nc].c=l[at];
			if(cside[at]==1&&r[at]<comp[nc].d) comp[nc].d=r[at];
			for(int x=fst[at];x!=-1;x=nxt[x]) {
				if(cidx[to[x]]!=-1&&(cidx[to[x]]!=cidx[at]||cside[to[x]]!=1-cside[at])) return false;
				if(cidx[to[x]]==-1) { cidx[to[x]]=cidx[at]; cside[to[x]]=1-cside[at]; q[qhead++]=to[x]; }
			}
		}
		if(comp[nc].a>comp[nc].b||comp[nc].c>comp[nc].d) return false;
		if(comp[nc].c<comp[nc].a||comp[nc].c==comp[nc].a&&comp[nc].d>comp[nc].b) {
			swap(comp[nc].a,comp[nc].c),swap(comp[nc].b,comp[nc].d);
			REP(j,qtail) cside[q[j]]=1-cside[q[j]];
		}
		++nc;
	}
	//if(have==1334309) REP(i,n) printf("%d: %d %c\n",i,cidx[i],cside[i]==0?'L':'R');
	//if(have==1334309) { printf("ncomp:%d\n",nc); FOR(i,31,nc) printf("%d: %d..%d / %d..%d\n",i,comp[i].a,comp[i].b==INT_MAX?-1:comp[i].b,comp[i].c,comp[i].d); }
	
	int minend=INT_MAX,maxstart=0;
	REP(i,nc) {
		if(comp[i].a>maxstart) maxstart=comp[i].a;
		if(comp[i].c>maxstart) maxstart=comp[i].c;
		if(comp[i].b<minend) minend=comp[i].b;
		if(comp[i].d<minend) minend=comp[i].d;
	}
	if(minend<maxstart) {
		return check(minend,maxstart);
	} else {
		if(maxstart>0&&check(maxstart-1,maxstart)) return true;
		if(check(minend,minend+1)) return true;
		if(2*maxstart>have) return false;
		if(2*minend<want) return false;
		L=R=maxstart;
		if(L+R<want) L+=(want-L-R)/2,R+=(want-L-R);
		return true;
	}
}

void run() {
	scanf("%d%d",&want,&have);
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	if(!calc()) { printf("IMPOSSIBLE\n"); return; }
	printf("POSSIBLE\n");
	printf("%d %d\n",L,R);
	REP(i,n) {
		int a=comp[cidx[i]].a,b=comp[cidx[i]].b,c=comp[cidx[i]].c,d=comp[cidx[i]].d;
		if(a<=L&&L<=b&&c<=R&&R<=d) printf("%c",cside[i]==0?'1':'2');
		else if(a<=R&&R<=b&&c<=L&&L<=d) printf("%c",cside[i]==1?'1':'2');
		else assert(false);
	}
	puts("");
}

int main() {
	run();
	return 0;
}