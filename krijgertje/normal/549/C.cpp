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

const int MAXN=200000;

int nstart,nkeep,nkill;
int neven,nodd;

void run() {
	scanf("%d%d",&nstart,&nkeep); nkill=nstart-nkeep;
	neven=nodd=0; REP(i,nstart) { int x; scanf("%d",&x); if(x%2==0) ++neven; else ++nodd; }

	// even->D, odd->S, start=S
	if(nkill==0) {
		printf("%s\n",nodd%2==1?"Stannis":"Daenerys");
	} else if(nkill%2==0) {
		printf("%s\n",nkeep%2==1&&nkill/2>=neven?"Stannis":"Daenerys");
	} else {
		printf("%s\n",nkill/2>=nodd||nkeep%2==0&&nkill/2>=neven?"Daenerys":"Stannis");
	}
}


int main() {
	run();
	return 0;
}