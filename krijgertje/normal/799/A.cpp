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


int need,tbake,cnt,toven;
int ret[2];


void run() {
	scanf("%d%d%d%d",&need,&tbake,&cnt,&toven);
	REP(i,2) {
		priority_queue<int> q; q.push(-tbake); if(i==1) q.push(-(toven+tbake));
		int left=need;
		while(!q.empty()) {
			int t=-q.top(); q.pop();
			left-=cnt; if(left<=0) { ret[i]=t; break; }
			q.push(-(t+tbake));
		}
	}
	//printf("%d %d\n",ret[0],ret[1]);
	printf("%s\n",ret[1]<ret[0]?"YES":"NO");
}

int main() {
	run();
	return 0;
}