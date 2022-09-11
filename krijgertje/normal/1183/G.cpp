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

const int MAXN=200000;
struct Candy { int a,f; };
bool operator<(const Candy &p,const Candy &q) { return p.a<q.a; }

int n;
Candy candy[MAXN];

pair<int,int> b[MAXN]; int nb;

pair<int,int> solve() {
	sort(candy,candy+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&candy[r].a==candy[l].a) ++r; int fsum=0; FOR(i,l,r) fsum+=candy[i].f; b[nb++]=MP(r-l,fsum); }
	sort(b,b+nb); reverse(b,b+nb);
	//printf("b:"); REP(i,nb) printf(" (%d,%d)",b[i].first,b[i].second); puts("");
	int sz=0,val=0; priority_queue<int> pq; int at=0;
	for(int cur=b[0].first;cur>=1;--cur) {
		while(at<nb&&b[at].first>=cur) pq.push(b[at++].second);
		if(SZ(pq)>0) { int cval=pq.top(); pq.pop(); sz+=cur; val+=min(cur,cval); }
	}
	return MP(sz,val);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&candy[i].a,&candy[i].f);
	auto ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run();
	return 0;
}