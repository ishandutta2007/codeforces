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

const int MAXHSUM=10000;
const int MAXN=10000;


int n,lscore,rscore;
int bh[MAXN],bkind[MAXN];

map<int,int> acnt,bcnt;

int can[MAXHSUM+1]; int mxcan;

int bcur[MAXN],nbcur;
int curscore[MAXHSUM+1];

void update(int h,int cost) {
	//printf("update(%d,%d)\n",h,cost);
	for(int i=mxcan;i>=0;--i) if(can[i]!=INT_MAX) can[i+h]=min(can[i+h],can[i]+cost);
	mxcan+=h;
}

void run() {
	scanf("%d%d%d",&n,&lscore,&rscore); REP(i,n) scanf("%d",&bh[i]); REP(i,n) scanf("%d",&bkind[i]);
	
	REP(i,n) if(bkind[i]==0) acnt[bh[i]]++; else if(bkind[i]==1) bcnt[bh[i]]++;

	can[0]=0; FORE(i,1,MAXHSUM) can[i]=INT_MAX; mxcan=0;
	for(auto it=acnt.begin();it!=acnt.end();++it) {
		int h=it->first,cnt=it->second;
		while(cnt>0) { if(cnt&1) update(h,0); cnt/=2; h*=2; }
	}
	
	int ret=0; int bskip=0;
	for(auto it=bcnt.rbegin();it!=bcnt.rend();++it) {
		int h=it->first,cnt=it->second;

		nbcur=0; auto it2=it; ++it2; while(it2!=bcnt.rend()) { REP(i,it2->second) bcur[nbcur++]=it2->first; ++it2; }
		//printf("bcur:"); REP(i,nbcur) printf(" %d",bcur[i]); puts("");
		memset(curscore,0,sizeof(curscore));
		int cursum=0; REP(i,nbcur) { curscore[cursum]=i+1; cursum+=bcur[i]; }
		FORE(i,1,MAXHSUM) curscore[i]=max(curscore[i],curscore[i-1]);

		REPE(i,MAXHSUM) if(can[i]!=INT_MAX) {
			int need=i>=lscore?0:(lscore-i+h-1)/h;
			if(need>cnt) continue;
			int rem=cnt-need;
			int cl=i+need*h;
			if(cl>rscore) continue;
			int have=rscore-cl;
			int cur=curscore[have];
			if(have>=cursum) {
				int haverem=have-cursum;
				int nextra=min(rem,1+haverem/h);
				cur+=nextra;
				if(haverem>=nextra*h&&can[i]<bskip) ++cur;
			}
			ret=max(ret,cur);
		}

		bskip+=cnt;
		int t=1; while(cnt>0) { if(cnt&1) update(h,t); cnt/=2; h*=2; t*=2; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}