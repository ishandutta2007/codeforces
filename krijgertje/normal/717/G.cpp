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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500;
const int MAXW=100;
const int MAXGN=MAXN+1;
const int MAXGM=MAXN+MAXN*MAXW;

typedef struct G {
	int n,m;
	int head[MAXGN],nxt[2*MAXGM],to[2*MAXGM],cap[2*MAXGM],cst[2*MAXGM];
	int dst[MAXGN],bck[MAXGN];
	void init(int _n) { n=_n,m=0; REP(i,n) head[i]=-1; }
	void addedge(int a,int b,int c,int d) {
		nxt[m]=head[a],head[a]=m,to[m]=b,cap[m]=c,cst[m]=+d,++m;
		nxt[m]=head[b],head[b]=m,to[m]=a,cap[m]=0,cst[m]=-d,++m;
	}
	pair<int,int> mcmf(int s,int t,int mx) {
		pair<int,int> ret=MP(0,0);
		while(ret.first<mx) {
			REP(i,n) dst[i]=i==s?0:INT_MAX,bck[i]=-1;
			while(true) {
				bool change=false;
				REP(i,n) if(dst[i]!=INT_MAX) for(int x=head[i];x!=-1;x=nxt[x]) if(cap[x]>0&&dst[i]+cst[x]<dst[to[x]]) dst[to[x]]=dst[i]+cst[x],bck[to[x]]=x^1,change=true;
				if(!change) break;
			}
			if(dst[t]==INT_MAX) break;
			ret.first++,ret.second+=dst[t];
			for(int u=t;u!=s;u=to[bck[u]]) cap[bck[u]]++,cap[bck[u]^1]--;
			//vector<int> tmp; for(int u=t;u!=s;u=to[bck[u]]) tmp.PB(u); tmp.PB(s); reverse(tmp.begin(),tmp.end()); REPSZ(i,tmp) printf("%d ",tmp[i]); printf("= %d\n",dst[t]);
		}
		return ret;
	}
} G;

int n;
char s[MAXN+1];
int nw;
char w[MAXW][MAXN+1]; int p[MAXW];
int mxuse;
G g;
bool match(int i,int j) { int len=strlen(w[j]); REP(k,len) if(s[i+k]!=w[j][k]) return false; return true; }

void run() {
	scanf("%d%s",&n,s);
	scanf("%d",&nw); REP(i,nw) scanf("%s%d",w[i],&p[i]);
	scanf("%d",&mxuse);

	g.init(n+1);
	REP(i,n) g.addedge(i,i+1,mxuse,0);
	REP(i,n) REP(j,nw) if(match(i,j)) g.addedge(i,i+strlen(w[j]),1,-p[j]);
	pair<int,int> res=g.mcmf(0,n,mxuse);
	printf("%d\n",-res.second);


}

int main() {
	run();
	return 0;
}