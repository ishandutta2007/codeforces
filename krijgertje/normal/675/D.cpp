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

int n;
int x[MAXN];


set<pair<int,int> > have;

int ret[MAXN-1];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	have.clear();
	have.insert(MP(x[0],1));
	REP(i,n-1) {
		set<pair<int,int> >::iterator nxt=have.lower_bound(MP(x[i+1],0));

		if(nxt==have.begin()) ret[i]=nxt->first;
		else {
			set<pair<int,int> >::iterator prv=nxt; --prv;
			if(nxt==have.end()) ret[i]=prv->first;
			else ret[i]=prv->second<nxt->second?nxt->first:prv->first;
		}
		have.insert(MP(x[i+1],i+2));
	}
	REP(i,n-1) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}