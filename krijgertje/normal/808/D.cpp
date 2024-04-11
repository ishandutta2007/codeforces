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
set<ll> seen;

bool solve() {
	REP(ttt,2) {
		seen.clear();
		ll a=0,b=0; REP(i,n) b+=x[i];
		REP(i,n) {
			a+=x[i],b-=x[i]; seen.insert(x[i]);
			if(a==b||a>b&&(a-b)%2==0&&seen.count((a-b)/2)) return true;
		}
		reverse(x,x+n);
	}
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}