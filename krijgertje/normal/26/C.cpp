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
#include <stack>
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

void run() {
	int n,m,a,b,c; scanf("%d%d%d%d%d",&n,&m,&a,&b,&c); //1x2,2x1,2x2 - nxm
	VVI g(n,VI(m,-1));
	vector<bool> split; int q=0; bool ok=true;
	REP(x,n) REP(y,m) if(g[x][y]==-1) {
		if(x+1<n&&y+1<m) {
			assert(g[x+1][y]==-1&&g[x][y+1]==-1&&g[x+1][y+1]==-1);
			g[x][y]=g[x+1][y]=g[x][y+1]=g[x+1][y+1]=q++;
			if(c>0) {
				--c; split.PB(false);
			} else {
				split.PB(true);
			}
		} else if(x+1<n) {
			assert(g[x+1][y]==-1);
			if(b==0) { ok=false; break; }
			g[x][y]=g[x+1][y]=q++;
			--b; split.PB(false);
		} else if(y+1<m) {
			assert(g[x][y+1]==-1);
			if(a==0) { ok=false; break; }
			g[x][y]=g[x][y+1]=q++;
			--a; split.PB(false);
		} else {
			ok=false; break;
		}
	}
	REP(x,n) REP(y,m) if(g[x][y]!=-1&&split[g[x][y]]) {
		split[g[x][y]]=false;
		if(a>=2) {
			g[x][y]=g[x][y+1]=q++; split.PB(false);
			a-=2;
		} else if(b>=2) {
			g[x][y]=g[x+1][y]=q++; split.PB(false);
			b-=2;
		} else {
			ok=false; break;
		}
	}
	if(!ok) { printf("IMPOSSIBLE\n"); return; }
	string s(q,'?');
//	REP(x,n) { REP(y,m) printf("%d ",g[x][y]); puts(""); }
	REP(x,n) REP(y,m) {
		int now=g[x][y];
		if(s[now]=='?') {
			int adjmask=0;
			FORE(dx,-1,+1) FORE(dy,-1,+1) {
				int xx=x+dx,yy=y+dy;
				if(xx<0||xx>=n||yy<0||yy>=m||g[xx][yy]!=g[x][y]) continue;
				FORE(dx2,-1,+1) FORE(dy2,-1,+1) {
					int xxx=xx+dx2,yyy=yy+dy2;
					if(xxx<0||xxx>=n||yyy<0||yyy>=m||s[g[xxx][yyy]]=='?') continue;
					adjmask|=1<<(s[g[xxx][yyy]]-'a');
				}
			}
			for(int i=0;;++i) if((adjmask&(1<<i))==0) { s[now]='a'+i; break; }
		}
		printf("%c",s[now]); if(y==m-1) puts("");
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}