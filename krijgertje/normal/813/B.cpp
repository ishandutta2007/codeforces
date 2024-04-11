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

ll x,y;
ll l,r;

// x==y?
void run() {
	scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
	if(x>y) swap(x,y);
	vector<ll> xx; for(ll z=1;z<=r;z=(z>=r/x+1?LLONG_MAX:z*x)) xx.PB(z);
	vector<ll> yy; for(ll z=1;z<=r;z=(z>=r/y+1?LLONG_MAX:z*y)) yy.PB(z);
	set<ll> unluckyset;
	REPSZ(i,xx) REPSZ(j,yy) { ll z=xx[i]+yy[j]; if(l<=z&&z<=r) unluckyset.insert(z); }
	unluckyset.insert(l-1); unluckyset.insert(r+1);
	vector<ll> unlucky; for(auto it=unluckyset.begin();it!=unluckyset.end();++it) unlucky.PB(*it);
	//REPSZ(i,unlucky) printf("%lld ",unlucky[i]); puts("");
	//printf("%d %d %d\n",SZ(xx),SZ(yy),SZ(unlucky));
	ll ret=0;
	FORSZ(i,1,unlucky) { ll cur=unlucky[i]-unlucky[i-1]-1; if(cur>ret) ret=cur; }
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}