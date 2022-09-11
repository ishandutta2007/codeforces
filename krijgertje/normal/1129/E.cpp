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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=500;

int n;
vector<pair<int,int>> edges;


int sz[MAXN];
pair<int,int> o[MAXN];

int query(vector<int> a,vector<int> b,int c) {
	printf("%d\n",SZ(a)); REPSZ(i,a) { if(i!=0) printf(" "); printf("%d",a[i]+1); } puts("");
	printf("%d\n",SZ(b)); REPSZ(i,b) { if(i!=0) printf(" "); printf("%d",b[i]+1); } puts("");
	printf("%d\n",c+1); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}



void solve() {
	sz[0]=n; FOR(i,1,n) { vector<int> a,b; a.PB(0); FOR(j,1,n) b.PB(j); sz[i]=query(a,b,i); }
	
	REP(i,n) o[i]=MP(sz[i],i); sort(o,o+n);
	vector<int> subtreeroots; edges.clear();
	REP(i,n) {
		int at=o[i].second;
		if(sz[at]>=2) {
			while(SZ(subtreeroots)>0) {
				{ vector<int> a,b; a.PB(0); b=subtreeroots; int rem=query(a,b,at); if(rem==0) break; }
				int lo=0,hi=SZ(subtreeroots);
				while(lo+1<hi) {
					int mi=lo+(hi-lo)/2; vector<int> a,b; a.PB(0); REP(k,mi) b.PB(subtreeroots[k]); int cur=query(a,b,at);
					if(cur==0) lo=mi; else hi=mi;
				}
				int idx=hi-1; int to=subtreeroots[idx];
				edges.PB(MP(at,to)); subtreeroots.erase(subtreeroots.begin()+idx);
			}
		}
		subtreeroots.PB(at);
	}
}

void run() {
	scanf("%d",&n);
	solve();
	printf("ANSWER\n"); REPSZ(i,edges) printf("%d %d\n",edges[i].first+1,edges[i].second+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}