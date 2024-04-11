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

const int MAXN=100;
const int MAXID=1000000;

int n;
char type[MAXN]; int id[MAXN];
bool have[MAXID+1]; int nhave;



void run() {
	scanf("%d",&n);
	REP(i,n) scanf(" %c%d",&type[i],&id[i]);

	memset(have,false,sizeof(have)); nhave=0;
	for(int i=n-1;i>=0;--i) {
		if(type[i]=='-') { assert(!have[id[i]]); have[id[i]]=true; ++nhave; }
		if(type[i]=='+'&&have[id[i]]) { have[id[i]]=false; --nhave; }
	}
	int ret=nhave;
	REP(i,n) {
		if(type[i]=='+') { assert(!have[id[i]]); have[id[i]]=true; ++nhave; }
		if(type[i]=='-') { assert(have[id[i]]); have[id[i]]=false; --nhave; }
		if(nhave>ret) ret=nhave;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}