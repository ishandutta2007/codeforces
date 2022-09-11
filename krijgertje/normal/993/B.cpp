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

const int MAXN=12;

int a[MAXN][2],na;
int b[MAXN][2],nb;

vector<int> opt;
vector<int> aopt[MAXN];
vector<int> bopt[MAXN];

void run() {
	scanf("%d%d",&na,&nb); REP(i,na) REP(j,2) scanf("%d",&a[i][j]); REP(i,nb) REP(j,2) scanf("%d",&b[i][j]);
	REP(i,na) REP(j,nb) {
		vector<int> comm;
		REP(ii,2) REP(jj,2) if(a[i][ii]==b[j][jj]) comm.PB(a[i][ii]);
		sort(comm.begin(),comm.end()); comm.erase(unique(comm.begin(),comm.end()),comm.end());
		if(SZ(comm)!=1) continue;
		opt.PB(comm[0]);
		aopt[i].PB(comm[0]);
		bopt[j].PB(comm[0]);
	}
	sort(opt.begin(),opt.end()); opt.erase(unique(opt.begin(),opt.end()),opt.end());
	REP(i,na) { sort(aopt[i].begin(),aopt[i].end()); aopt[i].erase(unique(aopt[i].begin(),aopt[i].end()),aopt[i].end()); }
	REP(i,nb) { sort(bopt[i].begin(),bopt[i].end()); bopt[i].erase(unique(bopt[i].begin(),bopt[i].end()),bopt[i].end()); }
	if(SZ(opt)==1) { printf("%d\n",opt[0]); return; }
	bool ok=true; REP(i,na) if(SZ(aopt[i])>1) ok=false; REP(i,nb) if(SZ(bopt[i])>1) ok=false; printf("%d\n",ok?0:-1);
}

int main() {
	run();
	return 0;
}