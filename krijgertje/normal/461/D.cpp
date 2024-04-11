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

const int MAXSZ=100000;
const int MOD=1000000007;

int sz,nhave;

int par[2*MAXSZ+4];
int rnk[2*MAXSZ+4];

int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
void unite(int a,int b) {
	//printf("uniting %d and %d\n",a,b);
	a=find(a),b=find(b); if(a==b) return;
	if(rnk[a]<rnk[b]) swap(a,b);
	par[b]=a; if(rnk[a]==rnk[b]) ++rnk[a];
}

void run() {
	scanf("%d%d",&sz,&nhave);
	REP(i,2*sz+4) par[i]=i,rnk[i]=0;
	REP(i,nhave) {
		int x,y; char c; scanf("%d%d %c",&x,&y,&c); --x,--y;
		int a=abs(y-x),b=sz-1-abs(sz-1-y-x)+2,z=c=='o'?1:0;
		unite(2*a+0,2*b+z); unite(2*a+1,2*b+1-z);
	}
	int cnt=0;
	REP(i,sz+2) {
		if(find(2*i)==find(2*i+1)) { printf("0\n"); return; }
		if(par[2*i]==2*i) ++cnt;
		if(par[2*i+1]==2*i+1) ++cnt;
	}
	int ret=1;
	REP(i,cnt/2-2) ret=2*ret%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}