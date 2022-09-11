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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=1000000;

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;

bool solve() {
	for(int al=0,ar=al,bl=0,br=bl;al<alen||bl<blen;al=ar,bl=br) {
		while(ar<alen&&a[ar]==a[al]) ++ar;
		while(br<blen&&b[br]==b[bl]) ++br;
		if(a[al]!=b[bl]) return false;
		if(ar-al>br-bl) return false;
	}
	return true;
}

void run() {
	scanf("%s",a); alen=strlen(a);
	scanf("%s",b); blen=strlen(b);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}