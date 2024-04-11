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


int calc(int x) {
	int ret=0; while(x>0) { ret+=x%10; x/=10; } return ret;
}

void run() {
	int k; scanf("%d",&k);
	int cur=1;
	while(true) {
		int sum=calc(cur);
		if(sum==10) { if(--k==0) break; ++cur; continue; }
		if(sum<10) { cur+=10-sum; continue; }
		if(sum>10) {
			int x=1; while(cur/x%10==0) x*=10;
			int y=cur/x%10; cur+=(10-y)*x;
		}
	}
	printf("%d\n",cur);
}

int main() {
	run();
	return 0;
}