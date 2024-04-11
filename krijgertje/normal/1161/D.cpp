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

const int MAXLEN=1000;
const int MAXID=2*MAXLEN+2;
const int MOD=998244353;

char s[MAXLEN+1]; int slen;

int id[2][MAXLEN]; int nid,zeroid,oneid;

int par[MAXID],diff[MAXID],sz[MAXID];
int find(int x) { if(par[x]==x) return x; find(par[x]); diff[x]^=diff[par[x]]; return par[x]=par[par[x]]; }
bool unite(int x,int y,int ediff) {
	//printf("unite(%d,%d,%d)\n",x,y,ediff);
	find(x); find(y); int xdiff=diff[x],ydiff=diff[y]; x=par[x]; y=par[y];
	if(x==y) return (xdiff^ydiff^ediff)==0;
	if(sz[x]<sz[y]) swap(x,y),swap(xdiff,ydiff);
	par[y]=x,sz[x]+=sz[y],diff[y]=xdiff^ydiff^ediff; return true;
}

int calc(int sndlen) {
	nid=0;
	REP(i,2) REP(j,slen) id[i][j]=-1;
	REP(j,slen) if(id[0][j]==-1) id[0][j]=id[0][slen-j-1]=nid++;
	int off=slen-sndlen;
	REP(j,sndlen) if(id[1][off+j]==-1) id[1][off+j]=id[1][off+sndlen-j-1]=nid++;

	//REP(i,2) { REP(j,slen) printf("%3d",id[i][j]); puts(""); }
	zeroid=nid++,oneid=nid++;
	REP(i,nid) par[i]=i,diff[i]=0,sz[i]=1;
	if(!unite(zeroid,oneid,1)) return 0;
	REP(i,slen) {
		if(id[1][i]==-1&&s[i]!='?'&&!unite(id[0][i],s[i]=='0'?zeroid:oneid,0)) return 0;
		if(id[1][i]!=-1&&s[i]!='?'&&!unite(id[0][i],id[1][i],s[i]=='1'?1:0)) return 0;
		if(i==off&&!unite(id[1][i],oneid,0)) return 0;
	}
	int ret=1;
	int fixed=find(zeroid);
	REP(i,nid) if(par[i]==i&&i!=fixed) ret=(ll)ret*2%MOD;
	return ret;
}

int solve() {
	int ret=0;
	FORE(sndlen,1,slen-1) {
		ret=(ret+calc(sndlen))%MOD;
		//puts("");
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}