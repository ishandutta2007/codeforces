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

int n;
double side,period;

void run() {
	scanf("%lf%lf%d",&side,&period,&n);
	int rounds=(int)floor(period/(4*side));
	period-=4*side*rounds;
	double at=0;
	FORE(i,1,n) {
		at+=period;
		while(at>=4*side) at-=4*side;
		double x,y;
		if(at<=side) x=at,y=0;
		else if(at<=2*side) x=side,y=at-side;
		else if(at<=3*side) x=3*side-at,y=side;
		else x=0,y=4*side-at;
		printf("%.9lf %.9lf\n",x,y);
	}
}

int main() {
	run();
	return 0;
}