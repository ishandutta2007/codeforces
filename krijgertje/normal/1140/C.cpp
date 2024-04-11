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

const int MAXSONG=300000;
struct Song { int len,beauty; };
bool operator<(const Song &a,const Song &b) { return a.beauty<b.beauty; }

int n,lim;
Song song[MAXSONG];

ll solve() {
	sort(song,song+n);
	multiset<int> bestlen; ll bestsumlen=0;
	ll ret=0;
	for(int i=n-1;i>=0;--i) {
		ll cur=(bestsumlen+song[i].len)*song[i].beauty;
		//printf("SZ=%d -> (%lld+%d)*%d\n",SZ(bestlen),bestsumlen,song[i].len,song[i].beauty);
		ret=max(ret,cur);
		bestlen.insert(song[i].len); bestsumlen+=song[i].len;
		while(SZ(bestlen)>=lim) { int mnlen=*bestlen.begin(); bestlen.erase(bestlen.begin()); bestsumlen-=mnlen; }
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d%d",&song[i].len,&song[i].beauty);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}