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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,limbat,limacc;
int x[MAXN];

int solve() {
	int havebat=limbat,haveacc=limacc;
	REP(i,n) {
		if(x[i]==0) {
			if(haveacc>0) --haveacc;
			else if(havebat>0) --havebat;
			else return i;
		} else {
			if(haveacc==limacc) --haveacc;
			else if(havebat>0) --havebat,++haveacc;
			else if(haveacc>0) --haveacc;
			else return i;
		}
	}
	return n;
}

void run() {
	scanf("%d%d%d",&n,&limbat,&limacc);
	REP(i,n) scanf("%d",&x[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}