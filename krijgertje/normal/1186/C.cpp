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

const int MAXLEN=1000000;

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;

int solve() {
	int bsum=0; REP(i,blen) bsum+=b[i]-'0';
	int asum=0; REP(i,blen) asum+=a[i]-'0';
	int ret=0;
	FORE(i,blen,alen) {
		if((asum+bsum)%2==0) ++ret;
		if(i!=alen) asum+=a[i]-a[i-blen];
	}
	return ret;
}

void run() {
	scanf("%s",a); alen=strlen(a);
	scanf("%s",b); blen=strlen(b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}