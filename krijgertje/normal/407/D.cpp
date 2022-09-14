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

int h,w;
int a[400][400];

int id[400][400],nid;
int id2row[160000],id2col[160000];

int fst[160000],lst[160000],nxt[160000],prv[160000];

int bound[400][400];
void setmax(int &a,int b) { if(b>a) a=b; }

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) { scanf("%d",&a[i][j]); --a[i][j]; }

	nid=0; REP(i,h) REP(j,w) { id[i][j]=nid; id2row[nid]=i; id2col[nid]=j; nid++; }

	int ret=0;
	REP(tr,h) {
		memset(fst,-1,sizeof(fst));
		memset(lst,-1,sizeof(lst));
		memset(bound,0,sizeof(bound));
		REP(c,w) FOR(r,tr,h) {
			int x=a[r][c],cid=id[r][c];
			if(fst[x]==-1) { prv[cid]=-1; nxt[cid]=-1; fst[x]=cid; lst[x]=cid; } else { prv[cid]=lst[x]; nxt[cid]=-1; nxt[prv[cid]]=cid; lst[x]=cid; }
		}
		for(int br=h-1;br>=tr;--br) for(int c=w-1;c>=0;--c) {
			int x=a[br][c],cid=id[br][c];
			if(prv[cid]!=-1) setmax(bound[br][c],id2col[prv[cid]]+1);
			if(nxt[cid]!=-1) setmax(bound[br][id2col[nxt[cid]]],c+1);
			if(prv[cid]==-1) fst[x]=nxt[cid]; else nxt[prv[cid]]=nxt[cid];
			if(nxt[cid]==-1) lst[x]=prv[cid]; else prv[nxt[cid]]=prv[cid];
			//printf("after (%d,%d)=%d:",br,c,x); for(int y=fst[x];y!=-1;y=nxt[y]) printf(" %d",y); puts("");
		}
		FOR(br,tr,h) REP(c,w) {
			if(br>tr) setmax(bound[br][c],bound[br-1][c]);
			if(c>0) setmax(bound[br][c],bound[br][c-1]);
			if(bound[br][c]<=c) {
				int cur=(br-tr+1)*(c-bound[br][c]+1);
				//printf("%d..%d / %d..%d = %d\n",tr,br,bound[br][c],c,cur);
				if(cur>ret) ret=cur;
			}
		}
	}
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}