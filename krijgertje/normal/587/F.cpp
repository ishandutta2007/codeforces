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
const int MAXLEN=100000;
const int MAXX=1+MAXLEN;
const int MINLONGLEN=707;
const int MAXQ=100000;
const int STEP=316;

typedef struct X { int nxt[26]; int endhead,par,childhead,childnxt,d,prefhead; } X;

int n,nq;
char s[MAXLEN+1];
int pos[MAXN+1],len[MAXN],id[MAXLEN];

X x[MAXX]; int root,nx;
int endnxt[MAXN];
int prefnxt[MAXLEN];
int getx(int d) { REP(k,26) x[nx].nxt[k]=-1; x[nx].endhead=x[nx].par=x[nx].childhead=x[nx].childnxt=x[nx].prefhead=-1; x[nx].d=d; return nx++; }

bool ispref[MAXX];
ll cnt[MAXN+1],sum[MAXN+1];

int qhead[MAXN];
int qnxt[MAXQ],ql[MAXQ],qr[MAXQ];
ll ret[MAXQ];

int qqhead,qqtail,qq[MAXX];

int dfs1(int at,int want) {
	int ret=0;
	for(int z=x[at].prefhead;z!=-1;z=prefnxt[z]) if(id[z]==want) ++ret;
	for(int z=x[at].childhead;z!=-1;z=x[z].childnxt) ret+=dfs1(z,want);
	for(int z=x[at].endhead;z!=-1;z=endnxt[z]) cnt[z+1]+=ret;
	//printf("\t%d: %d\n",at,ret);
	return ret;
}
void inc(int pos,int by) {
	while(pos%STEP!=0) cnt[pos]+=by,++pos;
	while(pos<=n) sum[pos]+=by,pos+=STEP;
}
ll get(int pos) {
	return cnt[pos]+sum[pos-pos%STEP];
}
void dfs2(int at) {
	for(int z=x[at].endhead;z!=-1;z=endnxt[z]) inc(z+1,+1);
	for(int z=x[at].childhead;z!=-1;z=x[z].childnxt) dfs2(z);
	for(int z=x[at].prefhead;z!=-1;z=prefnxt[z]) if(len[id[z]]<MINLONGLEN) for(int zz=qhead[id[z]];zz!=-1;zz=qnxt[zz]) ret[zz]+=get(qr[zz])-get(ql[zz]);
	for(int z=x[at].endhead;z!=-1;z=endnxt[z]) inc(z+1,-1);
}

void printtree(int at,int d) {
	if(d>10) return;
	REP(k,26) if(x[at].nxt[k]!=-1&&x[x[at].nxt[k]].d>x[at].d) {
		REP(i,d) printf("  "); printf("%c->%d [%d]\n",'a'+k,x[at].nxt[k],x[x[at].nxt[k]].par);
		printtree(x[at].nxt[k],d+1);
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	pos[0]=0; REP(i,n) { scanf("%s",s+pos[i]); len[i]=strlen(s+pos[i]); pos[i+1]=pos[i]+len[i]; } s[pos[n]]='\0';
	//printf("%s\n",s);

	nx=0; root=getx(0);
	REP(i,n) {
		int at=root;
		REP(j,len[i]) {
			int k=s[pos[i]+j]-'a';
			if(x[at].nxt[k]==-1) x[at].nxt[k]=getx(x[at].d+1);
			at=x[at].nxt[k];
			prefnxt[pos[i]+j]=x[at].prefhead; x[at].prefhead=pos[i]+j; id[pos[i]+j]=i;
		}
		endnxt[i]=x[at].endhead; x[at].endhead=i;
	}

	qqhead=qqtail=0; REP(k,26) if(x[root].nxt[k]==-1) x[root].nxt[k]=root; else qq[qqhead++]=x[root].nxt[k],x[x[root].nxt[k]].par=root;
	while(qqtail<qqhead) {
		int at=qq[qqtail++];
		REP(k,26) if(x[at].nxt[k]!=-1) {
			qq[qqhead++]=x[at].nxt[k];
			x[x[at].nxt[k]].par=x[x[at].par].nxt[k];
		} else {
			x[at].nxt[k]=x[x[at].par].nxt[k];
		}
	}
	REP(i,nx) if(x[i].par!=-1) { x[i].childnxt=x[x[i].par].childhead; x[x[i].par].childhead=i; }
	//printtree(root,0);

	REP(i,n) qhead[i]=-1;
	REP(i,nq) {
		int l,r,k; scanf("%d%d%d",&l,&r,&k); --l,--k;
		qnxt[i]=qhead[k]; qhead[k]=i; ql[i]=l; qr[i]=r;
	}

	REP(i,nq) ret[i]=0;
	REP(i,n) if(len[i]>=MINLONGLEN) {
		memset(cnt,0,sizeof(cnt));
		//printf("%d: ",i); REP(j,nx) printf("%c",ispref[j]?'v':'.'); puts("");
		dfs1(root,i);
		REP(j,n) cnt[j+1]+=cnt[j];
		//REPE(j,n) printf(" %I64d",cnt[j]); puts("");
		for(int z=qhead[i];z!=-1;z=qnxt[z]) ret[z]+=cnt[qr[z]]-cnt[ql[z]];
	}

	memset(cnt,0,sizeof(cnt));
	memset(sum,0,sizeof(sum));
	dfs2(root);

	REP(i,nq) printf("%I64d\n",ret[i]);
}

int main() {
	run();
	return 0;
}