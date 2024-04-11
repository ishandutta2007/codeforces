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

int n;
int v[MAXN];

pair<int,int> o[MAXN];

int solve() {
	REP(i,n) o[i]=MP(v[i],i); sort(o,o+n);
	REP(mightkill,3) {
		int a=-1,b=-1; REP(i,n) if(i!=mightkill) if(a==-1) a=i; else if(b==-1) b=i; if(a==-1||b==-1) continue;
		int d=o[b].first-o[a].first;
		int killleft=-1,killmid=-1,killright=-1; bool ok=true;
		FOR(i,b+1,n) { ll expect=o[b].first+(ll)(i-b-(killright!=-1?1:0))*d; if(o[i].first==expect) continue; if(killright!=-1) { ok=false; break; } killright=o[i].second; }
		FOR(i,a+1,b) { if(killmid!=-1) { ok=false; break; } killmid=o[i].second; }
		for(int i=a-1;i>=0;--i) { ll expect=o[a].first-(ll)(a-i-(killleft!=-1?1:0))*d; if(o[i].first==expect) continue; if(killleft!=-1) { ok=false; break; } killleft=o[i].second; }
		if(!ok) continue;
		vector<int> kill; if(killleft!=-1) kill.PB(killleft); if(killmid!=-1) kill.PB(killmid); if(killright!=-1) kill.PB(killright);
		if(SZ(kill)==1) return kill[0];
		if(SZ(kill)==0) return o[n-1].second;
	}
	return -1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&v[i]);
	int ans=solve();
	printf("%d\n",ans==-1?-1:ans+1);
}

int main() {
	run();
	return 0;
}