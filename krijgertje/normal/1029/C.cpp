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

const int MAXN=300000;

int n;
int l[MAXN],r[MAXN];

int lpref[MAXN+1],rpref[MAXN+1]; // prefix [0..i)
int lsuff[MAXN+1],rsuff[MAXN+1]; // [i..n)


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);

	lpref[0]=INT_MIN; REP(i,n) lpref[i+1]=max(lpref[i],l[i]);
	rpref[0]=INT_MAX; REP(i,n) rpref[i+1]=min(rpref[i],r[i]);
	lsuff[n]=INT_MIN; for(int i=n-1;i>=0;--i) lsuff[i]=max(lsuff[i+1],l[i]);
	rsuff[n]=INT_MAX; for(int i=n-1;i>=0;--i) rsuff[i]=min(rsuff[i+1],r[i]);

	int ret=0;
	REP(i,n) {
		int cl=max(lpref[i],lsuff[i+1]),cr=min(rpref[i],rsuff[i+1]);
		if(cl<=cr) ret=max(ret,cr-cl);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}