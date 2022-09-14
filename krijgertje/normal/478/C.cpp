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

int r,g,b;

void run() {
	scanf("%d%d%d",&r,&g,&b);
	int ret=0;
	while(true) {
		if(g<b) swap(g,b); if(r<g) swap(r,g); if(g<b) swap(g,b);
		if(r>g) {
			if(g>b) {
				int times=min(r-g,g-b);
				ret+=times; r-=2*times; g-=times;
			} else if(r-g>=3&&g>0) {
				int times=min((r-g)/3,g);
				ret+=2*times; r-=4*times; g-=times; b-=times;
			} else if(g>0) {
				int times=g;
				ret+=times; r-=times; g-=times; b-=times;
			} else {
				break;
			}
		} else {
			if(g-b>=3) {
				int times=(g-b)/3;
				ret+=2*times; r-=3*times; g-=3*times;
			} else if(g-b>=2) {
				ret++; r-=1; g-=2;
			} else if(b>0) {
				int times=b;
				ret+=times; r-=times; g-=times; b-=times;
			} else {
				break;
			}
		}
		//printf("%d %d %d (%d)\n",r,g,b,ret);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}