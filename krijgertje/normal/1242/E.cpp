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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXFACE=100000;
struct Face { int nside,id; };
bool operator<(const Face &a,const Face &b) { return a.nside>b.nside; }

int nface;
Face face[MAXFACE];
int ansn;
vector<int> ans[MAXFACE];

int perim[MAXFACE];
int overlap[MAXFACE];

void solve() {
	sort(face,face+nface);
	perim[0]=face[0].nside,overlap[0]=0;
	FOR(i,1,nface) {
		assert(perim[i-1]>=face[i].nside);
		int lim=i+1<nface?face[i+1].nside:3;
		// 1<=x<=face[i].nside-1, perim[i-1]+face[i].nside-2*x>=lim
		// -> x<=(perim[i-1]+face[i].nside-lim)/2
		overlap[i]=min(face[i].nside-1,(perim[i-1]+face[i].nside-lim)/2);
		perim[i]=perim[i-1]+face[i].nside-2*overlap[i];
	}
	//printf("perim:"); REP(i,nface) printf(" %d",perim[i]); puts("");
	//printf("overlap:"); REP(i,nface) printf(" %d",overlap[i]); puts("");

	ansn=0; REP(i,nface) ans[i].clear();
	vector<int> cur(perim[0]); REPSZ(i,cur) cur[i]=ansn++;
	ans[face[0].id]=cur;
	FOR(i,1,nface) {
		assert(overlap[i]<face[i].nside&&overlap[i]<SZ(cur)&&SZ(cur)+face[i].nside-2*overlap[i]>=3);
		vector<int> me;
		me.PB(cur[0]);
		REP(j,overlap[i]-1) { int x=cur.back(); cur.pop_back(); me.PB(x); }
		me.PB(cur.back());
		REP(j,face[i].nside-overlap[i]-1) { int x=ansn++; me.PB(x); cur.PB(x); }
		ans[face[i].id]=me;
		assert(SZ(cur)==perim[i]);
		assert(SZ(me)==face[i].nside);
		if(perim[i-1]==3&&overlap[i]==1) rotate(cur.begin(),cur.begin()+SZ(cur)-1,cur.end());
	}
}

void run() {
	scanf("%d",&nface);
	REP(i,nface) scanf("%d",&face[i].nside),face[i].id=i;
	solve();
	printf("%d\n",ansn);
	REP(i,nface) { REPSZ(j,ans[i]) { if(j!=0) printf(" "); printf("%d",ans[i][j]+1); } puts(""); }
}

int main() {
	run();
	return 0;
}