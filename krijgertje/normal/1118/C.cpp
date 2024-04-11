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

const int MAXN=20;

int n;
int a[MAXN*MAXN];
int g[MAXN][MAXN];

vector<int> ones;
vector<int> twos;
vector<int> fours;

bool solve() {
	sort(a,a+n*n); ones.clear(); twos.clear(); fours.clear();
	for(int l=0,r=l;l<n*n;l=r) { while(r<n*n&&a[l]==a[r]) ++r; int cnt=r-l,val=a[l]; while(cnt>=4) fours.PB(val),cnt-=4; while(cnt>=2) twos.PB(val),cnt-=2; while(cnt>=1) ones.PB(val),cnt-=1; }
	REP(x,n) REP(y,n) g[x][y]=-1;
	REP(rep,3) {
		REP(x,n) REP(y,n) if(g[x][y]==-1) {
			int xx=n-x-1,yy=n-y-1;
			vector<pair<int,int>> cur; cur.PB(MP(x,y)); cur.PB(MP(xx,y)); cur.PB(MP(x,yy)); cur.PB(MP(xx,yy)); sort(cur.begin(),cur.end()); cur.erase(unique(cur.begin(),cur.end()),cur.end());
			if(rep==0&&SZ(cur)!=4) continue;
			if(rep==1&&SZ(cur)!=2) continue;
			if(rep==2&&SZ(cur)!=1) continue;
			if(SZ(cur)==1) { if(SZ(ones)==0) return false; int val=ones.back(); ones.pop_back(); REPSZ(i,cur) g[cur[i].first][cur[i].second]=val; }
			if(SZ(cur)==2) { if(SZ(twos)==0) return false; int val=twos.back(); twos.pop_back(); REPSZ(i,cur) g[cur[i].first][cur[i].second]=val; }
			if(SZ(cur)==4) { if(SZ(fours)==0) return false; int val=fours.back(); fours.pop_back(); REPSZ(i,cur) g[cur[i].first][cur[i].second]=val; }
		}
		if(rep==0) { REPSZ(i,fours) { int val=fours[i]; twos.PB(val); twos.PB(val); } fours.clear(); }
		if(rep==1) { REPSZ(i,twos) { int val=twos[i]; ones.PB(val); ones.PB(val); } twos.clear(); }
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n*n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x,n) { REP(y,n) { if(y!=0) printf(" "); printf("%d",g[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}