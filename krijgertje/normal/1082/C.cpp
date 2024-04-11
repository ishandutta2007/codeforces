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

const int MAXCAND=100000;
const int MAXSUB=100000;

int ncand,nsub;
int sub[MAXCAND],score[MAXCAND];

vector<ll> bysub[MAXSUB];
pair<int,int> bycnt[MAXSUB];

ll solve() {
	REP(i,nsub) bysub[i].clear();
	REP(i,ncand) bysub[sub[i]].PB(score[i]);
	REP(i,nsub) {
		sort(bysub[i].rbegin(),bysub[i].rend());
		FORSZ(j,1,bysub[i]) bysub[i][j]+=bysub[i][j-1];
	}
	REP(i,nsub) bycnt[i]=MP(SZ(bysub[i]),i);
	sort(bycnt,bycnt+nsub); reverse(bycnt,bycnt+nsub);
	ll ret=0;
	FORE(cnt,1,bycnt[0].first) {
		ll cur=0;
		REP(i,nsub) {
			if(bycnt[i].first<cnt) break;
			int idx=bycnt[i].second;
			if(bysub[idx][cnt-1]<=0) continue;
			cur+=bysub[idx][cnt-1];
		}
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d",&ncand,&nsub);
	REP(i,ncand) scanf("%d%d",&sub[i],&score[i]),--sub[i];
	printf("%lld\n",solve());

}

int main() {
	run();
	return 0;
}