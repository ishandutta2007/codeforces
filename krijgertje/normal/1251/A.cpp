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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXLEN=500;

char s[MAXLEN+1]; int slen;

bool ok[26];
char ans[26+1]; int nans;


void solve() {
	memset(ok,false,sizeof(ok));
	for(int l=0,r=l;l<slen;l=r) {
		while(r<slen&&s[r]==s[l]) ++r;
		if((r-l)%2==1) ok[s[l]-'a']=true;
	}
	nans=0;
	REP(i,26) if(ok[i]) ans[nans++]='a'+i;
	ans[nans]='\0';
}

void run() {
	scanf("%s",s); slen=strlen(s);
	solve();
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}