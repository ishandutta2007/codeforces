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

int h1,a1,c1;
int h2,a2;

void run() {
	scanf("%d%d%d",&h1,&a1,&c1); scanf("%d%d",&h2,&a2);
	int hits=(h2+a1-1)/a1;
	// 	(c1-a2)*potions>(hits-1)*a2-h1
	int rhs=(hits-1)*a2-h1;
	int potions=rhs<0?0:((hits-1)*a2-h1)/(c1-a2)+1;
	printf("%d\n",potions+hits);
	REP(i,potions) printf("HEAL\n");
	REP(i,hits) printf("STRIKE\n");
}

int main() {
	run();
	return 0;
}