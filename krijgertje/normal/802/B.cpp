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

const int MAXN=400000;
const int MAXCAP=400000;

int n,cap;
int x[MAXN];

pair<int,int> o[MAXN];
int nxt[MAXN];
set<int> q;

bool have[MAXN];

int removefirst() {
	assert(SZ(q)>0);
	set<int>::iterator it=q.begin(); int ret=*it; q.erase(it); return ret;
}
int removelast() {
	assert(SZ(q)>0);
	set<int>::iterator it=q.end(); --it; int ret=*it; q.erase(it); return ret;
}

void run() {
	scanf("%d%d",&n,&cap); REP(i,n) scanf("%d",&x[i]),--x[i];

	REP(i,n) o[i]=MP(x[i],i); sort(o,o+n); REP(i,n) nxt[o[i].second]=i+1<n&&o[i+1].first==o[i].first?o[i+1].second:-1;
	REP(i,n) have[i]=false;

	//REP(i,n) printf("%d ",nxt[i]); puts("");

	int ret=0,extra=0;
	REP(i,n) {
		if(have[x[i]]) {
			assert(SZ(q)>0);
			int z=removefirst();
			assert(z==i);
		} else if(extra+SZ(q)>=cap) {
			if(extra>0) {
				--extra;
			} else {
				int z=removelast();
				//printf("removing at %d\n",z);
				have[x[z]]=false;
			}
		}
		if(!have[x[i]]) ++ret;
		have[x[i]]=true;
		if(nxt[i]==-1) {
			++extra;
		} else {
			q.insert(nxt[i]);
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}