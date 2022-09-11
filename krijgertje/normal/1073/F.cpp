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

const int MAXN=200000;
struct Res { int len1,a1,common2,len2,a2,b2,common3,len3,a3,b3,c3,common4,len4,a4,b4,c4,d4; Res() { len1=common2=len2=common3=len3=common4=len4=0; } };

int n;
vector<int> adj[MAXN];

void upd4(Res &res,int common,int len,int a,int b,int c,int d) {
	if(common<res.common4||common==res.common4&&len<=res.len4) return;
	res.common4=common,res.len4=len,res.a4=a,res.b4=b,res.c4=c,res.d4=d;
}
void upd3(Res &res,int common,int len,int a,int b,int c) {
	if(common<res.common3||common==res.common3&&len<=res.len3) return;
	res.common3=common,res.len3=len,res.a3=a,res.b3=b,res.c3=c;
}
void upd2(Res &res,int common,int len,int a,int b) {
	if(common<res.common2||common==res.common2&&len<=res.len2) return;
	res.common2=common,res.len2=len,res.a2=a,res.b2=b;
}
void upd1(Res &res,int len,int a) {
	if(len<=res.len1) return;
	res.len1=len,res.a1=a;
}

Res dfs(int at,int par) {
	Res ret;
	upd1(ret,1,at);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		Res cur=dfs(to,at);
		if(cur.len4>0) upd4(ret,cur.common4,cur.len4,cur.a4,cur.b4,cur.c4,cur.d4);
		if(ret.len2>0&&cur.len2>0) upd4(ret,ret.common2+cur.common2,ret.len2+cur.len2,ret.a2,ret.b2,cur.a2,cur.b2);
		if(ret.len3>0) upd4(ret,ret.common3,ret.len3+cur.len1,ret.a3,ret.b3,ret.c3,cur.a1);
		if(cur.len3>0) upd4(ret,cur.common3,cur.len3+ret.len1,cur.a3,cur.b3,cur.c3,ret.a1);
		if(cur.len3>0) upd3(ret,cur.common3,cur.len3+1,cur.a3,cur.b3,cur.c3);
		if(cur.len2>0&&ret.len1>1) upd3(ret,cur.common2+1,cur.len2+1+ret.len1,cur.a2,cur.b2,ret.a1);
		if(ret.len2>0) upd3(ret,ret.common2,ret.len2+cur.len1,ret.a2,ret.b2,cur.a1);
		if(cur.len2>0) upd2(ret,cur.common2+1,cur.len2+2,cur.a2,cur.b2);
		if(ret.len1>1) upd2(ret,1,cur.len1+1+ret.len1,cur.a1,ret.a1);
		upd1(ret,cur.len1+1,cur.a1);
	}
	return ret;
}

Res solve() {
	return dfs(0,-1);
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	Res ans=solve();
	printf("%d %d\n",ans.a4+1,ans.c4+1);
	printf("%d %d\n",ans.b4+1,ans.d4+1);
}

int main() {
	run();
	return 0;
}