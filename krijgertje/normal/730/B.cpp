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

const int MAXN=50;

int n;
pair<int,int> solve(int l,int r) {
	if(l==r) return MP(l,r);
	printf("? %d %d\n",r-1,r); fflush(stdout); char res1; scanf(" %c",&res1); int a=r-1,b=r; if(res1=='>') swap(a,b);
	if(r-1==l) return MP(a,b);
	pair<int,int> sub=solve(l,r-2);
	printf("? %d %d\n",a,sub.first); fflush(stdout); char res2; scanf(" %c",&res2); if(res2=='>') a=sub.first;
	printf("? %d %d\n",b,sub.second); fflush(stdout); char res3; scanf(" %c",&res3); if(res3=='<') b=sub.second;
	return MP(a,b);
}

void run() {
	scanf("%d",&n);
	pair<int,int> ret=solve(1,n);
	printf("! %d %d\n",ret.first,ret.second); fflush(stdout); 
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}