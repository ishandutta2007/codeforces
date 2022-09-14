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
typedef struct S { int l,r,idx; } S;
bool operator<(const S &a,const S &b) { if(a.l!=b.l) return a.l>b.l; if(a.r!=b.r) return a.r<b.r; return a.idx<b.idx; }

int n;
S s[MAXN];
int x[2*MAXN],nx;
int ret[MAXN];

int bt[2*MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bt[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=nx) { bt[idx]+=by; idx+=idx&-idx; } }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&s[i].l,&s[i].r),s[i].idx=i;
	nx=0; REP(i,n) x[nx++]=s[i].l,x[nx++]=s[i].r; sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,n) s[i].l=lower_bound(x,x+nx,s[i].l)-x,s[i].r=lower_bound(x,x+nx,s[i].r)-x;
	//REP(i,n) printf("%d %d [%d %d]\n",s[i].l,s[i].r,x[s[i].l],x[s[i].r]);

	sort(s,s+n); memset(bt,0,sizeof(bt));
	REP(i,n) {
		ret[s[i].idx]=bget(s[i].r);
		bmod(s[i].r,+1);
	}
	REP(i,n) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}