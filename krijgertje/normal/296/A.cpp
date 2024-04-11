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
	int n; scanf("%d",&n);
	vector<int> a(n); REP(i,n) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int maxcnt=0;
	{ int i=0; while(i<n) { int j=i+1; while(j<n&&a[i]==a[j]) ++j; if(j-i>maxcnt) maxcnt=j-i; i=j; } }
	printf("%s\n",maxcnt>(n+1)/2?"NO":"YES");
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}