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

const int MAXN=1000000;
const int INF=2*MAXN;
const int UP=0;
const int DN=1;
const int LT=2;
const int RT=3;

int n;
int a[MAXN];
int ansh,answ,ansx,ansy;

int freq[MAXN+1];

bool solvefixed(vector<int> p) {
	if(p[0]!=UP) return false;
	if(p[1]!=LT&&p[1]!=DN) return false;
	if(p[1]==DN&&p[2]!=LT) return false;
	if(freq[0]!=1) return false;
	vector<int> d(4,INF);
	FORE(i,1,n) {
		int need=0;
		need+=max(0,i-1-max(0,i-(d[UP]+1))-max(0,i-(d[LT]+1)));
		need+=max(0,i-1-max(0,i-(d[UP]+1))-max(0,i-(d[RT]+1)));
		need+=max(0,i-1-max(0,i-(d[DN]+1))-max(0,i-(d[LT]+1)));
		need+=max(0,i-1-max(0,i-(d[DN]+1))-max(0,i-(d[RT]+1)));
		int rem=freq[i]-need;
		if(rem<0||rem>4) return false;
		if(rem<4) { if(d[p[0]]==INF) d[p[0]]=i-1; } else { if(d[p[0]]!=INF) return false; }
		if(rem<3) { if(d[p[1]]==INF) d[p[1]]=i-1; } else { if(d[p[1]]!=INF) return false; }
		if(rem<2) { if(d[p[2]]==INF) d[p[2]]=i-1; } else { if(d[p[2]]!=INF) return false; }
		if(rem<1) { if(d[p[3]]==INF) d[p[3]]=i-1; } else { if(d[p[3]]!=INF) return false; }
	}
	REP(k,4) assert(d[k]!=INF);
	ansx=d[UP],ansy=d[LT],ansh=d[UP]+1+d[DN],answ=d[LT]+1+d[RT];
	return true;
}


bool solve() {
	REPE(i,n) freq[i]=0; REP(i,n) ++freq[a[i]];
	vector<int> p(4); REP(k,4) p[k]=k;
	do {
		if(solvefixed(p)) return true;
	} while(next_permutation(p.begin(),p.end()));
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d %d\n%d %d\n",ansh,answ,ansx+1,ansy+1);
}

int dff[MAXN+1];

void stress() {
	REP(rep,100000) {
		int h=1+rand()%20,w=1+rand()%20,cx=rand()%h,cy=rand()%w;
		n=0; REP(x,h) REP(y,w) a[n++]=abs(x-cx)+abs(y-cy);
		assert(solve());
		printf("%d: %d %d %d %d -> %d %d %d %d\n",rep,h,w,cx,cy,ansh,answ,ansx,ansy);
		assert(h*w==ansh*answ);
		REPE(i,n) dff[i]=0; REP(i,n) { assert(a[i]>=0&&a[i]<=n); ++dff[a[i]]; } REP(x,ansh) REP(y,answ) { int cur=abs(x-ansx)+abs(y-ansy); assert(cur>=0&&cur<=n); --dff[cur]; } REPE(i,n) assert(dff[i]==0);
	}
}

int main() {
	run();
	//stress();
	return 0;
}