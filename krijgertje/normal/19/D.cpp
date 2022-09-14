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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

const int ADD=1,REM=2,FIND=3;

int n;
vector<pair<int,int> > p;

vector<int> maxy;

void update(int at,int l,int r,int id,bool exists) {
	while(at>=SZ(maxy)) maxy.PB(INT_MIN);
	if(id<l||id>r) return;
	if(l==r) {
		maxy[at]=exists?p[id].second:INT_MIN;
	} else {
		int m=l+(r-l)/2;
		update(2*at+1,l,m,id,exists); update(2*at+2,m+1,r,id,exists);
		maxy[at]=max(maxy[2*at+1],maxy[2*at+2]);
	}
}

int find(int at,int l,int r,int x,int y) {
	while(at>=SZ(maxy)) maxy.PB(INT_MIN);
	if(maxy[at]<=y) return -1;
	if(p[r].first<=x) return -1;
	if(l==r) return l;
	int m=l+(r-l)/2;
	int ret=find(2*at+1,l,m,x,y);
	if(ret!=-1) return ret;
	return find(2*at+2,m+1,r,x,y);	
}

void run() {
	int nq; scanf("%d",&nq);
	vector<int> qtype(nq); vector<pair<int,int> > qp(nq); vector<int> qid(nq);
	REP(i,nq) { char buff[10]; int x,y; scanf("%s%d%d",buff,&x,&y); if(buff[0]=='a') qtype[i]=ADD; else if(buff[0]=='r') qtype[i]=REM; else qtype[i]=FIND; qp[i]=MP(x,y); }
	
	vector<pair<pair<int,int>,int> > tmp;
	REP(i,nq) if(qtype[i]==ADD||qtype[i]==REM) tmp.PB(MP(qp[i],i));
	sort(tmp.begin(),tmp.end());
	p.clear();
	REPSZ(i,tmp) {
		if(i==0||tmp[i].first!=p.back()) p.PB(tmp[i].first);
		qid[tmp[i].second]=SZ(p)-1;
	}	
	n=SZ(p);
	maxy=vector<int>(4*n,INT_MIN);
	
	REP(i,nq) {
		if(qtype[i]==ADD) {
			update(0,0,n-1,qid[i],true);
		} else if(qtype[i]==REM) {
			update(0,0,n-1,qid[i],false);
		} else {
			int id=find(0,0,n-1,qp[i].first,qp[i].second);
			if(id==-1) printf("-1\n"); else printf("%d %d\n",p[id].first,p[id].second);
		}
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}