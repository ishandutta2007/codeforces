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

int n,nq;
int qx[MAXQ],qy[MAXQ];
int match[MAXQ];
bool ans[MAXQ];

pair<ll,int> o[MAXN];

int par[MAXN];
int sz[MAXN];
bool same[MAXN];
int nerr;

vector<pair<int*,int> > changes;
void revert(int to) {
	while(SZ(changes)>to) {
		*changes.back().first=changes.back().second;
		changes.pop_back();
	}
}


pair<int,bool> find(int x) {
	if(par[x]==x) return MP(x,true);
	pair<int,bool> res=find(par[x]);
	return MP(res.first,same[x]?res.second:!res.second);
}
void unite(int x,int y,bool sm) {
	assert(par[x]==x); assert(par[y]==y);
	if(sz[x]<sz[y]) swap(x,y);
	changes.PB(MP(&par[y],par[y]));
	changes.PB(MP(&sz[x],sz[x]));
	par[y]=x; sz[x]+=sz[y]; same[y]=sm;
}

void addedge(int i) {
	int x=qx[i],y=qy[i];
	pair<int,bool> a=find(x),b=find(y);
	if(a.first==b.first) {
		if(a.second==b.second) {
			changes.PB(MP(&nerr,nerr));
			++nerr;
		}
	} else {
		unite(a.first,b.first,a.second!=b.second);
	}
}

void solve(int l,int r) {
	if(l==r) {
		int backup=SZ(changes);
		if(match[l]==-1||match[l]>r) addedge(l);
		ans[l]=nerr==0;
		revert(backup);
	} else {
		int m=l+(r-l)/2;
		int backup=SZ(changes);
		FORE(i,m+1,r) if(match[i]!=-1&&match[i]<l) addedge(match[i]);
		solve(l,m);
		revert(backup);
		FORE(i,l,m) if(match[i]==-1||match[i]>r) addedge(i);
		solve(m+1,r);
		revert(backup);
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) scanf("%d%d",&qx[i],&qy[i]),--qx[i],--qy[i];


	memset(match,-1,sizeof(match));
	REP(i,nq) o[i]=MP((ll)n*qx[i]+qy[i],i); sort(o,o+nq);
	for(int at=0,to=at;at<nq;at=to) {
		while(to<nq&&o[at].first==o[to].first) ++to;
		int cnt=to-at;
		REP(i,cnt/2) {
			match[o[at+2*i].second]=o[at+2*i+1].second;
			match[o[at+2*i+1].second]=o[at+2*i].second;
		}
	}

	nerr=0;
	REP(i,n) par[i]=i,same[i]=true,sz[i]=1;

	solve(0,nq-1);

	REP(i,nq) printf("%s\n",ans[i]?"YES":"NO");
}

int main() {
	run();
	return 0;
}