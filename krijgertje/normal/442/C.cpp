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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int x[500000];
int prv[500000];
int nxt[500000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	REP(i,n) prv[i]=i-1,nxt[i]=i+1;

	ll ret=0; int at=0; int cnt=n;
	while(nxt[at]!=n) {
		if(prv[at]!=-1&&x[at]<=x[prv[at]]&&x[at]<=x[nxt[at]]) {
			ret+=min(x[prv[at]],x[nxt[at]]);
			nxt[prv[at]]=nxt[at]; prv[nxt[at]]=prv[at]; --cnt; at=prv[at];
		} else {
			at=nxt[at];
		}
	}

	int l=0,r=n-1; at=0;
	while(l!=r) {
		if(x[l]<=x[r]) {
			ret+=(ll)(cnt-2)*(x[l]-at); at=x[l]; --cnt; l=nxt[l];
		} else {
			ret+=(ll)(cnt-2)*(x[r]-at); at=x[r]; --cnt; r=prv[r];
		}
	}

	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}