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

const int MAXN=1000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }

int n;
P p[MAXN];
P d[MAXN];
map<P,int> mp;

bool have[MAXN];

bool ok(P ans) {
	//printf("testing %d %d\n",ans.x,ans.y);
	REP(i,n) have[i]=false;
	REP(i,n) {
		P want=ans-d[i];
		if(!mp.count(want)) return false;
		int idx=mp[want]; if(have[idx]) return false; else have[idx]=true;
	}
	return true;
}

P solve() {
	mp.clear(); REP(i,n) mp[p[i]]=i;
	REP(i,n) if(ok(p[0]+d[i])) return p[0]+d[i];
	assert(false); return P(-1,-1);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	REP(i,n) scanf("%d%d",&d[i].x,&d[i].y);
	P ans=solve();
	printf("%d %d\n",ans.x,ans.y);
}

int main() {
	run();
	return 0;
}