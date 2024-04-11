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


typedef struct R { string s; R() {} R(string s):s(s) {} } R;
bool operator<(const R &a,const R &b) { if(SZ(a.s)!=SZ(b.s)) return SZ(a.s)>SZ(b.s); return a.s>b.s; } // inverted because of pq

R best[3][1<<8]; // 0=E, 1=T, 2=F


priority_queue<pair<R,pair<int,int> > > pq;
void upd(int i,int j,R val) { if(SZ(best[i][j].s)==0||best[i][j]<val) best[i][j]=val,pq.push(MP(val,MP(i,j))); }

void run() {
	int n; scanf("%d",&n);
	REP(i,n) {
		char s[9]; scanf("%s",s); int x=0; REP(j,8) x=2*x+(s[j]-'0'); printf("%s\n",best[0][x].s.c_str());
	}
}

void precalc() {
	REP(i,3) REP(j,1<<8) best[i][j]=R("");
	int all=(1<<8)-1;

	upd(2,1+4+16+64,R("z")); upd(2,1+2+16+32,R("y")); upd(2,1+2+4+8,R("x"));
	while(!pq.empty()) {
		R r=pq.top().first; int i=pq.top().second.first,j=pq.top().second.second; pq.pop();
		if(r.s!=best[i][j].s) continue;
		//printf("%d %2x = %s\n",i,j,r.s.c_str());
		if(i==2) {
			upd(2,all^j,R("!"+r.s));
			upd(1,j,r);
			REP(jj,1<<8) if(SZ(best[1][jj].s)!=0) upd(1,jj&j,best[1][jj].s+"&"+r.s);
		}
		if(i==1) {
			REP(jj,1<<8) if(SZ(best[2][jj].s)!=0) upd(1,j&jj,r.s+"&"+best[2][jj].s);
			upd(0,j,r);
			REP(jj,1<<8) if(SZ(best[0][jj].s)!=0) upd(0,jj|j,best[0][jj].s+"|"+r.s);
		}
		if(i==0) {
			upd(2,j,"("+r.s+")");
			REP(jj,1<<8) if(SZ(best[1][jj].s)!=0) upd(0,j|jj,r.s+"|"+best[1][jj].s);
		}
	}
}

int main() {
	precalc();
	run();
	return 0;
}