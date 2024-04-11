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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXBIT=12;

int nbit;
int a[1<<MAXBIT];
int b[1<<MAXBIT];
int c[1<<MAXBIT];

int cinv[1<<MAXBIT];


bool solve() {
	int sum=0; REP(i,1<<nbit) sum^=a[i]; if(sum!=0) return false;
	REP(i,1<<nbit) b[i]=c[i]=i;
	REP(i,1<<nbit) cinv[c[i]]=i;
	REP(i,(1<<nbit)-1) {
		int at=i;
		while(at<=i) {
			swap(b[at],b[i+1]);
			if(a[at]==(b[at]^c[at])) break;
			int to=cinv[a[at]^b[at]];
			swap(c[at],c[to]); swap(cinv[c[at]],cinv[c[to]]);
			at=to;
		}
	}
	return true;
}

void run() {
	scanf("%d",&nbit);
	REP(i,1<<nbit) scanf("%d",&a[i]);
	if(!solve()) { printf("Fou\n"); return; }
	printf("Shi\n");
	REP(i,1<<nbit) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
	REP(i,1<<nbit) { if(i!=0) printf(" "); printf("%d",c[i]); } puts("");
}

int main() {
	run();
	return 0;
}