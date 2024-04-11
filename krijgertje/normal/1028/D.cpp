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

const int MAXN=363304;
const int MOD=1000000007;

int n;
int kind[MAXN],val[MAXN];

set<int> lo,mi,hi;

void run() {
	scanf("%d",&n); REP(i,n) { char buff[100]; scanf("%s%d",buff,&val[i]); kind[i]=strcmp(buff,"ADD")==0?0:1; }

	lo.clear(),mi.clear(),hi.clear(); int ret=1;
	REP(i,n) {
		if(kind[i]==0) {
			if(SZ(lo)!=0&&val[i]<=*lo.rbegin()) lo.insert(val[i]);
			else if(SZ(hi)!=0&&val[i]>=*hi.begin()) hi.insert(val[i]);
			else mi.insert(val[i]);
		}
		if(kind[i]==1) {
			if(SZ(lo)!=0&&val[i]<*lo.rbegin()) { ret=0; break; }
			if(SZ(hi)!=0&&val[i]>*hi.begin()) { ret=0; break; }
			if(SZ(lo)!=0&&val[i]==*lo.rbegin()) { lo.erase(prev(lo.end())); for(auto it=mi.begin();it!=mi.end();++it) hi.insert(*it); mi.clear(); continue; }
			if(SZ(hi)!=0&&val[i]==*hi.begin()) { hi.erase(hi.begin()); for(auto it=mi.begin();it!=mi.end();++it) lo.insert(*it); mi.clear(); continue; }
			ret=(ll)ret*2%MOD;
			for(auto it=mi.begin();it!=mi.end();++it) if(*it<val[i]) lo.insert(*it); else if(*it>val[i]) hi.insert(*it);
			mi.clear();
		}
	}
	ret=(ll)ret*(SZ(mi)+1)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}