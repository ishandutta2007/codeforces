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

const int MAXN=500;

int n;
int a[MAXN*MAXN];

map<int,int> cnt;

int ret[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n*n) scanf("%d",&a[i]);
	cnt.clear(); REP(i,n*n) ++cnt[a[i]];

	REP(i,n) {
		map<int,int>::iterator it=cnt.end(); --it;
		while(it->second==0) { cnt.erase(it); it=cnt.end(); --it; }
		ret[i]=it->first;
		cnt[ret[i]]--;
		REP(j,i) cnt[gcd(ret[i],ret[j])]-=2;
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}


int main() {
	run();
	return 0;
}