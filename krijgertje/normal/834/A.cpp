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

char s,t; int n;

char cw(char x) { if(x=='v') return '<'; if(x=='<') return '^'; if(x=='^') return '>'; if(x=='>') return 'v'; return '?'; }

void run() {
	scanf(" %c %c%d",&s,&t,&n);
	if(n%2==0) { printf("undefined\n"); return; }
	printf("%s\n",n%4==1&&t==cw(s)||n%4==3&&s==cw(t)?"cw":"ccw");
}

int main() {
	run();
	return 0;
}