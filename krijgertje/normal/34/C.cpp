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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;


void run() {
	string s; cin>>s; REPSZ(i,s) if(s[i]==',') s[i]=' ';
	istringstream iss(s); vector<int> x; string ss; while(iss>>ss) x.PB(atoi(ss.c_str()));
	sort(x.begin(),x.end()); x.erase(unique(x.begin(),x.end()),x.end());
	
	bool first=true;
	for(int i=0;i<SZ(x);) {
		int j=i; while(j+1<SZ(x)&&x[j+1]==x[j]+1) ++j;
		if(first) first=false; else printf(",");
		if(i==j) printf("%d",x[i]); else printf("%d-%d",x[i],x[j]);
		i=j+1;
	}
	puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}