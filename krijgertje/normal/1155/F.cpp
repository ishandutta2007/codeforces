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

const int MAXN=14;
struct Path { int mask,a,b; Path() {} Path(int mask,int a,int b):mask(mask),a(a),b(b) {} };

int n,m;
vector<int> adj[MAXN];

int adjmask[MAXN];
bool isadj[MAXN][MAXN];
int prvpath[1<<MAXN][MAXN][MAXN];

int best[1<<MAXN];
Path lastpath[1<<MAXN];
int bc[1<<MAXN];

vector<pair<int,int>> ans;

void addpath(int mask,int a,int b) {
	//printf("addpath(%x,%d,%d)\n",mask,a+1,b+1);
	while(prvpath[mask][a][b]>=0) {
		int c=prvpath[mask][a][b];
		assert((mask&(1<<c))!=0&&isadj[b][c]);
		ans.PB(MP(b,c));
		mask-=(1<<b); b=c;
		//printf("\taddpath(%x,%d,%d)\n",mask,a+1,b+1);
	}
	assert(prvpath[mask][a][b]==-1);
}

void solve() {
	REP(i,n) adjmask[i]=0; REP(i,n) REPSZ(j,adj[i]) adjmask[i]|=1<<adj[i][j];
	REP(i,n) REP(j,n) isadj[i][j]=false; REP(i,n) REPSZ(j,adj[i]) isadj[i][adj[i][j]]=true;
	//REP(i,n) { printf("isadj%d",i); REP(j,n) printf("%c",isadj[i][j]?'V':'.'); puts(""); }

	REP(mask,1<<n) REP(a,n) REP(b,n) prvpath[mask][a][b]=-2;
	REP(a,n) prvpath[1<<a][a][a]=-1;
	REP(mask,1<<n) REP(a,n) REP(b,n) if(prvpath[mask][a][b]!=-2) REP(c,n) if((mask&(1<<c))==0&&isadj[b][c]&&prvpath[mask|(1<<c)][a][c]==-2) prvpath[mask|(1<<c)][a][c]=b;
	//REP(mask,1<<n) REP(a,n) REP(b,n) if(prvpath[mask][a][b]!=-2) printf("path %x: %d->%d\n",mask,a+1,b+1);
	
	REP(mask,1<<n) best[mask]=INT_MAX;
	REP(mask,1<<n) { bc[mask]=0; REP(i,n) if(mask&(1<<i)) ++bc[mask]; }
	REP(mask,1<<n) if(bc[mask]>=3) {
		REP(a,n) REP(b,n) if(prvpath[mask][a][b]!=-2&&isadj[a][b]&&bc[mask]<best[mask]) {
			//printf("can[%x]=cycle %d->%d\n",mask,a+1,b+1);
			best[mask]=bc[mask]; lastpath[mask]=Path(mask,a,b);
		}
	}
	REP(mask,1<<n) if(best[mask]!=INT_MAX) {
		int remmask=(1<<n)-1-mask;
		for(int pathmask=(mask+1)&remmask;;pathmask=(pathmask+mask+1)&remmask) {
			REP(a,n) if((pathmask&(1<<a))!=0&&(adjmask[a]&mask)!=0) FOR(b,a+1,n) if((pathmask&(1<<b))!=0&&(adjmask[b]&mask)!=0) if(prvpath[pathmask][a][b]!=-2) {
				int nmask=mask|pathmask,ncost=best[mask]+bc[pathmask]+1;
				if(ncost<best[nmask]) best[nmask]=ncost,lastpath[nmask]=Path(pathmask,a,b);
			}
			if(bc[pathmask]==1) REP(a,n) if(pathmask==(1<<a)&&bc[adjmask[a]&mask]>=2) {
				int nmask=mask|pathmask,ncost=best[mask]+2;
				if(ncost<best[nmask]) best[nmask]=ncost,lastpath[nmask]=Path(pathmask,a,a);
			}
			if(pathmask==remmask) break;
		}
	}
	//printf("bestcost: %d\n",best[(1<<n)-1]);

	ans.clear();
	{
		int mask=(1<<n)-1;
		while(mask!=0) {
			Path last=lastpath[mask];
			//printf("mask=%x last=%x %d->%d:",mask,last.mask,last.a+1,last.b+1); REP(i,n) if(last.mask&(1<<i)) printf(" %d",i+1); puts("");
			addpath(last.mask,last.a,last.b);
			mask-=last.mask;
			if(mask!=0) {
				if(last.a==last.b) {
					assert(last.mask=(1<<last.a));
					int foundcnt=0; REP(i,n) if((mask&(1<<i))!=0&&isadj[i][last.a]&&foundcnt<2) { ++foundcnt; ans.PB(MP(i,last.a)); } assert(foundcnt==2);
				} else {
					bool founda=false; REP(i,n) if((mask&(1<<i))!=0&&isadj[i][last.a]) { founda=true; ans.PB(MP(i,last.a)); break; } assert(founda);
					bool foundb=false; REP(i,n) if((mask&(1<<i))!=0&&isadj[i][last.b]) { foundb=true; ans.PB(MP(i,last.b)); break; } assert(foundb);
				}
			} else {
				ans.PB(MP(last.a,last.b));
			}
		}
	}

	
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}