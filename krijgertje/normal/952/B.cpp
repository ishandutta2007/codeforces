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

const char ans[2][10][20]={{"no","great!","don't think so","not bad","cool","don't touch me!","no","no","no","no"},{"no","don't even","are you serious?","worse","terrible","go die in a hole","no way","no way","no","no"}};
map<string,int> anscnt[2];




void init() {
	REP(i,2) anscnt[i].clear();
	REP(i,2) REP(j,10) ++anscnt[i][ans[i][j]];
}

string have[10];
map<string,int> havecnt;

bool solve(int nq,int &kind) {
	havecnt.clear(); REP(i,nq) ++havecnt[have[i]];
	bool can[2]; can[0]=can[1]=true;
	for(auto it=havecnt.begin();it!=havecnt.end();++it) {
		string s=it->first; int cnt=it->second;
		if(anscnt[0][s]==0&&anscnt[1][s]==0) continue;
		REP(i,2) {
			//printf("%d: %s: %d vs %d\n",i,s.c_str(),cnt,anscnt[i][s]);
			if(anscnt[i][s]<cnt) can[i]=false;
		}
	}
	REP(i,2) if(can[i]&&!can[1-i]) { kind=i; return true; }
	return false;
}


void run() {
	init();
	REP(i,10) {
		printf("%d\n",i); fflush(stdout);
		getline(cin, have[i]);
		int kind; if(solve(i+1,kind)) { printf("%s\n",kind==0?"normal":"grumpy"); fflush(stdout); return; }
	}
	printf("???\n");
}

int main() {
	run();
	return 0;
}