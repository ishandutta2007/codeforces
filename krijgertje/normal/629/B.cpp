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

const int MAXN=5000;
const int MAXVAL=366;

int n;
int a[2][MAXVAL+1],b[2][MAXVAL+1];

void run() {
	scanf("%d",&n);
	memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	REP(i,n) { char g; int aa,bb; scanf(" %c%d%d",&g,&aa,&bb); a[g=='M'?0:1][aa-1]++; b[g=='M'?0:1][bb]++; }
	int x=0,y=0,ret=0;
	REPE(i,MAXVAL) {
		x+=a[0][i]-b[0][i]; y+=a[1][i]-b[1][i];
		int cur=2*min(x,y);
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}