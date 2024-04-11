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

const int MAXN=100000;

int n,have;
int c[MAXN],w[MAXN];

bool exact[MAXN];

void run() {
	scanf("%d%d",&n,&have);
	REP(i,n) scanf("%d",&c[i]);
	REP(i,n) scanf("%d",&w[i]);

	priority_queue<pair<int,int> > q; ll ret=0;
	REP(i,n) {
		if(c[i]%100==0) { exact[i]=true; continue; }
		int x=c[i]%100,y=(100-x)*w[i];
		have-=x; q.push(MP(-y,i)); exact[i]=true;
		while(have<0) {
			assert(SZ(q)>0);
			int cost=-q.top().first,cur=q.top().second; q.pop();
			have+=100; ret+=cost; exact[cur]=false;
		}
	}
	printf("%lld\n",ret);
	REP(i,n) { int p=c[i]/100,q=c[i]%100; if(exact[i]) printf("%d %d\n",p,q); else printf("%d %d\n",p+1,0); }
}

int main() {
	run();
	return 0;
}