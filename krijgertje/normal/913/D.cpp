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


int n,have;
int a[MAXN],t[MAXN];

vector<int> idx[MAXN+1];

set<pair<int,int>> cur;
set<pair<int,int>> avail;



void run() {
	scanf("%d%d",&n,&have); REP(i,n) scanf("%d%d",&a[i],&t[i]);

	FORE(i,1,n) idx[i].clear(); REP(i,n) idx[a[i]].PB(i);
	ll tsum=0; cur=set<pair<int,int>>(),avail=set<pair<int,int>>();
	for(int i=n;i>=0;--i) {
		REPSZ(j,idx[i]) avail.insert(MP(t[idx[i][j]],idx[i][j]));
		while(SZ(cur)<i&&SZ(avail)>0) { auto it=avail.begin(); tsum+=it->first; cur.insert(*it); avail.erase(it); }
		while(SZ(cur)>i) { auto it=prev(cur.end()); tsum-=it->first; avail.insert(*it); cur.erase(it); }
		while(SZ(cur)>0&&SZ(avail)>0&&prev(cur.end())->first>avail.begin()->first) { auto it1=prev(cur.end()); auto it2=avail.begin(); tsum+=it2->first-it1->first; cur.insert(*it2); avail.insert(*it1); cur.erase(it1); avail.erase(it2); }
		//printf("%d: ",i); for(auto it=cur.begin();it!=cur.end();++it) printf(" %d",it->second+1); printf(" = %lld\n",tsum);
		if(tsum<=have&&SZ(cur)==i) break;
	}
	printf("%d\n%d\n",SZ(cur),SZ(cur));
	for(auto it=cur.begin();it!=cur.end();++it) { if(it!=cur.begin()) printf(" "); printf("%d",it->second+1); } puts("");
}

int main() {
	run();
	return 0;
}