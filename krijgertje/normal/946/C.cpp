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

const int MAXLEN=100000;

char s[MAXLEN+1]; int n;

vector<int> pos[26];

void run() {
	scanf("%s",s); n=strlen(s);
	REP(i,26) pos[i].clear(); REP(i,n) pos[s[i]-'a'].PB(i); REP(i,26) reverse(pos[i].begin(),pos[i].end());
	REP(i,26) {
		int idx=-1;
		REPE(j,i) if(SZ(pos[j])>0&&(idx==-1||pos[j].back()<idx)) idx=pos[j].back();
		//printf("%d: %d\n",i,idx);
		if(idx==-1) { printf("-1\n"); return; }
		s[idx]='a'+i;
		REP(j,26) while(SZ(pos[j])>0&&pos[j].back()<=idx) pos[j].pop_back();
	}
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}