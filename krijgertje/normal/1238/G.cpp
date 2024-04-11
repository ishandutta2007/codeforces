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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXZ=500000;
struct Z { int t,lim,cost; };
bool operator<(const Z &a,const Z &b) { return a.t<b.t; }

int nz,tmax,cap,shave;
Z z[MAXZ];

multiset<pair<int,int>> avail; ll sumavail;

ll solve() {
	sort(z,z+nz);
	int t=0;
	avail.clear(); sumavail=0;
	avail.insert(MP(0,shave)),sumavail+=shave;
	int at=0;
	ll ret=0;
	while(t<tmax) {
		while(at<nz&&z[at].t==t) {
			Z cur=z[at++];
			avail.insert(MP(cur.cost,cur.lim)),sumavail+=cur.lim;
			while(sumavail>cap) {
				assert(SZ(avail)>0);
				pair<int,int> cur=*prev(avail.end()); avail.erase(prev(avail.end())),sumavail-=cur.second;
				cur.second=max(0LL,cap-sumavail);
				if(cur.second>0) avail.insert(cur),sumavail+=cur.second;
			}
		}
		int nt=tmax; if(at<nz) nt=min(nt,z[at].t);
		int dt=nt-t;
		while(dt>0) {
			if(SZ(avail)==0) return -1;
			pair<int,int> cur=*avail.begin(); avail.erase(avail.begin()),sumavail-=cur.second;
			int use=min(dt,cur.second);
			ret+=(ll)use*cur.first;
			cur.second-=use; dt-=use;
			if(cur.second>0) avail.insert(cur),sumavail+=cur.second;
		}
		t=nt;
	}
	return ret;
}


void run() {
	scanf("%d%d%d%d",&nz,&tmax,&cap,&shave);
	REP(i,nz) scanf("%d%d%d",&z[i].t,&z[i].lim,&z[i].cost);
	printf("%lld\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}