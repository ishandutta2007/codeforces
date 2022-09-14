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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

typedef struct State {
	char cnt[21];
	char top[3];
} State;
inline bool operator<(const State &a,const State &b) {
	return memcmp(&a, &b, sizeof(State)) < 0;
}

int nways[3];
int need[3][16],gain[3][16];
char color[3]={'B','G','R'};
char name[21][4]={"B","G","R","BBB","BBG","BBR","BGB","BGG","BGR","BRB","BRG","BRR","GBG","GBR","GGG","GGR","GRG","GRR","RBR","RGR","RRR"};

void init() {
	memset(nways,0,sizeof(nways));
	REP(i,3) {
		int x=name[i][0]=='B'?0:name[i][0]=='G'?1:2;
		need[x][nways[x]]=i; gain[x][nways[x]]=-1; ++nways[x];
	}
	FOR(i,3,21) REP(j,3) {
		if(j==2&&name[i][0]==name[i][2]) continue;
		int x=name[i][j]=='B'?0:name[i][j]=='G'?1:2;
		int y=name[i][2-j]=='B'?0:name[i][2-j]=='G'?1:2;
		need[x][nways[x]]=i; gain[x][nways[x]]=j==1?-1:y; ++nways[x];
	}
	REP(i,3) assert(nways[i]==16);
}

int encode(char s[3]) {
	FOR(i,3,21) if(s[0]==name[i][0]&&s[1]==name[i][1]&&s[2]==name[i][2]) return i;
	assert(false); return -1;
}


map<State,double> mem;
double go(State &s) {
	map<State,double>::iterator retit=mem.find(s);
	if(retit!=mem.end()) return retit->second;

	char oldtop[3]; int gaintop=-1;
	bool fulltop=true; REP(k,3) if(s.top[k]=='?') fulltop=false;
	if(fulltop) {
		REP(k,3) oldtop[k]=s.top[k];
		gaintop=encode(s.top);
		REP(k,3) s.top[k]='?';
	}

	int nwait=1; double sum=0;
	REP(i,3) {
		int times=i==2?1:2;
		bool any=false; double best=-1;
		REP(j,nways[i]) if(s.cnt[need[i][j]]>0) REP(k,3) {
			if(s.top[k]!='?'||k==2&&s.top[0]=='?') continue;

			s.top[k]=color[i];
			bool swaptop=false; if(k==2&&s.top[0]>s.top[2]) { swaptop=true; swap(s.top[0],s.top[2]); }
			--s.cnt[need[i][j]];
			if(gain[i][j]!=-1) ++s.cnt[gain[i][j]];
			if(gaintop!=-1) ++s.cnt[gaintop];

			double cur=go(s);
			if(!any||cur<best) any=true,best=cur;

			if(gaintop!=-1) --s.cnt[gaintop];
			if(gain[i][j]!=-1) --s.cnt[gain[i][j]];
			++s.cnt[need[i][j]];
			if(swaptop) swap(s.top[0],s.top[2]);
			s.top[k]='?';
		}
		if(!any) nwait+=times; else sum+=times*best;
	}

	if(fulltop) {
		REP(k,3) s.top[k]=oldtop[k];
	}

	double ret=nwait==6?0.0:(6+sum)/(6-nwait);
	return mem[s]=ret;
}

char sinit[6][3];

void run() {
	int n; scanf("%d",&n);
	REP(i,n) REP(j,3) scanf(" %c",&sinit[i][j]);
	REP(i,n) if(sinit[i][0]>sinit[i][2]) swap(sinit[i][0],sinit[i][2]);
	State init;
	REP(j,21) init.cnt[j]=0;
	REP(i,n-1) init.cnt[encode(sinit[i])]++;
	REP(k,3) init.top[k]=sinit[n-1][k];
	double ret=go(init);
	//printf("%d\n",SZ(mem));
	printf("%.9lf\n",ret);
}

int main() {
	init();
	run();
	return 0;
}