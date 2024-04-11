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

const int MOD=998244353;
const int MAXN=1000;
const int MAXCOL=3;
const int MAXSTEP=3;
const int MAXGRUNDY=3;
const int MAXSTATE=(MAXGRUNDY+1)*(MAXGRUNDY+1)*(MAXGRUNDY+1);
const int MAXLG=30;
const ll MODUNDOOVERFLOW=(1ULL<<63)/MOD*MOD;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
int sz[MAXN];
int nknown;
vector<pair<int,int>> known[MAXN];
int allowed[MAXCOL][MAXSTEP+1];

vector<vector<int>> mat[MAXCOL+1];
int stripways[MAXN][MAXGRUNDY+1];
int dp[MAXN+1][MAXGRUNDY+1];

vector<vector<int>> matpw[MAXCOL+1][MAXLG+1];

int mex(int mask) { int ret=0; while(mask&(1<<ret)) ++ret; return ret; }
int encode(int a,int b,int c) { assert(0<=a&&a<=MAXGRUNDY&&0<=b&&b<=MAXGRUNDY&&0<=c&&c<=MAXGRUNDY); return a*(MAXGRUNDY+1)*(MAXGRUNDY+1)+b*(MAXGRUNDY+1)+c; }
void decode(int code,int &a,int &b,int &c) { c=code%4; code/=4; b=code%4; code/=4; a=code; }

bool reachable[MAXSTATE];
int mp[MAXSTATE],invmp[MAXSTATE];

vector<vector<int>> mmlt(vector<vector<int>> A,vector<vector<int>> B) {
	assert(SZ(A)>=1&&SZ(B)>=1&&SZ(A[1])==SZ(B)); int n=SZ(A),k=SZ(A[0]),m=SZ(B[0]); vector<vector<int>> ret(n,vector<int>(m,0));
	REP(i,n) REP(j,n) REP(x,k) { ll sum=0; REP(x,n) { sum+=(ll)A[i][x]*B[x][j]; if(sum<0) sum-=MODUNDOOVERFLOW; } sum%=MOD; ret[i][j]=sum; } return ret;
}
vector<vector<int>> mpw(vector<vector<int>> x,int n) {
	int dim=SZ(x); assert(dim>=1&&SZ(x[0])==dim); vector<vector<int>> ret(dim,vector<int>(dim,0)); REP(i,dim) ret[i][i]=1;
	while(true) { if(n&1) ret=mmlt(ret,x); if((n>>=1)==0) return ret; x=mmlt(x,x); }
}
vector<int> combine(vector<int> ways,vector<vector<int>> mat) {
	int dim=SZ(ways); assert(dim>=1&&SZ(mat)==dim&&SZ(mat[0])==dim); vector<int> ret(dim,0);
	REP(i,dim) REP(j,dim) ret[j]=(ret[j]+(ll)ways[i]*mat[i][j])%MOD; return ret;
}

int solve() {
	memset(reachable,false,sizeof(reachable)); queue<int> q;
	REPE(g0,MAXGRUNDY) { if(g0!=0) continue; REPE(g1,MAXGRUNDY) { if(g1!=0&&g1!=mex(1<<g0)) continue; REPE(g2,MAXGRUNDY) { if(g2!=0&&g2!=mex(1<<g0)&&g2!=mex(1<<g1)&&g2!=mex((1<<g0)|(1<<g1))) continue; int code=encode(g0,g1,g2); reachable[code]=true; q.push(code); } } }
	while(!q.empty()) { int at=q.front(); q.pop(); REP(col,MAXCOL) { int g0,g1,g2; decode(at,g0,g1,g2); int mask=0; if(allowed[col][1]) mask|=1<<g2; if(allowed[col][2]) mask|=1<<g1; if(allowed[col][3]) mask|=1<<g0; int g3=mex(mask); int to=encode(g1,g2,g3); if(!reachable[to]) reachable[to]=true,q.push(to); } }
	int nreachable=0; REP(i,MAXSTATE) if(reachable[i]) mp[i]=nreachable,invmp[nreachable]=i,++nreachable; else mp[i]=-1;
	//printf("nreachable=%d\n",nreachable); printf("reachable: "); REP(i,MAXSTATE) printf("%c",reachable[i]?'V':'.'); puts("");


	REPE(i,MAXCOL) {
		mat[i]=vector<vector<int>>(nreachable,vector<int>(nreachable,0));
		REPE(g0,MAXGRUNDY) REPE(g1,MAXGRUNDY) REPE(g2,MAXGRUNDY) REP(col,MAXCOL) {
			if(i<MAXCOL&&col!=i) continue;
			int mask=0; if(allowed[col][1]) mask|=1<<g2; if(allowed[col][2]) mask|=1<<g1; if(allowed[col][3]) mask|=1<<g0; int g3=mex(mask);
			int a=mp[encode(g0,g1,g2)],b=mp[encode(g1,g2,g3)];
			if(a!=-1&&b!=-1) inc(mat[i][a][b],1);
		}
	}

	REPE(i,MAXCOL) { matpw[i][0]=mat[i]; FORE(k,1,MAXLG) matpw[i][k]=mmlt(matpw[i][k-1],matpw[i][k-1]); }

	REP(i,n) {
		REPE(j,MAXGRUNDY) stripways[i][j]=0;
		sort(known[i].begin(),known[i].end());
		vector<int> col(MAXSTEP,-1); REPSZ(j,known[i]) if(known[i][j].first<SZ(col)) col[known[i][j].first]=known[i][j].second; FORSZ(j,sz[i],col) col[j]=0;
		vector<int> ways(nreachable,0);
		REP(a,MAXCOL) REP(b,MAXCOL) REP(c,MAXCOL) {
			if(col[0]!=-1&&col[0]!=a) continue;
			if(col[1]!=-1&&col[1]!=b) continue;
			if(col[2]!=-1&&col[2]!=c) continue;
			vector<int> g(MAXSTEP);
			int amask=0; g[0]=mex(amask);
			int bmask=0; if(allowed[b][1]) bmask|=1<<g[0]; g[1]=mex(bmask);
			int cmask=0; if(allowed[c][1]) cmask|=1<<g[1]; if(allowed[c][2]) cmask|=1<<g[0]; g[2]=mex(cmask);
			int code=encode(g[0],g[1],g[2]);
			if(sz[i]==1) inc(stripways[i][g[0]],1); else if(sz[i]==2) inc(stripways[i][g[1]],1); else if(sz[i]==3) inc(stripways[i][g[2]],1); else { assert(mp[code]!=-1); inc(ways[mp[code]],1); }
			//printf("%d: %d/%d/%d\n",i,g[0],g[1],g[2]);
		}
		if(sz[i]>3) {
			int last=2; vector<pair<int,int>> e; REPSZ(j,known[i]) if(known[i][j].first>=SZ(col)) e.PB(known[i][j]); e.PB(MP(sz[i],0));
			REPSZ(j,e) {
				int nfree=e[j].first-last-1;
				//ways=combine(combine(ways,mpw(mat[MAXCOL],nfree)),mat[e[j].second]);
				REPE(k,MAXLG) if(nfree&(1<<k)) ways=combine(ways,matpw[MAXCOL][k]);
				ways=combine(ways,mat[e[j].second]);
				last=e[j].first;
			}
			REPSZ(mappedcode,ways) {
				int code=invmp[mappedcode],g0,g1,g2; decode(code,g0,g1,g2);
				inc(stripways[i][g1],ways[mappedcode]);
			}
		}
		//printf("stripways:"); REPE(j,MAXGRUNDY) printf(" %d",stripways[i][j]); puts("");
	}
	REPE(j,MAXGRUNDY) dp[0][j]=0; inc(dp[0][0],1);
	REP(i,n) {
		REPE(j,MAXGRUNDY) dp[i+1][j]=0;
		REPE(j,MAXGRUNDY) REPE(k,MAXGRUNDY) dp[i+1][j^k]=(dp[i+1][j^k]+(ll)dp[i][j]*stripways[i][k])%MOD;
	}
	return dp[n][0];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&sz[i]);
	scanf("%d",&nknown);
	REP(i,nknown) { int x,y,z; scanf("%d%d%d",&x,&y,&z); --x,--y,--z; known[x].PB(MP(y,z)); }
	REP(i,MAXCOL) FORE(j,1,MAXSTEP) scanf("%d",&allowed[i][j]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}