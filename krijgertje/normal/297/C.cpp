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


void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> s(n); REP(i,n) scanf("%d",&s[i]);
	vector<pair<int,int> > p(n); REP(i,n) p[i]=MP(s[i],i); sort(p.begin(),p.end());
	vector<int> a(n,-1),b(n,-1);
	int nn=(n+2)/3;
	FOR(i,0,min(nn,n)) { int ind=p[i].second; a[ind]=i; b[ind]=s[ind]-a[ind]; }
	FOR(i,nn,min(2*nn,n)) { int ind=p[i].second; b[ind]=i; a[ind]=s[ind]-b[ind]; }
	FOR(i,2*nn,min(3*nn,n)) { int ind=p[i].second; b[ind]=3*nn-i-1; a[ind]=s[ind]-b[ind]; assert(b[ind]<nn); assert(a[ind]>=nn); }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}