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

const int MAXVAL=1000000;

int pmx[MAXVAL+1];

int v1[MAXVAL+1];

int solve(int a) {
	int l=a==pmx[a]?a:a-pmx[a]+1,r=a;
	int ret=v1[l]; FORE(i,l,r) ret=min(ret,v1[i]); return ret;
}

void run() {
	REPE(i,MAXVAL) pmx[i]=-1; FORE(i,2,MAXVAL) if(pmx[i]==-1) for(int j=i;j<=MAXVAL;j+=i) pmx[j]=i;
	FORE(i,3,MAXVAL) v1[i]=i==pmx[i]?i:i-pmx[i]+1;
	int a; scanf("%d",&a); printf("%d\n",solve(a));

}

int main() {
	run();
	return 0;
}