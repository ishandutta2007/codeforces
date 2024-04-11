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


int a,b,c,d;

int pos[3];

int solve() {
	pos[0]=a,pos[1]=b,pos[2]=c; sort(pos,pos+3);
	int ab=pos[1]-pos[0],bc=pos[2]-pos[1];
	return max(0,d-ab)+max(0,d-bc);
}

void run() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}