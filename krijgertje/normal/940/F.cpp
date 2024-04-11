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
const int MAXV=MAXN+MAXQ;
const int NCNT=50;
const int TCNT=50;
struct T { int idx,a,b; };
struct QQ { int l,r,t,nb,tb,id; };
bool operator<(const QQ &a,const QQ &b) { if(a.tb!=b.tb) return a.tb<b.tb; if(a.nb!=b.nb) return a.nb<b.nb; return a.r<b.r; }


int n,nq;
int a[MAXN],b[MAXN];
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qidx[MAXQ],qval[MAXQ],qt[MAXQ],qans[MAXQ];

int vals[MAXV],nvals;

int nbl[NCNT],nbr[NCNT];
int tbl[TCNT],tbr[TCNT];

T tt[MAXQ]; int ntt;
QQ qq[MAXQ]; int nqq;

int cnt[MAXV];
int freq[MAXV+1];

void mod(int val,int by) {
	freq[cnt[val]]--;
	cnt[val]+=by;
	freq[cnt[val]]++;
}
void apply(int t,int cl,int cr) {
	int idx=tt[t].idx;
	if(cl<=idx&&idx<cr) mod(a[idx],-1);
	a[idx]=tt[t].b;
	if(cl<=idx&&idx<cr) mod(a[idx],+1);
}
void undo(int t,int cl,int cr) {
	int idx=tt[t].idx;
	if(cl<=idx&&idx<cr) mod(a[idx],-1);
	a[idx]=tt[t].a;
	if(cl<=idx&&idx<cr) mod(a[idx],+1);
}
int calc() {
	int ret=0; while(freq[ret]>0) ++ret; return ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i]; if(qkind[i]==2) scanf("%d%d",&qidx[i],&qval[i]),--qidx[i]; }

	nvals=0; REP(i,n) vals[nvals++]=a[i]; REP(i,nq) if(qkind[i]==2) vals[nvals++]=qval[i];
	sort(vals,vals+nvals); nvals=unique(vals,vals+nvals)-vals;
	REP(i,n) a[i]=lower_bound(vals,vals+nvals,a[i])-vals; REP(i,nq) if(qkind[i]==2) qval[i]=lower_bound(vals,vals+nvals,qval[i])-vals;

	ntt=0; REP(i,n) b[i]=a[i]; REP(i,nq) if(qkind[i]==1) qt[i]=ntt; else { qt[i]=ntt; tt[ntt].idx=qidx[i],tt[ntt].a=b[qidx[i]],tt[ntt].b=qval[i]; b[qidx[i]]=qval[i]; ++ntt; }
	REP(i,NCNT) nbl[i]=(ll)n*i/NCNT,nbr[i]=(ll)n*(i+1)/NCNT;
	REP(i,TCNT) tbl[i]=(ll)(ntt+1)*i/TCNT,tbr[i]=(ll)(ntt+1)*(i+1)/TCNT;
	nqq=0; REP(i,nq) if(qkind[i]==1) {
		qq[nqq].l=ql[i],qq[nqq].r=qr[i]+1,qq[nqq].t=qt[i],qq[nqq].nb=qq[nqq].tb=-1,qq[nqq].id=i;
		REP(j,NCNT) if(nbl[j]<=ql[i]&&ql[i]<nbr[j]) qq[nqq].nb=j;
		REP(j,TCNT) if(tbl[j]<=qt[i]&&qt[i]<tbr[j]) qq[nqq].tb=j;
		assert(qq[nqq].nb!=-1&&qq[nqq].tb!=-1);	++nqq;
	}
	sort(qq,qq+nqq);

	int cl=0,cr=0,ct=0; REP(i,nvals) cnt[i]=0; REPE(i,nvals) freq[i]=0; freq[0]=nvals+1;
	REP(i,nqq) {
		while(ct>qq[i].t) undo(--ct,cl,cr);
		while(ct<qq[i].t) apply(ct++,cl,cr);
		while(cl>qq[i].l) mod(a[--cl],+1);
		while(cr<qq[i].r) mod(a[cr++],+1);
		while(cl<qq[i].l) mod(a[cl++],-1);
		while(cr>qq[i].r) mod(a[--cr],-1);
		qans[qq[i].id]=calc();
	}
	REP(i,nq) if(qkind[i]==1) printf("%d\n",qans[i]);	
}

int main() {
	run();
	return 0;
}