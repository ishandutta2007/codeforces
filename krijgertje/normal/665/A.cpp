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

int da,ta,db,tb,h,m;

void run() {
	scanf("%d%d%d%d%d:%d",&da,&ta,&db,&tb,&h,&m);
	int t=(h*60+m)-(5*60+0);
//#x | x*db+tb>t x*db>=0 x*db<t+ta x*db<19*60
//#x | x>=flr((t-tb+db)/db)  x<=flr((t+ta-1)/db)
	printf("%d\n",(min(t+ta,19*60)-1)/db-max(0,(t-tb+db)/db)+1);

}

int main() {
	run();
	return 0;
}