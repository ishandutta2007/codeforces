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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXQ=200000;
const int MAXCOL=200000;

struct Q { int pos,col,id; Q() {} Q(int pos,int col,int id):pos(pos),col(col),id(id) {} };
struct State {
	int n,ncol;
	vector<int> col;
	vector<int> match;
	vector<int> sum;
	vector<int> mx;
	vector<int> cnt;
	vector<Q> q;
};

void printstate(const State &state) {
	REP(i,state.n) {
		int col=state.col[i];
		if(col!=-1) { printf(" %d",col); assert(state.match[i]==-1); continue; }
		assert(state.match[i]!=-1);
		if(state.match[i]==i) {
			printf(" [sum=%d,mx=%d]",state.sum[i],state.mx[i]);
		} else if(i<state.match[i]) {
			printf(" [%d:sum=%d,mx=%d",i,state.sum[i],state.mx[i]);
		} else {
			printf(" :%d]",state.match[i]);
		}
	}
	REPSZ(i,state.q) printf(" (%d:%d=%d)",state.q[i].id,state.q[i].pos,state.q[i].col);
}

State reduce(State state,int l,int r) {
	//printf("\treduce(%d..%d):",l,r); printstate(state); puts("");
	vector<bool> done(state.ncol,true);
	vector<bool> used(state.n,false);
	FORE(i,l,r) { int pos=state.q[i].pos,ocol=state.col[pos],ncol=state.q[i].col; assert(ocol!=-1); done[ocol]=done[ncol]=false; used[pos]=true; }
	vector<int> fst(state.ncol,INT_MAX),lst(state.ncol,INT_MIN);
	REP(i,state.n) { int col=state.col[i]; if(col!=-1&&!used[i]) fst[col]=min(fst[col],i),lst[col]=max(lst[col],i); }
	//REP(i,state.ncol) if(state.cnt[i]!=0) printf("\t\t%d: %d %d %d %d\n",i,done[i]?1:0,fst[i],lst[i],state.cnt[i]);
	vector<bool> alive(state.n,true);
	REP(i,state.n) {
		int col=state.col[i];
		if(col==-1||used[i]) continue;
		if(i!=fst[col]&&i!=lst[col]) { alive[i]=false; continue; }
		if(!done[col]) continue;
		state.col[i]=-1;
		state.match[i]=fst[col]+lst[col]-i; 
		if(i==fst[col]) state.sum[i]=state.mx[i]=state.cnt[col]; 
	}
	int bal=0,fstidx=-1,mx=0,cntalivebetween=0;
	REP(i,state.n) if(alive[i]) {
		if(state.col[i]!=-1) { if(bal!=0) ++cntalivebetween; continue; }
		assert(state.match[i]!=-1);
		if(state.match[i]==i) {
			if(bal==0) {
				//nothing
			} else {
				mx=max(mx,state.mx[i]);
				alive[i]=false;
			}
		} else if(i<state.match[i]) {
			if(bal==0) {
				fstidx=i,mx=state.mx[i],cntalivebetween=0;
			} else {
				mx=max(mx,state.mx[i]);
				alive[i]=false;
			}
			++bal;
		} else {
			--bal;
			if(bal==0) {
				if(cntalivebetween==0) {
					state.match[fstidx]=fstidx,state.sum[fstidx]=state.mx[fstidx]=mx;
					alive[i]=false;
				} else {
					state.match[fstidx]=i,state.match[i]=fstidx,state.sum[fstidx]=state.mx[fstidx]=mx;
				}
				fstidx=-1,mx=0,cntalivebetween=0;
			} else {
				mx=max(mx,state.mx[i]);
				alive[i]=false;
			}
		}
	}
	int reuseidx=-1;
	REP(i,state.n) if(alive[i]) {
		if(state.col[i]!=-1) { reuseidx=-1; continue; }
		assert(state.match[i]!=-1);
		if(state.match[i]!=i) { reuseidx=-1; continue; }
		if(reuseidx==-1) { reuseidx=i; continue; }
		state.mx[reuseidx]=max(state.mx[reuseidx],state.mx[i]);
		state.sum[reuseidx]+=state.sum[i];
		alive[i]=false;
	}

	State ret;
	vector<int> posmp(state.n,-1); ret.n=0; REP(i,state.n) if(alive[i]) posmp[i]=ret.n++;
	vector<int> colmp(state.ncol,-1); ret.ncol=0; REP(i,state.ncol) if(!done[i]) colmp[i]=ret.ncol++;
	ret.col=vector<int>(ret.n,-1); REP(i,state.n) if(alive[i]&&state.col[i]!=-1) ret.col[posmp[i]]=colmp[state.col[i]];
	ret.match=vector<int>(ret.n,-1); REP(i,state.n) if(alive[i]&&state.match[i]!=-1) ret.match[posmp[i]]=posmp[state.match[i]];
	ret.sum=ret.mx=vector<int>(ret.n,-1); REP(i,state.n) if(alive[i]&&state.match[i]!=-1&&i<=state.match[i]) ret.sum[posmp[i]]=state.sum[i],ret.mx[posmp[i]]=state.mx[i];
	FORE(i,l,r) { int pos=state.q[i].pos,col=state.q[i].col,id=state.q[i].id; ret.q.PB(Q(posmp[pos],colmp[col],id)); }
	REP(i,ret.n) if(ret.col[i]!=-1) ret.sum[i]=1;
	ret.cnt=vector<int>(ret.ncol,0); REP(i,state.ncol) if(!done[i]) ret.cnt[colmp[i]]=state.cnt[i];
	//printf("\t->"); printstate(ret); puts("");
	return ret;
}

void apply(State &state,const Q &q) {
	int pos=q.pos,ocol=state.col[pos],ncol=q.col; assert(ocol!=-1); state.col[pos]=ncol; --state.cnt[ocol],++state.cnt[ncol]; //printf("\tchange %d from %d to %d\n",pos,ocol,ncol);
}

int calc(State &state) {
	assert(state.n==1&&state.col[0]==-1);
	return state.sum[0];
}

int ans[MAXQ+1];


void rec(State &state) {
	//printf("rec:"); printstate(state); puts("");
	//static int xxx=0; if(++xxx>=20) exit(0);
	if(SZ(state.q)==0) {
		State res=reduce(state,0,-1);
		ans[0]=calc(res);
		return;
	}
	if(SZ(state.q)==1) {
		if(state.q[0].id==0) {
			State tmp=reduce(state,0,-1);
			//printf("at start:"); printstate(tmp); puts("");
			ans[0]=calc(tmp);
		}
		apply(state,state.q[0]);
		State res=reduce(state,0,-1);
		//printf("after %d:",state.q[0].id); printstate(res); puts("");
		ans[state.q[0].id+1]=calc(res);
		return;
	}
	int m=SZ(state.q)/2;
	State lstate=reduce(state,0,m-1);
	rec(lstate);
	REP(i,m) apply(state,state.q[i]);
	State rstate=reduce(state,m,SZ(state.q)-1);
	rec(rstate);
}

State sstate;

void solve() {
	State state=sstate;
	rec(state);
	REPE(i,SZ(sstate.q)) ans[i]=sstate.n-ans[i];
}

void run() {
	int nq; scanf("%d%d",&sstate.n,&nq); sstate.ncol=MAXCOL;
	sstate.col=vector<int>(sstate.n); REP(i,sstate.n) { int col; scanf("%d",&col); --col; sstate.col[i]=col; }
	sstate.sum=sstate.match=sstate.mx=vector<int>(sstate.n,-1); sstate.cnt=vector<int>(MAXCOL,0); REP(i,sstate.n) ++sstate.cnt[sstate.col[i]];
	sstate.q.clear(); REP(i,nq) { int pos,col; scanf("%d%d",&pos,&col); --pos,--col; sstate.q.PB(Q(pos,col,i)); }
	solve();
	REPE(i,nq) printf("%d\n",ans[i]);
}

void stress() {
	int mxn=10,mxcol=10;
	REP(rep,1000) {
		sstate.n=rand()%mxn+1;
		sstate.ncol=rand()%mxcol+1;
		sstate.col=vector<int>(sstate.n); REP(i,sstate.n) sstate.col[i]=rand()%sstate.ncol;
		sstate.sum=sstate.match=sstate.mx=vector<int>(sstate.n,-1); sstate.cnt=vector<int>(sstate.ncol,0); REP(i,sstate.n) ++sstate.cnt[sstate.col[i]];
		sstate.q.clear();
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}