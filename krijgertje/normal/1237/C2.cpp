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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=50000;
struct P { int x,y,z; int id; };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; if(a.y!=b.y) return a.y<b.y; if(a.z!=b.z) return a.z<b.z; return a.id<b.id; }

int n;
P p[MAXN];
vector<pair<int,int>> ans;

P a[MAXN]; int na;
bool used[MAXN];

void solve() {
	ans.clear();
	REP(i,n) a[i]=p[i]; na=n; sort(a,a+na);
	
	REP(i,na) used[i]=false;
	REP(i,na-1) if(!used[i]&&!used[i+1]&&a[i].x==a[i+1].x&&a[i].y==a[i+1].y) {
		used[i]=used[i+1]=true;
		ans.PB(MP(a[i].id,a[i+1].id));
	}
	{ int tmp=0; REP(i,na) if(!used[i]) a[tmp++]=a[i]; na=tmp; }

	REP(i,na) used[i]=false;
	REP(i,na-1) if(!used[i]&&!used[i+1]&&a[i].x==a[i+1].x) {
		used[i]=used[i+1]=true;
		ans.PB(MP(a[i].id,a[i+1].id));
	}
	{ int tmp=0; REP(i,na) if(!used[i]) a[tmp++]=a[i]; na=tmp; }

	REP(i,na) used[i]=false;
	REP(i,na-1) if(!used[i]&&!used[i+1]) {
		used[i]=used[i+1]=true;
		ans.PB(MP(a[i].id,a[i+1].id));
	}
	{ int tmp=0; REP(i,na) if(!used[i]) a[tmp++]=a[i]; na=tmp; }
	
	assert(na==0);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),p[i].id=i;
	solve();
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}