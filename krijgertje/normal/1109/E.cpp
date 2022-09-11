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

const int MAXVAL=100000;
const int MAXN=100000;
const int MAXQ=100000;
const int MAXS=4*MAXN;

int n,MOD;
int sval[MAXN];
int nq;
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qx[MAXQ],qans[MAXQ];

int pmn[MAXVAL+1];
map<int,vector<int>> dv[MAXVAL+1];

vector<pair<int,pair<int,int>>> nonmatched[MAXQ];
vector<pair<int,int>> specials[MAXQ];

int initnonmatched[MAXN];
int initspecial[MAXN];

vector<int> specialvals[MAXN];
vector<pair<int,int>> events[MAXN];



vector<int> factorize(int x) { vector<int> ret; while(x!=1) { ret.PB(pmn[x]); x/=pmn[x]; } return ret; }


int ssum[MAXS],slazy[MAXS],sspecial[MAXS];
void sapply(int x,int val) {
	ssum[x]=(ll)ssum[x]*val%MOD; slazy[x]=(ll)slazy[x]*val%MOD;
}
void spull(int x) {
	ssum[x]=(ssum[2*x+1]+ssum[2*x+2])%MOD;
}
void spush(int x) {
	if(slazy[x]!=1) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=1;
}
void sinit(int x,int l,int r) {
	if(l==r) {
		slazy[x]=initnonmatched[l],sspecial[x]=initspecial[l],ssum[x]=(ll)slazy[x]*sspecial[x]%MOD;
	} else {
		slazy[x]=1;
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smult(int x,int l,int r,int L,int R,int VAL) {
	//if(x==0) printf("smult(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,VAL);
	if(L<=l&&r<=R) {
		sapply(x,VAL);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smult(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) smult(2*x+2,m+1,r,L,R,VAL);
		spull(x);
	}
}
void ssetspecial(int x,int l,int r,int IDX,int VAL) {
	//if(x==0) printf("ssetspecial(%d,%d..%d,%d,%d)\n",x,l,r,IDX,VAL);
	if(l==r) {
		sspecial[x]=VAL,ssum[x]=(ll)slazy[x]*sspecial[x]%MOD;
	} else {
		int m=l+(r-l)/2; spush(x);
		if(IDX<=m) ssetspecial(2*x+1,l,m,IDX,VAL); else ssetspecial(2*x+2,m+1,r,IDX,VAL);
		spull(x);
	}
}
int sget(int x,int l,int r,int L,int R) {
	//if(x==0) printf("sget(%d,%d..%d,%d..%d)\n",x,l,r,L,R);
	if(L<=l&&r<=R) {
		return ssum[x];
	} else {
		int m=l+(r-l)/2,ret=0; spush(x);
		if(L<=m) ret=(ret+sget(2*x+1,l,m,L,R))%MOD;
		if(m+1<=R) ret=(ret+sget(2*x+2,m+1,r,L,R))%MOD;
		return ret;
	}
}

vector<int> tprod;
void tinit(int id,int x,int l,int r) {
	tprod[x]=1;
	if(l<r) {
		int m=l+(r-l)/2;
		tinit(id,2*x+1,l,m);
		tinit(id,2*x+2,m+1,r);
	}
}
void ttoggle(int id,int x,int l,int r,int IDX) {
	if(l==r) {
		tprod[x]=tprod[x]==1?specialvals[id][l]:1;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) ttoggle(id,2*x+1,l,m,IDX); else ttoggle(id,2*x+2,m+1,r,IDX);
		tprod[x]=(ll)tprod[2*x+1]*tprod[2*x+2]%MOD;
	}
}


void solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;

	for(int i=nq-1;i>=0;--i) {
		if(qkind[i]==1) {
			vector<int> vals=factorize(qx[i]);
			REPSZ(j,vals) {
				int l=ql[i],r=qr[i];
				auto it=dv[vals[j]].lower_bound(l);
				while(it!=dv[vals[j]].end()&&it->first<=r) {
					if(l<=it->first-1) nonmatched[i].PB(MP(vals[j],MP(l,it->first-1)));
					l=it->first+1;
					auto prv=it; it=next(it); int pos=prv->first,trem=prv->second.back(); prv->second.pop_back(); if(SZ(prv->second)==0) dv[vals[j]].erase(prv);
					specialvals[pos].PB(vals[j]); events[pos].PB(MP(i,SZ(specialvals[pos])-1)); events[pos].PB(MP(trem,SZ(specialvals[pos])-1));
				}
				if(l<=r) nonmatched[i].PB(MP(vals[j],MP(l,r)));
			}
		}
		if(qkind[i]==2) {
			vector<int> vals=factorize(qx[i]);
			REPSZ(j,vals) dv[vals[j]][ql[i]].PB(i);
		}
	}
	REP(i,n) {
		vector<int> vals=factorize(sval[i]);
		initnonmatched[i]=1;
		initspecial[i]=1;
		REPSZ(j,vals) {
			auto it=dv[vals[j]].lower_bound(i);
			if(it!=dv[vals[j]].end()&&it->first==i) {
				int pos=it->first,trem=it->second.back(); it->second.pop_back(); if(SZ(it->second)==0) dv[vals[j]].erase(it);
				specialvals[pos].PB(vals[j]); events[pos].PB(MP(-1,SZ(specialvals[pos])-1)); events[pos].PB(MP(trem,SZ(specialvals[pos])-1));
			} else {
				initnonmatched[i]=(ll)initnonmatched[i]*vals[j]%MOD;
			}
		}
	}
	FORE(i,2,MAXVAL) assert(SZ(dv[i])==0);

	REP(i,n) if(SZ(specialvals[i])!=0) {
		sort(events[i].begin(),events[i].end());
		tprod=vector<int>(4*SZ(specialvals[i]));
		tinit(i,0,0,SZ(specialvals[i])-1);
		for(int l=0,r=l;l<SZ(events[i]);l=r) {
			while(r<SZ(events[i])&&events[i][r].first==events[i][l].first) ++r;
			FOR(j,l,r) ttoggle(i,0,0,SZ(specialvals[i])-1,events[i][j].second);
			//printf("%d: at t=%d special=%d\n",i,events[i][l].first,tprod[0]);
			if(events[i][l].first==-1) initspecial[i]=(ll)initspecial[i]*tprod[0]%MOD; else specials[events[i][l].first].PB(MP(i,tprod[0]));
		}
	}

	sinit(0,0,n-1);
	//printf("initnonmatched:"); REP(i,n) printf(" %d",initnonmatched[i]); puts("");
	//printf("initspecial:"); REP(i,n) printf(" %d",initspecial[i]); puts("");
	REP(i,nq) {
		REPSZ(j,nonmatched[i]) {
			int v=nonmatched[i][j].first,l=nonmatched[i][j].second.first,r=nonmatched[i][j].second.second;
			smult(0,0,n-1,l,r,v);
		}
		REPSZ(j,specials[i]) {
			int idx=specials[i][j].first,v=specials[i][j].second;
			ssetspecial(0,0,n-1,idx,v);
		}
		if(qkind[i]==3) {
			qans[i]=sget(0,0,n-1,ql[i],qr[i]);
		}
	}

}

void run() {
	scanf("%d%d",&n,&MOD);
	REP(i,n) scanf("%d",&sval[i]);
	scanf("%d",&nq);
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d%d%d",&ql[i],&qr[i],&qx[i]),--ql[i],--qr[i];
		if(qkind[i]==2) scanf("%d%d",&ql[i],&qx[i]),--ql[i];
		if(qkind[i]==3) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	}
	solve();
	REP(i,nq) if(qkind[i]==3) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}