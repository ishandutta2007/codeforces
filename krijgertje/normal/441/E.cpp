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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int x,k,p;
double pmult;

bool been[201][201];
double mem[201][201];

double go(int steps,int add) {
	if(been[steps][add]) return mem[steps][add];
	
	double ret=0;
	if(steps==0) {
		int xx=x+add;
		while(xx%2==0) xx/=2,++ret;
	} else {
		if(add%2==0) ret+=pmult*(1+go(steps-1,add/2));
		ret+=(1-pmult)*go(steps-1,add+1);
	}

	been[steps][add]=true;
	return mem[steps][add]=ret;
}

void run() {
	scanf("%d%d%d",&x,&k,&p); pmult=0.01*p;
	memset(been,false,sizeof(been));
	double ret=go(k,0);
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}