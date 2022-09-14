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

const int MAXLEN=200000;

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;
int bsum[MAXLEN+1];

void run() {
	scanf("%s%s",a,b); alen=strlen(a),blen=strlen(b);
	bsum[0]=0; REP(i,blen) bsum[i+1]=bsum[i]+(b[i]=='1'?1:0);
	ll ret=0;
	REP(i,alen) {
		//b[i..i+blen-alen]
		int cur=bsum[i+blen-alen+1]-bsum[i];
		if(a[i]=='0') ret+=cur; else ret+=blen-alen+1-cur;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}