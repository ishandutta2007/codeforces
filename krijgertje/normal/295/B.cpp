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
	vector<vector<int> > a(n,vector<int>(n)); REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
	vector<int> x(n); REP(i,n) { scanf("%d",&x[i]); --x[i]; }
	
	vector<vector<int> > d=a;
	vector<ll> ans(n,0);
	vector<bool> dead(n,true);
	REP(kk,n) {
		int k=x[n-kk-1]; dead[k]=false; REP(i,n) REP(j,n) if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
		REP(i,n) if(!dead[i]) REP(j,n) if(!dead[j]) ans[n-kk-1]+=d[i][j];
	}
	REP(i,n) { if(i!=0) cout<<" "; cout<<ans[i]; } cout<<endl;
}


int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}