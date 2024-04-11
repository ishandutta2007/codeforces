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

const int MAXSTUD=1000;

int nstud,nkind;
int a[MAXSTUD];

int solve() {
	sort(a,a+nstud);
	int nsingle=0,npair=0;
	for(int l=0,r=l;l<nstud;l=r) { while(r<nstud&&a[r]==a[l]) ++r; int cnt=r-l; nsingle+=cnt%2; npair+=cnt/2; }
	return 2*npair+(nsingle+1)/2;
}

void run() {
	scanf("%d%d",&nstud,&nkind);
	REP(i,nstud) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}