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

const int MAXN=1000;

int n,l,r;

ll ansmn,ansmx;

void solve() {
	vector<int> ldig; ldig.PB(1); while(SZ(ldig)<l) ldig.PB(ldig.back()*2);
	vector<int> rdig; rdig.PB(1); while(SZ(rdig)<r) rdig.PB(rdig.back()*2);
	ansmn=0; REPSZ(i,ldig) ansmn+=ldig[i]; ansmn+=(ll)(n-SZ(ldig))*1;
	ansmx=0; REPSZ(i,rdig) ansmx+=rdig[i]; ansmx+=(ll)(n-SZ(rdig))*rdig.back();
}

void run() {
	scanf("%d%d%d",&n,&l,&r);
	solve();
	printf("%lld %lld\n",ansmn,ansmx);
}

int main() {
	run();
	return 0;
}