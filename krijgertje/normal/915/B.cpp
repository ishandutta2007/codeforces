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

int n,pos,l,r;

int solve(int n,int pos,int l,int r) {
	if(l==1&&r==n) return 0;
	int ret=INT_MAX;
	if(l!=1) ret=min(ret,abs(pos-l)+1+solve(n-(l-1),1,1,r-(l-1)));
	if(r!=n) ret=min(ret,abs(pos-r)+1+solve(r,r,l,r));
	return ret;
}

void run() {
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	printf("%d\n",solve(n,pos,l,r));
}

int main() {
	run();
	return 0;
}