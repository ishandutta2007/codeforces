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

typedef struct {
	int n;
	int arr[100000]; // arr[0]=id of max element
	int val[100000]; // id -> val
	int pos[100000]; // id -> pos in arr

	void makeswap(int a,int b) {
		swap(arr[a],arr[b]);
		swap(pos[arr[a]],pos[arr[b]]);
	}
	int up(int at) {
		while(at!=0) {
			int to=(at-1)/2;
			if(val[arr[at]]<=val[arr[to]]) return at;
			makeswap(at,to);
			at=to;
		}
		return at;
	}
	int down(int at) {
		while(true) {
			int to=at;
			if(2*at+1<n&&val[arr[2*at+1]]>val[arr[to]]) to=2*at+1;
			if(2*at+2<n&&val[arr[2*at+2]]>val[arr[to]]) to=2*at+2;
			if(to==at) return at;
			makeswap(at,to);
			at=to;
		}
	}
	void add(int id) {
		arr[n]=id; pos[id]=n; n++;
		up(pos[id]);
	}
	void rem(int id) {
		int at=pos[id];
		if(at!=n-1) makeswap(at,n-1);
		pos[id]=-1; arr[n-1]=-1; --n;
		if(at!=n) { at=up(at); at=down(at); }
	}
} H;

const int MOD=1000000009;
typedef struct B { int x,y,idx; } B;
bool operator<(const B &p,const B &q) {
	if(p.y!=q.y) return p.y<q.y;
	if(p.x!=q.x) return p.x<q.x;
	return p.idx<q.idx;
}

int n;
B b[100000];
int nbelow[100000];
int below[100000][3];
int nabove[100000];
int above[100000][3];

bool dead[100000];
int curbelow[100000];
int nrest[100000];


H mx,mn;


void kill(int at) {
	dead[at]=true; mx.rem(at); mn.rem(at);
	if(curbelow[at]==1) REP(i,nbelow[at]) if(!dead[below[at][i]]) if(--nrest[below[at][i]]==0) { mx.add(below[at][i]); mn.add(below[at][i]); }
	REP(i,nabove[at]) if(!dead[above[at][i]]) {
		int to=above[at][i];
		--curbelow[to];
		assert(curbelow[to]>0);
		if(curbelow[to]==1) REP(j,nbelow[to]) if(!dead[below[to][j]]) if(nrest[below[to][j]]++==0) { mx.rem(below[to][j]); mn.rem(below[to][j]); }
	}
}

void printstate() {
	printf("state:"); REP(i,n) if(!dead[i]&&nrest[i]==0) printf(" %d",i); puts("");
	printf("mx:"); REP(i,mx.n) printf(" %d",mx.arr[i]); puts("");
	printf("mn:"); REP(i,mn.n) printf(" %d",mn.arr[i]); puts("");
}


void run() {
	scanf("%d",&n);
	REP(i,n) { b[i].idx=i; scanf("%d%d",&b[i].x,&b[i].y); }
	sort(b,b+n);

	{
		REP(i,n) nbelow[i]=0;
		int at=0,to=0;
		while(to<n) {
			if(b[to].y<=b[at].y) { ++to; continue; }
			if(b[to].y>b[at].y+1) { ++at; continue; }
			if(b[at].x<b[to].x-1) { ++at; continue; }
			if(b[at].x>b[to].x+1) { ++to; continue; }
			if(b[at].x==b[to].x+1) { below[to][nbelow[to]++]=at; ++to; continue; }
			if(b[at].x==b[to].x-1) { below[to][nbelow[to]++]=at; ++at; continue; }
			below[to][nbelow[to]++]=at;
			if(at+1<n&&b[at+1].y==b[at].y&&b[at+1].x==b[at].x+1) below[to][nbelow[to]++]=at+1;
			++to;
		}
		REP(i,n) nabove[i]=0;
		REP(i,n) REP(j,nbelow[i]) above[below[i][j]][nabove[below[i][j]]++]=i;
	}
	//REP(i,n) { printf("%d: [%d] (%d,%d) ->",i,b[i].idx,b[i].x,b[i].y); REP(j,nbelow[i]) printf(" %d",below[i][j]); puts(""); }

	REP(i,n) dead[i]=false,nrest[i]=0,curbelow[i]=nbelow[i];
	REP(i,n) if(nbelow[i]==1) ++nrest[below[i][0]];

	mx.n=mn.n=0;
	REP(i,n) mx.val[i]=b[i].idx,mn.val[i]=-b[i].idx;
	REP(i,n) if(nrest[i]==0) { mx.add(i); mn.add(i); }

	int ret=0;
	while(true) {
		if(mx.n==0) break;
		int curmx=mx.arr[0];
		kill(curmx); ret=((ll)ret*n+b[curmx].idx)%MOD; //printf("%d\n",curmx); printstate();
		if(mn.n==0) break;
		int curmn=mn.arr[0];
		kill(curmn); ret=((ll)ret*n+b[curmn].idx)%MOD; //printf("%d\n",curmn); printstate();
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}