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
int x[5000];

int go(int a,int b,int c) {
	int ret=b-a+1;
	int l=x[a]; FORE(i,a+1,b) if(x[i]<l) l=x[i];
	int cur=l-c;
	int at=a;
	while(at<=b) {
		if(x[at]==l) { ++at; continue; }
		int to=at; while(to+1<=b&&x[to+1]!=l) ++to;
		//printf("[%d..%d] -> [%d..%d]\n",a,b,at,to);
		cur+=go(at,to,l);
		at=to+1;
	}
	if(cur<ret) ret=cur;
	//printf("[%d..%d] = %d\n",a,b,ret);
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	
	int ret=go(0,n-1,0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}