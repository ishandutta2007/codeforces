
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

const int MAXN=200000;
const int MAXBIT=29;

typedef struct RN { int c[2]; RN() { c[0]=c[1]=-1; } } RN;
vector<RN> nodes;
int addnode() { int ret=SZ(nodes); nodes.PB(RN()); return ret; }

int find(int at,int sbit,int val) {
	//printf("find(%d,%d,%d)\n",at,sbit,val);
	int ret=1<<sbit;
	for(int bit=sbit-1;bit>=0;--bit) {
		int z=(val>>bit)&1;
		if(nodes[at].c[z]==-1) ret+=1<<bit,z=1-z;
		assert(nodes[at].c[z]!=-1);
		at=nodes[at].c[z];
	}
	return ret;
}

ll ans;
vector<int> solve(int a,int bit,int val) {
	//printf("solve(%d,%d,%d) [%d,%d]\n",a,bit,val,nodes[a].c[0],nodes[a].c[1]);
	if(nodes[a].c[0]==-1&&nodes[a].c[1]==-1) return vector<int>(1,val);
	if(nodes[a].c[1]==-1) return solve(nodes[a].c[0],bit-1,val);
	if(nodes[a].c[0]==-1) return solve(nodes[a].c[1],bit-1,val+(1<<bit));
	vector<int> subvals[2];
	subvals[0]=solve(nodes[a].c[0],bit-1,val);
	subvals[1]=solve(nodes[a].c[1],bit-1,val+(1<<bit));
	int z=0; if(SZ(subvals[z])<SZ(subvals[1-z])) z=1-z;
	int cur=INT_MAX; REPSZ(i,subvals[1-z]) { int now=find(nodes[a].c[z],bit,subvals[1-z][i]); if(now<cur) cur=now; } ans+=cur;
	vector<int> vals; REPSZ(i,subvals[1]) subvals[0].PB(subvals[1][i]); return subvals[0];
}

int n;
int a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n); n=unique(a,a+n)-a;

	nodes.clear(); int root=addnode();
	REP(i,n) {
		int at=root;
		for(int bit=MAXBIT;bit>=0;--bit) { int x=(a[i]>>bit)&1; if(nodes[at].c[x]==-1) { int y=addnode(); nodes[at].c[x]=y; } at=nodes[at].c[x]; }
	}
	ans=0; solve(root,MAXBIT,0);
	printf("%lld\n",ans);
}

int main() {
	run();
	return 0;
}