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

const int MAXN=5000;

int n;
int t[MAXN][3];
int npos[3],nneg[3],s[3],c[3];

int me,score[MAXN][1<<3];
int lft[3],res[3];
bool match[MAXN];
int use[MAXN];

int head[3][3],head2[3],prv[300*MAXN],nxt[300*MAXN],tail[3][3],tail2[3];
int id[300*MAXN],nid;
int pos[MAXN][2];

void append(int i,int hd,int tl) {
	int at=nid++;
	assert(hd!=-1&&tl!=-1&&nxt[hd]!=-1&&prv[tl]!=-1);
	id[at]=i,prv[at]=prv[tl],nxt[at]=tl;
	nxt[prv[at]]=at,prv[nxt[at]]=at;
	if(pos[i][0]==-1) pos[i][0]=at; else if(pos[i][1]==-1) pos[i][1]=at; else assert(false);
}
void remove(int at) {
	//printf("removing %d\n",at);
	assert(prv[at]!=-1&&nxt[at]!=-1);
	nxt[prv[at]]=nxt[at]; 
	prv[nxt[at]]=prv[at];
	id[at]=prv[at]=nxt[at]=-2;
}

void change(int i,int k) {
	//printf("changing %d to %x (%d)\n",i,k,nid);
	if(match[i]) {
		REP(j,3) if(use[i]&(1<<j)) ++lft[j];
		if(pos[i][0]!=-1) remove(pos[i][0]),pos[i][0]=-1;
		if(pos[i][1]!=-1) remove(pos[i][1]),pos[i][1]=-1;
		match[i]=false,use[i]=0;
	}
	REP(j,3) if(k&(1<<j)) {
		assert(lft[j]>res[j]); --lft[j];
		int jj=(j+1)%3,jjj=(j+2)%3;
		if(me>=score[i][k^(1<<j)^(1<<jj)]) append(i,head[j][jj],tail[j][jj]);
		if(me>=score[i][k^(1<<j)^(1<<jjj)]) append(i,head[j][jjj],tail[j][jjj]);
		if(me<score[i][k^(1<<j)^(1<<jj)]&&me<score[i][k^(1<<j)^(1<<jjj)]&&me>=score[i][k^(1<<j)^(1<<jj)^(1<<jjj)]) append(i,head2[j],tail2[j]);
	}
	match[i]=true,use[i]=k;
}
void move(int j,int jj) {
	//printf("moving %d->%d [%d]\n",j,jj,nxt[head[j][jj]]);
	int i=id[nxt[head[j][jj]]];
	assert(match[i]);
	change(i,use[i]^(1<<j)^(1<<jj));
}
void move2(int j) {
	//printf("moving2 %d\n",j);
	int i=id[nxt[head2[j]]];
	assert(match[i]);
	change(i,use[i]^((1<<3)-1)^(1<<j));
}

bool reserve1(int j) {
	int jj=(j+1)%3,jjj=(j+2)%3;
	if(lft[j]<=res[j]) {
		if(id[nxt[head[j][jj]]]!=-1&&lft[jj]>res[jj]) move(j,jj);
		else if(id[nxt[head[j][jjj]]]!=-1&&lft[jjj]>res[jjj]) move(j,jjj);
		else if(id[nxt[head[j][jj]]]!=-1&&id[nxt[head[jj][jjj]]]!=-1&&lft[jjj]>res[jjj]) move(jj,jjj),move(j,jj);
		else if(id[nxt[head[j][jjj]]]!=-1&&id[nxt[head[jjj][jj]]]!=-1&&lft[jj]>res[jj]) move(jjj,jj),move(j,jjj);
	}
	if(res[j]>=lft[j]) return false;
	//printf("reserved %d\n",j);
	++res[j]; return true;
}

bool reserve2(int j) {
	int jj=(j+1)%3,jjj=(j+2)%3;
	if(lft[j]<=res[j]) {
		if(id[nxt[head2[j]]]!=-1&&lft[jj]>res[jj]&&lft[jjj]>res[jjj]) move2(j);
		else if(id[nxt[head2[j]]]!=-1&&id[nxt[head[jjj][jj]]]!=-1&&lft[jj]>res[jj]+1) move(jjj,jj),move2(j);
		else if(id[nxt[head2[j]]]!=-1&&id[nxt[head[jj][jjj]]]!=-1&&lft[jjj]>=res[jjj]+1) move(jj,jjj),move2(j);
	}
	if(res[j]>=lft[j]) return false;
	//printf("reserved2 %d\n",j);
	++res[j]; return true;
}

void clearreserved() {
	REP(j,3) res[j]=0;
}

void augment0() {
	FOR(i,1,n) if(!match[i]&&me>=score[i][0]) change(i,0);
}

void augment1() {
	REP(j,3) {
		int jj=(j+1)%3,jjj=(j+2)%3;
		FOR(i,1,n) if(!match[i]&&me>=score[i][1<<j]) {
			clearreserved();
			if(!reserve1(j)) break;
			clearreserved();
			//printf("change1\n");
			change(i,1<<j);
		}
	}
}

void augment2() {
	REP(j,3) {
		int jj=(j+1)%3,jjj=(j+2)%3;
		FOR(i,1,n) if(!match[i]&&me>=score[i][1<<j]) {
			clearreserved();
			if(!reserve2(j)) break;
			clearreserved();
			//printf("change2a\n");
			change(i,1<<j);
		}
		FOR(i,1,n) if(!match[i]&&me>=score[i][(1<<j)|(1<<jj)]) {
			clearreserved();
			if(!reserve1(j)||!reserve1(jj)) break;
			clearreserved();
			//printf("change2b\n");
			change(i,(1<<j)|(1<<jj));
		}
	}
}

void augment3() {
	REP(j,3) {
		int jj=(j+1)%3,jjj=(j+2)%3;
		FOR(i,1,n) if(!match[i]&&me>=score[i][(1<<j)|(1<<jj)]) {
			clearreserved();
			if(reserve1(j)) { if(!reserve2(jj)) break; } else if(!reserve1(jj)||!reserve2(j)) break;
			clearreserved();
			//printf("change3a\n");
			change(i,(1<<j)|(1<<jj));
		}
		if(j==0) FOR(i,1,n) if(!match[i]&&me>=score[i][(1<<j)|(1<<jj)|(1<<jjj)]) {
			clearreserved();
			if(!reserve1(j)||!reserve1(jj)||!reserve1(jjj)) break;
			clearreserved();
			//printf("change3b\n");
			change(i,(1<<j)|(1<<jj)|(1<<jjj));
		}
	}
}

void augment4() {
	REP(j,3) {
		int jj=(j+1)%3,jjj=(j+2)%3;
		if(lft[jjj]>0) FOR(i,1,n) if(!match[i]&&me>=score[i][(1<<j)|(1<<jj)|(1<<jjj)]) {
			clearreserved();
			assert(reserve1(jjj));
			if(reserve1(j)) { if(!reserve2(jj)) break; } else if(!reserve1(jj)||!reserve2(j)) break;
			clearreserved();
			//printf("change4\n",jjj);
			change(i,(1<<j)|(1<<jj)|(1<<jjj));
		}
	}
}

int ret;
void solve() {
	//printf("solve(%d,%d,%d | %d,%d,%d)\n",s[0],s[1],s[2],c[0],c[1],c[2]);
	me=0; REP(j,3) if(t[0][j]>0) me+=s[j]/250*(250-t[0][j]); REP(j,3) me+=100*c[j];
	FOR(i,1,n) REP(k,1<<3) { score[i][k]=0; REP(j,3) if(t[i][j]>0||t[i][j]<0&&(k&(1<<j))==0) score[i][k]+=s[j]/250*(250-abs(t[i][j])); }
	nid=0; FOR(i,1,n) match[i]=false,pos[i][0]=-1,pos[i][1]=-1;
	REP(j,3) REP(jj,3) { id[nid]=-1,prv[nid]=-1,head[j][jj]=nid++; id[nid]=-1,nxt[nid]=-1,tail[j][jj]=nid++; nxt[head[j][jj]]=tail[j][jj]; prv[tail[j][jj]]=head[j][jj]; }
	REP(j,3) { id[nid]=-1,prv[nid]=-1,head2[j]=nid++; id[nid]=-1,nxt[nid]=-1,tail2[j]=nid++; nxt[head2[j]]=tail2[j]; prv[tail2[j]]=head2[j]; }
	REP(j,3) lft[j]=c[j];
	augment0();
	augment1();
	augment2();
	augment3();
	augment4();
	int cur=n; FOR(i,1,n) if(match[i]) --cur; if(cur<ret) ret=cur;
	//printf("%d\n",cur);
}

void go(int at) {
	if(at>=3) return (void)solve();
	int mn=npos[at],mx=npos[at]+nneg[at];
	if(n<2*mx&&2*mn<=2*n) { s[at]=500; c[at]=min(mx-mn,mx-(n/2+1)); go(at+1); }
	if(n<4*mx&&4*mn<=2*n) { s[at]=1000; c[at]=min(mx-mn,mx-(n/4+1)); go(at+1); }
	if(n<8*mx&&8*mn<=2*n) { s[at]=1500; c[at]=min(mx-mn,mx-(n/8+1)); go(at+1); }
	if(n<16*mx&&16*mn<=2*n) { s[at]=2000; c[at]=min(mx-mn,mx-(n/16+1)); go(at+1); }
	if(n<32*mx&&32*mn<=2*n) { s[at]=2500; c[at]=min(mx-mn,mx-(n/32+1)); go(at+1); }
	if(64*mn<=2*n) { s[at]=3000; c[at]=min(mx-mn,mx); go(at+1); }
}


void run() {
	scanf("%d",&n); REP(i,n) REP(j,3) scanf("%d",&t[i][j]);
	REP(j,3) npos[j]=nneg[j]=0; REP(i,n) REP(j,3) if(t[i][j]>0) ++npos[j]; else if(t[i][j]<0) ++nneg[j];
	ret=INT_MAX; go(0); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}