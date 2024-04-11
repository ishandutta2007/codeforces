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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n,m;
bool badcol[1000];
bool badrow[1000];

bool bad[4000];
int cnte[4000];
int e[4000][3];

int id[4000];
int nn;
int orig[8];
int adj[8][8];

int qh,qt;
int q[8];

void getxy(int at,int &x,int &y) {
	if(at<2*n) { x=at; y=0; if(x>=n) { x-=n; y=n-1; } }
	else { y=at-2*n; x=0; if(y>=n) { y-=n; x=n-1; } }
}
int getid(int x,int y) {
	if(y==0) return x; if(y==n-1) return n+x; if(x==0) return 2*n+y; if(x==n-1) return 3*n+y; assert(false);
}

void addedge(int a,int b) { e[a][cnte[a]++]=b; e[b][cnte[b]++]=a; }
bool testedge(int a,int b) { REP(i,cnte[a]) if(e[a][i]==b) return true; return false; }

void run(int casenr) {
	memset(badcol,false,sizeof(badcol));
	memset(badrow,false,sizeof(badrow));
	scanf("%d%d",&n,&m);
	REP(i,m) { int x,y; scanf("%d%d",&x,&y); --x,--y; badrow[x]=true; badcol[y]=true; }

	memset(bad,false,sizeof(bad));
	REP(x,n) bad[getid(x,0)]=bad[getid(x,0)]||x==0||x==n-1||badrow[x];
	REP(x,n) bad[getid(x,n-1)]=bad[getid(x,n-1)]||x==0||x==n-1||badrow[x];
	REP(y,n) bad[getid(0,y)]=bad[getid(0,y)]||y==0||y==n-1||badcol[y];
	REP(y,n) bad[getid(n-1,y)]=bad[getid(n-1,y)]||y==0||y==n-1||badcol[y];
	REP(i,4*n) if(i%n==0||i%n==n-1) bad[i]=true;
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(x,0),getid(x,n-1));
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(0,x),getid(n-1,x));
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(x,0),getid(0,x));
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(x,0),getid(n-1,n-1-x));
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(x,n-1),getid(n-1,x));
	REP(x,n) if(x!=0&&x!=n-1) addedge(getid(x,n-1),getid(0,n-1-x));
//	REP(i,4*n) { int x,y; getxy(i,x,y); printf("%c (%d,%d):",bad[i]?'X':'V',x,y); REP(j,cnte[i]) { getxy(e[i][j],x,y); printf(" (%d,%d)",x,y); } puts(""); }

	int ret=0;
	memset(id,-1,sizeof(id));
	REP(start,4*n) if(start%n!=0&&start%n!=n-1&&id[start]==-1) {
		nn=0; memset(adj,false,sizeof(adj)); qh=qt=0;
		orig[nn]=start; id[start]=nn; q[qh++]=start; ++nn;
		while(qt<qh) {
			int at=q[qt++];
			REP(i,cnte[at]) {
				int to=e[at][i];
				if(id[to]==-1) { orig[nn]=to; id[to]=nn; q[qh++]=to; ++nn; }
			}
		}
		REP(i,nn) FOR(j,i+1,nn) adj[i][j]=adj[j][i]=testedge(orig[i],orig[j]);
//		printf("%d\n",nn);
//		REP(i,nn) { int x,y; getxy(orig[i],x,y); printf("(%d,%d): ",x,y); REP(j,nn) printf("%c",adj[i][j]?'X':'.'); puts(""); }
		int best=0;
		REP(mask,1<<nn) {
			bool ok=true;
			REP(i,nn) FOR(j,i+1,nn) if((mask&(1<<i))!=0&&(mask&(1<<j))!=0&&adj[i][j]) ok=false;
			REP(i,nn) if((mask&(1<<i))!=0&&bad[orig[i]]) ok=false;
			if(!ok) continue;
			int cur=0; REP(i,nn) if(mask&(1<<i)) ++cur; if(cur>best) best=cur;
		}
//		printf("=> %d\n",best);
		ret+=best;
	}
	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}