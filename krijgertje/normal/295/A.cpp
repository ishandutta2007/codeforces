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

void run(int casenr) {
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> a(n); REP(i,n) scanf("%d",&a[i]);
	vector<int> l(m),r(m),d(m); REP(i,m) { scanf("%d%d%d",&l[i],&r[i],&d[i]); --l[i]; --r[i]; }
	vector<int> x(k),y(k); REP(i,k) { scanf("%d%d",&x[i],&y[i]); --x[i]; --y[i]; }
	
	vector<int> timesop(m+1,0);
	REP(i,k) { ++timesop[x[i]]; --timesop[y[i]+1]; }
	FORE(i,1,m) timesop[i]+=timesop[i-1];
	
	vector<int> firststart(n,-1),nextstart(m,-1);
	vector<int> firstend(n,-1),nextend(m,-1);
	REP(i,m) { nextstart[i]=firststart[l[i]]; firststart[l[i]]=i; }
	REP(i,m) { nextend[i]=firstend[r[i]]; firstend[r[i]]=i; }
	
	
	vector<ll> ret(n,0);
	ll add=0; int at1=0,at2=0;
	REP(i,n) {
		for(int x=firststart[i];x!=-1;x=nextstart[x]) add+=(ll)d[x]*timesop[x];
		ret[i]=a[i]+add;
		for(int x=firstend[i];x!=-1;x=nextend[x]) add-=(ll)d[x]*timesop[x];
	}
	REP(i,n) { if(i!=0) cout<<" "; cout<<ret[i]; } cout<<endl;	
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}