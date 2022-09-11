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

const int MAXN=100000;

int n;
char a[MAXN+1];
char b[MAXN+1];

void run() {
	scanf("%d",&n); scanf("%s%s",a,b);
	int n00=0,n10=0,n01=0,n11=0; REP(i,n) if(b[i]=='1') if(a[i]=='0') ++n01; else ++n11; else if(a[i]=='0') ++n00; else ++n10;

	//printf("n00=%d, n10=%d, n01=%d, n11=%d\n",n00,n10,n01,n11);
	ll ans=(ll)n00*n11+(ll)n10*n01+(ll)n00*n10;
	printf("%lld\n",ans);
}

int main() {
	run();
	return 0;
}