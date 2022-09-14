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

const int MAXN=1000;
const int MAXM=100000;

int nl,nr,m;
int a[MAXM],b[MAXM];
int el[MAXN][MAXN];
int er[MAXN][MAXN];
int res[MAXM];


void run() {
	scanf("%d%d%d",&nl,&nr,&m);
	REP(i,m) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	memset(el,-1,sizeof(el));
	memset(er,-1,sizeof(er));
	memset(res,-1,sizeof(res));
	REP(i,m) {
		int ca=0; while(el[a[i]][ca]!=-1) ++ca;
		int cb=0; while(er[b[i]][cb]!=-1) ++cb;
		for(int x=i,cnt=0;;++cnt) {
			int y=er[b[x]][ca];
			//printf("%d (%d-%d) becomes %d [%d]\n",x,a[x],b[x],ca,y);
			el[a[x]][ca]=er[b[x]][ca]=x; res[x]=ca;
			if(y==-1) { if(x!=i) er[b[x]][cb]=-1; break; }
			int z=el[a[y]][cb];
			//printf("%d (%d-%d) becomes %d [%d]\n",y,a[y],b[y],cb,z);
			el[a[y]][cb]=er[b[y]][cb]=y; res[y]=cb;
			if(z==-1) { el[a[y]][ca]=-1; break; }
			x=z;
			//if(cnt>20||i>10) exit(0);
		}
	}
	int ret=0;
	REP(i,nl) { int cur=0; REP(j,nr) if(el[i][j]!=-1) ++cur; if(cur>ret) ret=cur; }
	REP(i,nr) { int cur=0; REP(j,nl) if(er[i][j]!=-1) ++cur; if(cur>ret) ret=cur; }
	printf("%d\n",ret);
	REP(i,m) { if(i!=0) printf(" "); printf("%d",res[i]+1); } puts("");
}


int main() {
	run();
	return 0;
}