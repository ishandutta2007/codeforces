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
const int MOD=998244353;

int na,nb;
char a[MAXN+1];
char b[MAXN+1];

int sum[MAXN+1];


int solve() {
	reverse(a,a+na);
	reverse(b,b+nb);
	sum[0]=0; REP(i,nb) sum[i+1]=sum[i]+(b[i]-'0');
	int ret=0,cur=1;
	REP(i,na) {
		if(i<=nb&&a[i]=='1') {
			int mlt=sum[nb]-sum[i];
			//printf("%d: %d times %d\n",i,mlt,cur);
			ret=(ret+(ll)cur*mlt)%MOD;
		}
		cur=(ll)2*cur%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&na,&nb);
	scanf("%s",a);
	scanf("%s",b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}