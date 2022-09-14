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

const int MAXN=50;

int n;
int x[MAXN]; char dir[MAXN][10];

bool solve() {
	int at=0;
	REP(i,n) {
		if(strcmp(dir[i],"South")==0) {
			if(at+x[i]>20000) return false;
			at+=x[i];
		} else if(strcmp(dir[i],"North")==0) {
			if(at-x[i]<0) return false;
			at-=x[i];
		} else {
			if(at==0||at==20000) return false;
		}
	}
	return at==0;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%s",&x[i],dir[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}