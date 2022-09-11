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

const int MAXLEN=300000;

char s[MAXLEN+1]; int slen;
char ans[MAXLEN+1]; int anslen;

char odd[MAXLEN+1]; int nodd;
char evn[MAXLEN+1]; int nevn;

void solve() {
	nodd=nevn=0; REP(i,slen) if((s[i]-'0')%2==0) evn[nevn++]=s[i]; else odd[nodd++]=s[i];
	int atodd=0,atevn=0; anslen=0;
	while(atodd<nodd||atevn<nevn) {
		if(atodd<nodd&&(atevn>=nevn||odd[atodd]<evn[atevn])) ans[anslen++]=odd[atodd++]; else ans[anslen++]=evn[atevn++];
	}
	ans[anslen]='\0';
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