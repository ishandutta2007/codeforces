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

const int MAXN=2000;



int n,mxa,mxb;
double p[4][MAXN];

int use[MAXN],cnt[MAXN];
priority_queue<pair<double,int> > q[4][4];
double ret,cur;

void setuse(int idx,int w) {
	--cnt[use[idx]]; use[idx]=w; ++cnt[use[idx]];
	REP(x,4) q[w][x].push(MP(p[x][idx]-p[w][idx],idx));
}

void add(int z) {
	double best=-10; int idx1=-1,idx2=-1,idx3=-1;
	REP(y,4) if(y!=z) {
		while(SZ(q[y][z])>0&&use[q[y][z].top().second]!=y) q[y][z].pop();
		if(SZ(q[y][z])==0) continue;
		if(y==0) { double now=q[y][z].top().first; if(now>best) best=now,idx1=q[y][z].top().second,idx2=-1,idx3=-1; }
		if(y!=0) REP(x,4) if(x!=y&&x!=z) {
			while(SZ(q[x][y])>0&&use[q[x][y].top().second]!=x) q[x][y].pop();
			if(SZ(q[x][y])==0) continue;
			if(x==0) { double now=q[y][z].top().first+q[x][y].top().first; if(now>best) best=now,idx1=q[y][z].top().second,idx2=q[x][y].top().second,idx3=-1; }
			if(x!=0) REP(w,4) if(w!=x&&w!=y&&w!=z) {
				while(SZ(q[w][x])>0&&use[q[w][x].top().second]!=w) w[q][x].pop();
				if(SZ(q[w][x])==0) continue;
				if(w==0) { double now=q[y][z].top().first+q[x][y].top().first+q[w][x].top().first; if(now>best) best=now,idx1=q[y][z].top().second,idx2=q[x][y].top().second,idx3=q[w][x].top().second; }
			}
		}
	}
	assert(idx1!=-1);
	if(idx3!=-1) setuse(idx3,use[idx2]);
	if(idx2!=-1) setuse(idx2,use[idx1]);
	if(idx1!=-1) setuse(idx1,z);
	cur+=best; if(cur>ret) ret=cur;
	//printf("adding %d: %d %d %d -> %lf\n",z,idx1,idx2,idx3,cur);
}
void rem(int w) {
	double best=-10; int idx1=-1,idx2=-1,idx3=-1;
	REP(x,4) if(x!=w) {
		while(SZ(q[w][x])>0&&use[q[w][x].top().second]!=w) q[w][x].pop();
		if(SZ(q[w][x])==0) continue;
		if(x==0) { double now=q[w][x].top().first; if(now>best) best=now,idx1=q[w][x].top().second,idx2=-1,idx3=-1; }
		if(x!=0) REP(y,4) if(y!=w&&y!=x) {
			while(SZ(q[x][y])>0&&use[q[x][y].top().second]!=x) q[x][y].pop();
			if(SZ(q[x][y])==0) continue;
			if(y==0) { double now=q[w][x].top().first+q[x][y].top().first; if(now>best) best=now,idx1=q[w][x].top().second,idx2=q[x][y].top().second,idx3=-1; }
			if(y!=0) REP(z,4) if(z!=w&&z!=x&&z!=y) {
				while(SZ(q[y][z])>0&&use[q[y][z].top().second]!=y) q[y][z].pop();
				if(SZ(q[y][z])==0) continue;
				if(z==0) { double now=q[w][x].top().first+q[x][y].top().first+q[y][z].top().first; if(now>best) best=now,idx1=q[w][x].top().second,idx2=q[x][y].top().second,idx3=q[y][z].top().second; }
			}
		}
	}
	assert(idx1!=-1);
	if(idx1!=-1) setuse(idx1,idx2==-1?0:use[idx2]);
	if(idx2!=-1) setuse(idx2,idx3==-1?0:use[idx3]);
	if(idx3!=-1) setuse(idx3,0);
	cur+=best; if(cur>ret) ret=cur;
	//printf("removing %d: %d %d %d -> %lf\n",w,idx1,idx2,idx3,cur);
}

void run() {
	scanf("%d%d%d",&n,&mxa,&mxb);
	REP(i,n) p[0][i]=0; FORE(w,1,2) REP(i,n) scanf("%lf",&p[w][i]); REP(i,n) p[3][i]=p[1][i]+p[2][i]-p[1][i]*p[2][i];

	REP(w,4) REP(x,3) q[w][x]=priority_queue<pair<double,int> >();
	ret=cur=0;

	REP(i,4) cnt[i]=i==0?n:0;
	REP(i,n) use[i]=0,setuse(i,0);

	int mnc=max(0,mxa+mxb-n),mxc=min(mxa,mxb);
	REP(i,mnc) add(3);
	REP(i,mxa-mnc) add(1);
	REP(i,mxb-mnc) add(2);
	REP(i,mxc-mnc) rem(1),rem(2),add(3);

	printf("%.9lf\n",ret);
}


int main() {
	run();
	return 0;
}