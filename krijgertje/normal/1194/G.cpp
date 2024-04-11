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

const int MAXLEN=100;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

struct Ratio { int x,y; vector<pair<int,int>> pairs; };


char s[MAXLEN+1]; int slen;

vector<Ratio> ratios;

vector<int> p3;
vector<int> nums[10],dens[10];
int x,y;
int finstate;
int contrib[MAXLEN];

vector<int> mem[MAXLEN][10][10][2];

int go(int idx,int xcarry,int ycarry,int ok,int state) {
	if(idx<0) return xcarry==0&&ycarry==0&&ok==1&&state==finstate?1:0;
	assert(0<=idx&&idx<slen&&0<=xcarry&&xcarry<x&&0<=ycarry&&ycarry<y&&0<=ok&&ok<=1&&0<=state&&state<=finstate);
	if(mem[idx][xcarry][ycarry][ok][state]!=-1) return mem[idx][xcarry][ycarry][ok][state];
	int ret=0;
	REPE(b,9) {
		int xval=xcarry+b*x,nxcarry=xval/10,xdig=xval%10;
		int yval=ycarry+b*y,nycarry=yval/10,ydig=yval%10,ylim=s[idx]-'0';
		int nok=ydig<ylim||ok==1&&ydig==ylim?1:0;
		int nstate=state;
		REPSZ(i,nums[xdig]) if(nstate!=finstate) { int z=nums[xdig][i],old=nstate/p3[z]%3; if(old==2) nstate=finstate; else if(old==0) nstate+=p3[z]; }
		REPSZ(i,dens[ydig]) if(nstate!=finstate) { int z=dens[ydig][i],old=nstate/p3[z]%3; if(old==1) nstate=finstate; else if(old==0) nstate+=2*p3[z]; }
		int cur=go(idx-1,nxcarry,nycarry,nok,nstate);
		inc(ret,cur);
		//if(state==2) printf("\t\tb=%d: (%d,%d,%d,%d,%d)+%d->(%d,%d,%d,%d,%d)=%d [xdig=%d,ydig=%d]\n",b,idx,xcarry,ycarry,ok,state,b,idx-1,nxcarry,nycarry,nok,nstate,cur,xdig,ydig);
	}
	//printf("\t(%d,%d,%d,%d,%d)=%d\n",idx,xcarry,ycarry,ok,state,ret);
	return mem[idx][xcarry][ycarry][ok][state]=ret;
}


int calc(int i) {
	//if(i!=1) return 0;
	//printf("%d:",i); REPSZ(j,ratios[i].pairs) printf(" %d/%d",ratios[i].pairs[j].first,ratios[i].pairs[j].second); puts("");
	p3.clear(); p3.PB(1); REPSZ(j,ratios[i].pairs) { int nxt=p3.back()*3; p3.PB(nxt); }
	REP(j,10) nums[j].clear(),dens[j].clear(); REPSZ(j,ratios[i].pairs) nums[ratios[i].pairs[j].first].PB(j),dens[ratios[i].pairs[j].second].PB(j);
	::x=ratios[i].x,::y=ratios[i].y,finstate=p3[SZ(ratios[i].pairs)];
	contrib[slen-1]=1; for(int i=slen-2;i>=0;--i) contrib[i]=10*contrib[i+1]%y;
	int nstate=finstate+1;
	REP(idx,slen) REP(xcarry,x) REP(ycarry,y) REP(ok,2) mem[idx][xcarry][ycarry][ok]=vector<int>(nstate,-1);
	int ret=go(slen-1,0,0,1,0);
	REP(idx,slen) REP(xcarry,x) REP(ycarry,y) REP(ok,2) mem[idx][xcarry][ycarry][ok]=vector<int>();
	//printf("->%d\n",ret);
	return ret;
}

int solve() {
	ratios.clear();
	FORE(x,1,9) FORE(y,x,9) {
		int idx=-1; REPSZ(i,ratios) if(x*ratios[i].y==ratios[i].x*y) { assert(idx==-1); idx=i; }
		if(idx!=-1) { ratios[idx].pairs.PB(MP(x,y)); continue; }
		Ratio cur; cur.x=x,cur.y=y; cur.pairs.PB(MP(x,y)); ratios.PB(cur);
	}
	int ret=0;
	REPSZ(i,ratios) {
		int cur=calc(i);
		if(ratios[i].x!=ratios[i].y) cur=(ll)cur*2%MOD;
		inc(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%d\n",solve());
}


bool contains(int x,int d) { while(x>0) { if(x%10==d) return true; x/=10; } return false; }
int solvestupid(int n) {
	int ret=0;
	FORE(num,1,n) {
		set<int> dens;
		FORE(x,1,9) if(contains(num,x)) FORE(y,1,9) if((num*y)%x==0) { int den=(num*y)/x; if(den<=n&&contains(den,y)) dens.insert(den); }
		ret+=SZ(dens);
	}
	return ret;
}

void stress() {
	FORE(n,1,1000) {
		sprintf(s,"%d",n); slen=strlen(s);
		int have=solve();
		int want=solvestupid(n);
		if(have==want) { printf("."); continue; }
		printf("%d: have=%d want=%d\n",n,have,want);

	}
}

int main() {
	run();
	//stress();
	return 0;
}