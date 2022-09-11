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
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
struct P { int x,y; };
bool operator<(const P &a,const P &b) { if(a.y!=b.y) return a.y>b.y; return a.x<b.x; }

int n;
P p[MAXN];
int xx[MAXN],nxx;

void bmod(vector<int> &bit,int idx,int by) { ++idx; while(idx<SZ(bit)) { bit[idx]+=by; idx+=idx&-idx; } }
int bget(const vector<int> &bit,int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
int bget(const vector<int> &bit,int lidx,int ridx) { return bget(bit,ridx)-bget(bit,lidx-1); }

ll solve() {
	nxx=0; REP(i,n) xx[nxx++]=p[i].x; sort(xx,xx+nxx); nxx=unique(xx,xx+nxx)-xx; REP(i,n) p[i].x=lower_bound(xx,xx+nxx,p[i].x)-xx;
	sort(p,p+n);
	ll ret=0;
	vector<bool> have(nxx,false);
	vector<int> bit(nxx+1,0);
	REP(i,n) {
		int nlft=bget(bit,0,p[i].x-1);
		int nrgt=bget(bit,p[i].x+1,i+1<n&&p[i+1].y==p[i].y?p[i+1].x-1:nxx-1);
		ret+=(ll)(nlft+1)*(nrgt+1);
		if(!have[p[i].x]) have[p[i].x]=true,bmod(bit,p[i].x,+1);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}