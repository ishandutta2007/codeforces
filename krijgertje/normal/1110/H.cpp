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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXLEN=2000;
const int MAXBOUNDLEN=801;
const int MAXSTATE=2*(MAXBOUNDLEN+1);

char bound[2][MAXBOUNDLEN+1]; int boundlen[2];
int len;


// comp[i][l][r][d][j] is comparison of bound[i][l..r)+d with bound[j]
// -1 is first is smaller, +1 is first is larger, 0 is first is prefix, -2 is invalid (if length of first is larger than that of second)
int comp[2][MAXBOUNDLEN+1][MAXBOUNDLEN+1][10][2]; 
int calccomp(int cur,char a,char b,int ifzero) { return cur!=0?cur:a=='\0'||b=='\0'?-2:a==b?ifzero:a<b?-1:+1; }

pair<int,int> nxt[2][MAXBOUNDLEN+1][10]; // nxt[i][r][d] is (ni,nr)
int gain[2][MAXBOUNDLEN+1][10][MAXBOUNDLEN+1]; // gain[i][r][d][x] is gain when moving from (i,r) through d to nxt[i][r][d], when there are (at least) x characters remaining after d
int endgain[2][MAXBOUNDLEN+1];


int tmpcnt[MAXBOUNDLEN+1];
int tmpdelta[MAXBOUNDLEN+1];
void incgain(int i,int r,int d,int need) {
	//printf("gain[%d][%d][%d][%d]\n",i,r,d,need); 
	need=max(need,0); ++tmpcnt[need];
}
void incgain(int i,int r,int d,int lneed,int rneed) {
	//printf("gain[%d][%d][%d][%d..%d]\n",i,r,d,lneed,rneed);
	if(lneed<0) tmpcnt[0]+=-lneed,lneed=0;
	++tmpdelta[lneed];
	if(rneed+1<0) tmpcnt[0]-=-(rneed+1),rneed=-1;
	--tmpdelta[rneed+1];
}
void calcgain(int i,int r,int d) {
	REPE(x,MAXBOUNDLEN) gain[i][r][d][x]=tmpcnt[x];
	FORE(x,1,MAXBOUNDLEN) gain[i][r][d][x]+=gain[i][r][d][x-1];
	int curcnt=0,curdelta=0; REPE(x,MAXBOUNDLEN) { curdelta+=tmpdelta[x]; curcnt+=curdelta; gain[i][r][d][x]+=curcnt; } assert(curdelta==0);
}

int dp[MAXLEN+1][2][MAXBOUNDLEN+1]; // dp[j][i][r] = maximum number of good substrings, if current state is (i,r), and we can place j more digits
int act[MAXLEN+1][2][MAXBOUNDLEN+1];
void upd(int j,int i,int r,int v,int a) { if(v>dp[j][i][r]||v==dp[j][i][r]&&a<act[j][i][r]) dp[j][i][r]=v,act[j][i][r]=a; }

void solve() {
	REP(i,2) REPE(l,boundlen[i]) REP(j,2) {
		int cur=0;
		REPE(ilen,boundlen[i]-l) {
			int r=l+ilen;
			int ifzero=ilen+1==boundlen[j]?j==0?+1:-1:0;
			REP(d,10) comp[i][l][r][d][j]=calccomp(cur,'0'+d,bound[j][ilen],ifzero);
			cur=calccomp(cur,bound[i][l+ilen],bound[j][ilen],ifzero);
		}
	}
	
	memset(gain,0,sizeof(gain));
	REP(i,2) REPE(r,boundlen[i]) REP(d,10) {
		nxt[i][r][d]=MP(0,0);
		REPE(l,r) REP(j,2) if(comp[i][l][r][d][j]==0&&r-l+1>nxt[i][r][d].second||r-l+1==nxt[i][r][d].second&&j==0&&nxt[i][r][d].first==1) nxt[i][r][d]=MP(j,r-l+1);
		memset(tmpcnt,0,sizeof(tmpcnt)); memset(tmpdelta,0,sizeof(tmpdelta)); 
		REPE(l,r) if(r-l+1>nxt[i][r][d].second&&(l<r&&bound[i][l]!='0'||l==r&&d!=0)) {
			assert(comp[i][l][r][d][0]!=0&&comp[i][l][r][d][1]!=0);
			if(boundlen[0]==boundlen[1]&&comp[i][l][r][d][0]==+1&&comp[i][l][r][d][1]==-1) incgain(i,r,d,boundlen[0]-(r-l+1));
			if(boundlen[0]!=boundlen[1]&&comp[i][l][r][d][0]==+1) incgain(i,r,d,boundlen[0]-(r-l+1));
			if(boundlen[0]!=boundlen[1]&&comp[i][l][r][d][1]==-1) incgain(i,r,d,boundlen[1]-(r-l+1));
			if(boundlen[0]+1<=boundlen[1]-1) incgain(i,r,d,boundlen[0]+1-(r-l+1),boundlen[1]-1-(r-l+1));
		}
		calcgain(i,r,d);
		//if(nxt[i][r][d]!=MP(0,0)) printf("(%d,%d)+%d=(%d,%d)\n",i,r,d,nxt[i][r][d].first,nxt[i][r][d].second);
		//if(i==1&&r==1&&d==2) { printf("here:"); REP(x,10) printf(" %d",gain[i][r][d][x]); puts(""); exit(0); }
	}
	REP(i,2) REPE(r,boundlen[i]) {
		endgain[i][r]=0;
		REP(l,r) if(bound[i][l]!='0') {
			if(boundlen[0]==boundlen[1]&&r-l>=boundlen[0]&&comp[i][l][r-1][bound[i][r-1]-'0'][0]==+1&&comp[i][l][r-1][bound[i][r-1]-'0'][1]==-1) ++endgain[i][r];
			if(boundlen[0]!=boundlen[1]&&r-l>=boundlen[0]&&comp[i][l][r-1][bound[i][r-1]-'0'][0]==+1) ++endgain[i][r];
			if(boundlen[0]!=boundlen[1]&&r-l>=boundlen[1]&&comp[i][l][r-1][bound[i][r-1]-'0'][1]==-1) ++endgain[i][r];
			if(boundlen[0]+1<=min(boundlen[1]-1,r-l)) endgain[i][r]+=min(boundlen[1]-1,r-l)-(boundlen[0]+1)+1;
		}
		//printf("endgain[%d][%d]=%d\n",i,r,endgain[i][r]);
	}
	
	REPE(j,len) REP(i,2) REPE(r,boundlen[i]) dp[j][i][r]=INT_MIN,act[j][i][r]=-2;
	REP(i,2) REPE(r,boundlen[i]) dp[0][i][r]=endgain[i][r],act[0][i][r]=-1;
	FORE(j,1,len) REP(i,2) REPE(r,boundlen[i]) REP(d,10) {
		int ni=nxt[i][r][d].first,nr=nxt[i][r][d].second; if(dp[j-1][ni][nr]==INT_MIN) continue; int nval=dp[j-1][ni][nr]+gain[i][r][d][min(MAXBOUNDLEN,j-1)];
		upd(j,i,r,nval,d);
	}
	
	/*printf("test %d\n",dp[3][0][0]);
	printf("test %d (%d,%d:%d)\n",dp[3][0][0],nxt[0][0][act[3][0][0]].first,nxt[0][0][act[3][0][0]].second,gain[0][0][act[3][0][0]][3-1]);
	printf("test %d (%d,%d:%d)\n",dp[2][1][1],nxt[1][1][2].first,nxt[1][1][2].second,gain[1][1][2][2-1]);
	printf("test %d (%d,%d:%d)\n",-1,nxt[1][1][1].first,nxt[1][1][1].second,gain[1][1][1][2-1]);
	//printf("test %d (%d,%d:%d)\n",dp[1][1][1],nxt[1][1][1].first,nxt[1][1][1].second,gain[1][1][1][0]);
	printf("test %d\n",dp[1][0][0]);*/
	
	printf("%d\n",dp[len][0][0]);
	for(int j=len,i=0,r=0;act[j][i][r]!=-1;) {
		printf("%d",act[j][i][r]);
		int nj=j-1,ni=nxt[i][r][act[j][i][r]].first,nr=nxt[i][r][act[j][i][r]].second; j=nj,i=ni,r=nr;
	}
	puts("");
}

void run() {
	scanf("%s",bound[0]); boundlen[0]=strlen(bound[0]);
	scanf("%s",bound[1]); boundlen[1]=strlen(bound[1]);
	scanf("%d",&len);
	solve();
}

int main() {
	run();
	return 0;
}