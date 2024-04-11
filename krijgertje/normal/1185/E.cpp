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

const int MAXH=2000;
const int MAXW=2000;
const int MAXSNAKE=26;
struct Snake { int lx,ly,hx,hy; };

int h,w;
char g[MAXH][MAXW+1];
vector<Snake> ans;

vector<pair<int,int>> pos[MAXSNAKE];
int nsnake;
char res[MAXH][MAXW+1];

bool solve() {
	REP(i,MAXSNAKE) pos[i].clear();
	REP(x,h) REP(y,w) if(g[x][y]!='.') pos[g[x][y]-'a'].PB(MP(x,y));
	nsnake=0; REP(i,MAXSNAKE) if(SZ(pos[i])>0) nsnake=i+1;
	ans=vector<Snake>(nsnake);
	for(int i=nsnake-1;i>=0;--i) {
		if(SZ(pos[i])>=1) {
			int lx=INT_MAX,ly=INT_MAX,hx=INT_MIN,hy=INT_MIN;
			REPSZ(j,pos[i]) { int x=pos[i][j].first,y=pos[i][j].second; lx=min(lx,x); ly=min(ly,y); hx=max(hx,x); hy=max(hy,y); }
			if(lx<hx&&ly<hy) return false;
			ans[i].lx=lx,ans[i].ly=ly,ans[i].hx=hx,ans[i].hy=hy;
		} else {
			assert(i+1<nsnake); ans[i]=ans[i+1];
		}
	}
	REP(x,h) { REP(y,w) res[x][y]='.'; res[x][w]='\0'; }
	REP(i,nsnake) FORE(x,ans[i].lx,ans[i].hx) FORE(y,ans[i].ly,ans[i].hy) res[x][y]='a'+i;
	//REP(x,h) printf("%s\n",res[x]);
	REP(x,h) REP(y,w) if(res[x][y]!=g[x][y]) return false;
	return true;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d %d %d\n",ans[i].lx+1,ans[i].ly+1,ans[i].hx+1,ans[i].hy+1);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}