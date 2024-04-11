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

int a,b,c;
int ret[81],nret;

void run() {
	scanf("%d%d%d",&a,&b,&c);
	FORE(sum,1,9*9) {
		int x=b; bool ok=true;
		REP(i,a) if(x>INT_MAX/sum) ok=false; else x*=sum;
		if(c>0&&x>INT_MAX-c||c<0&&x<INT_MIN-c) ok=false; else x+=c;
		if(!ok||x<=0||x>=1000000000) continue;
		int have=0; for(int y=x;y!=0;y/=10) have+=y%10; if(have==sum) ret[nret++]=x;
	}
	sort(ret,ret+nret);
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}