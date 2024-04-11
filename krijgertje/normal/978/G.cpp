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

const int MAXDAY=100;
const int MAXEXAM=100;

int nday,nexam;
int l[MAXEXAM],r[MAXEXAM],need[MAXEXAM];

int have[MAXEXAM];
vector<int> availbyday[MAXDAY];
int examonday[MAXDAY];
priority_queue<pair<int,int> > pq;

int ans[MAXDAY];
bool solve() {
	REP(i,nexam) have[i]=0;
	REP(i,nday) availbyday[i].clear(),examonday[i]=-1;
	REP(i,nexam) availbyday[l[i]].PB(i),examonday[r[i]]=i;
	pq=priority_queue<pair<int,int> >();

	REP(i,nday) {
		REPSZ(j,availbyday[i]) { int id=availbyday[i][j]; pq.push(MP(-r[id],id)); }
		if(examonday[i]!=-1) {
			int id=examonday[i];
			if(have[id]!=need[id]) return false;
			ans[i]=nexam+1;
		} else if(!pq.empty()) {
			int id=pq.top().second;
			ans[i]=id+1;
			++have[id];
			if(have[id]==need[id]) pq.pop();
		} else {
			ans[i]=0;
		}
	}
	return true;
}

void run() {
	scanf("%d%d",&nday,&nexam); REP(i,nexam) scanf("%d%d%d",&l[i],&r[i],&need[i]),--l[i],--r[i];
	if(!solve()) { printf("-1\n"); return; }
	REP(i,nday) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}