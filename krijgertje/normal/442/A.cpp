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

const char cols[5]={'R', 'G', 'B', 'Y', 'W'};

int n;

void print(ll have) { REP(i,6) { REP(j,6) printf("%c",have&(1LL<<(6*i+j))?'V':'.'); printf(" "); } puts(""); }

const ll basedigmask=(1LL<<0)|(1LL<<6)|(1LL<<12)|(1LL<<18)|(1LL<<24)|(1LL<<30);
#define GETDIG(mask,idx) (((mask)>>(idx))&basedigmask)
#define REMDIG(mask,idx) ((mask)&~(basedigmask<<(idx)))
#define ADDDIG(mask,idx,col) ((mask)|((col)<<(idx)))

int godig(int at,ll have) {
	if(at>=5) { /*print(have);*/ return 0; }
	if((GETDIG(have,at)&GETDIG(have,5))!=0) return 1+godig(at+1,have);
	int ret=min(1+godig(at+1,have),godig(at+1,ADDDIG(REMDIG(have,at),5,GETDIG(have,at))));
	return ret;
}

const ll basecolmask=(1LL<<0)|(1LL<<1)|(1LL<<2)|(1LL<<3)|(1LL<<4)|(1LL<<5);
#define GETCOL(mask,idx) (((mask)>>(6*(idx)))&basecolmask)
#define REMCOL(mask,idx) ((mask)&~(basecolmask<<(6*(idx))))
#define ADDCOL(mask,idx,col) ((mask)|((col)<<(6*(idx))))

int gocol(int at,ll have) {
	if(at>=5) return godig(0,have);
	if((GETCOL(have,at)&GETCOL(have,5))!=0) return 1+gocol(at+1,have);
	int ret=min(1+gocol(at+1,have),gocol(at+1,ADDCOL(REMCOL(have,at),5,GETCOL(have,at))));
	return ret;
}

void run() {
	scanf("%d",&n);
	ll have=0;
	REP(i,n) { char c,d; scanf(" %c %c",&c,&d); REP(j,5) if(cols[j]==c) have|=1LL<<(6*j+d-'1'); }
	int ret=gocol(0,have);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}