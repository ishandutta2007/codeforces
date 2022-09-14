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

int R,C;
char g[250][250];

bool type1(const vector<pair<int,int> > &cur) {
	if(SZ(cur)<4) return false;
//	REPSZ(i,cur) printf("(%d,%d)",cur[i].first,cur[i].second); puts("");
	int lr=INT_MAX,lc=INT_MAX,hr=INT_MIN,hc=INT_MIN;
	REPSZ(i,cur) {
		lr=min(lr,cur[i].first),hr=max(hr,cur[i].first);
		lc=min(lc,cur[i].second),hc=max(hc,cur[i].second);
	}
	if(hr-lr!=hc-lc) return false;
	int size=hr-lr+1;
	if(SZ(cur)!=4*(size-1)) return false;
	REPSZ(i,cur) if(cur[i].first!=lr&&cur[i].first!=hr&&cur[i].second!=lc&&cur[i].second!=hc) return false;
//	printf("OK!\n");
	return true;
}

bool type2(const vector<pair<int,int> > &cur) {
	int A=(cur[0].first+cur[0].second)%2,B=(cur[0].first-cur[0].second)%2; if(B<0) B+=2;
	vector<pair<int,int> > rot;
	REPSZ(i,cur) {
		int r=cur[i].first,c=cur[i].second;
		int a=r+c,b=r-c;
		if(a%2!=A) return false;
		if((b%2+2)%2!=B) return false;
		rot.PB(MP((a-A)/2,(b-B)/2));
	}
	return type1(rot);
}


void run() {
	scanf("%d%d",&R,&C);
	REP(r,R) REP(c,C) scanf(" %c",&g[r][c]);

	int ret=0;
	REP(sr,R) REP(sc,C) if(g[sr][sc]=='1') {
		vector<pair<int,int> > cur;
		queue<pair<int,int> > q;
		q.push(MP(sr,sc)); cur.PB(MP(sr,sc)); g[sr][sc]='0';
		while(!q.empty()) {
			int r=q.front().first,c=q.front().second; q.pop();
			FORE(dr,-1,+1) FORE(dc,-1,+1) {
				int nr=r+dr,nc=c+dc;
				if(nr<0||nr>=R||nc<0||nc>=C|g[nr][nc]!='1') continue;
				q.push(MP(nr,nc)); cur.PB(MP(nr,nc)); g[nr][nc]='0';
			}
		}
		if(type1(cur)||type2(cur)) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}