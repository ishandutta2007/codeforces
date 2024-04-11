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

const int MAXSHIP=100000;
const int MAXBASE=100000;

int nship,nbase;
int attack[MAXSHIP];
int defense[MAXBASE],gold[MAXBASE];
ll ans[MAXSHIP];

pair<int,int> oa[MAXSHIP];
pair<int,int> od[MAXBASE];

void solve() {
	REP(i,nship) oa[i]=MP(attack[i],i); sort(oa,oa+nship);
	REP(i,nbase) od[i]=MP(defense[i],i); sort(od,od+nbase);
	int at=0; ll sum=0;
	REP(i,nship) {
		while(at<nbase&&oa[i].first>=od[at].first) sum+=gold[od[at].second],++at;
		ans[oa[i].second]=sum;
	}
}

void run() {
	scanf("%d%d",&nship,&nbase);
	REP(i,nship) scanf("%d",&attack[i]);
	REP(i,nbase) scanf("%d%d",&defense[i],&gold[i]);
	solve();
	REP(i,nship) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}