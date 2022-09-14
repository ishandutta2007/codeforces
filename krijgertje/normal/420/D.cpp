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

int cnt[1<<22];

void update(int x,int by) {
	x+=1<<21;
	REP(i,22) cnt[x>>i]+=by;
}

int find(int y) {
	int x=1;
	assert(y<=cnt[x]);
	REP(i,21) if(y<=cnt[x<<1]) x<<=1; else { y-=cnt[x<<1]; x<<=1; ++x; }
	assert(y==1&&cnt[x]==1);
	return x-(1<<21);
}

int ncups,nops;
int id[1000000];
int ret[1000000];
bool seen[1000000];

void run() {
	scanf("%d%d",&ncups,&nops);
	bool ok=true; memset(seen,false,sizeof(seen)); memset(ret,-1,sizeof(ret));
	memset(cnt,0,sizeof(cnt));
	REP(i,ncups) update(nops+i,+1);
//	REP(i,1<<22) if(cnt[i]>0) printf("%x: %d\n",i,cnt[i]);
	REP(i,nops) {
		int x,y; scanf("%d%d",&x,&y);
		int from=find(y),to=nops-i-1;
		//printf("%d to %d\n",from,to);
		update(from,-1);
		update(to,+1);
		if(from>=nops) {
			if(!seen[x-1]) { ret[from-nops]=x; seen[x-1]=true; }
			else ok=false;
		} else {
			if(id[from]!=x) ok=false;
		}
		id[to]=x;
	}
	if(!ok) { printf("-1\n"); return; }
	int at=0; REP(i,ncups) if(ret[i]==-1) { while(at<ncups&&seen[at]) ++at; ret[i]=at+1; seen[at]=true; }
	REP(i,ncups) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}