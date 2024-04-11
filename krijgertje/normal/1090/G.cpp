#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXQ=250000;
const int MAXLG=18;
const int MAXS=4*((MAXLG+1)*(MAXQ+1)+2);

int nq;
int qkind[MAXQ],qa[MAXQ],qb[MAXQ];

struct SegNode { int c[2]; int val; };
SegNode s[MAXS]; int ns,szero,sone,sstart;

void myassert(bool cond,int method=0) { if(method==0) while(!cond); if(method==1) assert(cond);  }
int smake(int val) { myassert(val==0||val==1); myassert(ns<MAXS,1); int ret=ns++; s[ret].c[0]=s[ret].c[1]=-1; s[ret].val=val; return ret; }
int scopy(int x) { myassert(ns<MAXS,1); int ret=ns++; s[ret].c[0]=s[x].c[0],s[ret].c[1]=s[x].c[1],s[ret].val=s[x].val; return ret; }
void spull(int x) {
	myassert(s[x].c[0]!=-1&&s[x].c[1]!=-1);
	if(s[s[x].c[0]].val==s[s[x].c[1]].val) s[x].val=s[s[x].c[0]].val; else s[x].val=-1;
}
int supd(int x,int l,int r,int VAL,int L,int R) { // first apply val, then make bit L zero and bit L+1..R one
	//printf("supd(%d,%d..%d,%d,%d..%d) [%d]\n",x,l,r,VAL,L,R,s[x].val);
	if(L+1<=l&&r<=R) {
		return sone;
	} if(l==r) {
		return szero;
	} else {
		int ret=VAL!=-1?smake(VAL):scopy(x);
		int m=l+(r-l)/2;
		if(L<=m) s[ret].c[0]=supd(s[ret].c[0],l,m,s[ret].val,L,R); else if(s[ret].val!=-1) s[ret].c[0]=s[ret].val==0?szero:sone; else myassert(s[ret].c[0]!=-1);
		if(m+1<=R) s[ret].c[1]=supd(s[ret].c[1],m+1,r,s[ret].val,L,R); else if(s[ret].val!=-1) s[ret].c[1]=s[ret].val==0?szero:sone; else myassert(s[ret].c[1]!=-1);
		spull(ret);
		return ret;
	}
}
int supd(int x,int L,int R) { return supd(x,0,(1<<MAXLG)-1,-1,L,R); }
int sget(int x,int l,int r,int L,int R) { // find last idx in range that is one
	//printf("sget(%d,%d..%d,%d..%d) [%d]\n",x,l,r,L,R,s[x].val);
	if(s[x].val!=-1) return s[x].val==0?-1:min(r,R);
	myassert(l!=r&&s[x].c[0]!=-1&&s[x].c[1]!=-1);
	int m=l+(r-l)/2;
	if(m+1<=R) { int cur=sget(s[x].c[1],m+1,r,L,R); if(cur!=-1) return cur; }
	if(L<=m) { int cur=sget(s[x].c[0],l,m,L,R); if(cur!=-1) return cur; }
	return -1;
}
int sget(int x,int L,int R) { return sget(x,0,(1<<MAXLG)-1,L,R); }

int cdefroot[MAXQ],cdefbits[MAXQ],cattack[MAXQ],cdies[MAXQ],nc;

void processattack(int who,int val,int t) {
	if(val>=cdefbits[who]) {
		//printf("not enough bits\n");
		cdies[who]=t;
	} else {
		int attidx=cdefbits[who]-1-val;
		int defidx=sget(cdefroot[who],0,attidx);
		//printf("testing attidx=%d -> defidx=%d\n",attidx,defidx);
		if(defidx==-1) {
			cdies[who]=t;
		} else {
			cdefroot[who]=supd(cdefroot[who],defidx,attidx);
			if(s[cdefroot[who]].val==0) cdies[who]=t;
		}
	}
}

void solve() {
	ns=nc=0; szero=smake(0),sone=smake(1),sstart=supd(szero,-1,0);
	REP(i,nq) {
		//printf("processing %d: %d\n",i,qkind[i]);
		if(qkind[i]==1) {
			int id=nc++; cdefroot[id]=sstart,cdefbits[id]=1,cattack[id]=0,cdies[id]=-1;
		}
		if(qkind[i]==2) {
			int id=qa[i]; myassert(0<=id&&id<nc);
			if(cdies[id]==-1) ++cattack[id];
		}
		if(qkind[i]==3) { 
			int id=qa[i]; myassert(0<=id&&id<nc); 
			if(cdies[id]==-1) ++cdefbits[id];
		}
		if(qkind[i]==4) { 
			int oth=qa[i]; myassert(0<=oth&&oth<nc);
			int id=nc++; if(cdies[oth]==-1) cdefroot[id]=cdefroot[oth],cdefbits[id]=cdefbits[oth],cattack[id]=cattack[oth],cdies[id]=-1; else cdies[id]=i+1;
		}
		if(qkind[i]==5) {
			int a=qa[i],b=qb[i]; myassert(0<=a&&a<nc&&0<=b&&b<nc&&a!=b);
			if(cdies[a]==-1&&cdies[b]==-1) {
				processattack(a,cattack[b],i+1);
				processattack(b,cattack[a],i+1);
			}
		}
	}
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]>=2) scanf("%d",&qa[i]),--qa[i];
		if(qkind[i]==5) scanf("%d",&qb[i]),--qb[i];
	}
	solve();
	printf("%d\n",nc);
	REP(i,nc) { if(i!=0) printf(" "); printf("%d",cdies[i]); } puts("");
}

void stress() {
	REP(rep,100) {
		nq=MAXQ;
		int cnt=0;
		REP(i,nq) {
			if(cnt==0) { qkind[i]=1; ++cnt; continue; }
			while(true) { qkind[i]=rand()%1==0?rand()%5+1:rand()%2==0?2:3; if(cnt>=2||qkind[i]!=5) break; }
			qa[i]=(rand()%1000*1000+rand()%1000)%cnt;
			if(qkind[i]==4) ++cnt;
			if(qkind[i]==5) while(true) { qb[i]=(rand()%1000*1000+rand()%1000)%cnt; if(qa[i]!=qb[i]) break; }
		}
		solve();
		printf(".(%d)",ns);
	}

}

int main() {
	run();
	//stress();
	return 0;
}