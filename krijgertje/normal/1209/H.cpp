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
struct Seg { int len; double v,t; double delta; Seg() {} Seg(int len,double v):len(len),v(v) {} };

int n,totdist;
int wwl[MAXN],wwr[MAXN]; double wws[MAXN];

vector<Seg> seg;
vector<pair<double,int>> o;

void buildseg() {
	seg.clear();
	int x=0,at=0;
	while(x<totdist) {
		if(at<n&&x==wwl[at]) {
			seg.PB(Seg(wwr[at]-wwl[at],wws[at]));
			x=wwr[at++];
		} else {
			int nx=min(totdist,at<n?wwl[at]:INT_MAX);
			seg.PB(Seg(nx-x,0));
			x=nx;
		}
	}
	REPSZ(i,seg) seg[i].t=seg[i].v==0?seg[i].len:seg[i].len/seg[i].v;
	REPSZ(i,seg) seg[i].delta=seg[i].v==0?0:seg[i].t;
	//printf("seg:"); REPSZ(i,seg) printf(" (%d,%lf,%lf,%lf)",seg[i].len,seg[i].v,seg[i].t,seg[i].delta); puts("");
}

vector<double> spref;
vector<double> slazy;
vector<double> ssum;

void sapply(int x,double by) { spref[x]+=by; slazy[x]+=by; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { spref[x]=min(spref[2*x+1],spref[2*x+2]); ssum[x]=ssum[2*x+1]+ssum[2*x+2]; }

void smod(int x,int l,int r,int L,int R,double BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
void sset(int x,int l,int r,int IDX,double VAL ) {
	if(l==r) {
		ssum[x]=VAL;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) sset(2*x+1,l,m,IDX,VAL); else sset(2*x+2,m+1,r,IDX,VAL);
		spull(x);
	}
}
double scalcsum(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return ssum[x];
	} else {
		int m=l+(r-l)/2; double ret=0;
		if(L<=m) ret+=scalcsum(2*x+1,l,m,L,R);
		if(m+1<=R) ret+=scalcsum(2*x+2,m+1,r,L,R);
		return ret;
	}
}
double scalcpref(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return spref[x];
	} else {
		int m=l+(r-l)/2; spush(x);
		double ret=1e200;
		if(L<=m) ret=min(ret,scalcpref(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,scalcpref(2*x+2,m+1,r,L,R));
		return ret;
	}
}


double calclim(int idx) { 
	//double pref=0; REP(i,idx) pref+=seg[i].delta; assert(pref>=-1e-9);
	//double want=pref; FORSZ(i,idx+1,seg) { pref+=seg[i].delta; want=min(want,pref); }
	double before=idx==0?0:scalcsum(0,0,SZ(seg)-1,0,idx-1);
	double me=seg[idx].delta;
	double low=idx==SZ(seg)-1?before+me:scalcpref(0,0,SZ(seg)-1,idx+1,SZ(seg)-1);
	double ret=min(before,low-me);
	//printf("want=%lf ret=%lf\n",want,ret);
	return ret;
}

void upd(int idx,double oval,double nval) {
	sset(0,0,SZ(seg)-1,idx,nval);
	smod(0,0,SZ(seg)-1,idx,SZ(seg)-1,nval-oval);
}

double solve() {
	buildseg();
	o.clear(); REPSZ(i,seg) o.PB(MP(seg[i].v,i)); sort(o.begin(),o.end());
	spref=slazy=ssum=vector<double>(4*SZ(seg));
	REPSZ(i,seg) upd(i,0,seg[i].delta);
	REPSZ(i,o) {
		int at=o[i].second;
		double have=calclim(at);
		double lim=min(have,1.0*seg[at].len/(seg[at].v+2));
		double odelta=seg[at].delta;
		seg[at].delta=-lim;
		seg[at].t=(seg[at].len-lim)/(seg[at].v+1);
		upd(at,odelta,seg[at].delta);
		//printf("changed %d to %lf,%lf (have=%lf)\n",at,seg[at].delta,seg[at].t,have);
	}
	double ret=0; REPSZ(i,seg) ret+=seg[i].t; return ret;
}

void run() {
	scanf("%d%d",&n,&totdist);
	REP(i,n) scanf("%d%d%lf",&wwl[i],&wwr[i],&wws[i]);
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}