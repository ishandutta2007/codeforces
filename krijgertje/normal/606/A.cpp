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
int x,y,z;

void run() {
	scanf("%d%d%d",&a,&b,&c); scanf("%d%d%d",&x,&y,&z);
	if(a>=x) a-=x,x=0; else x-=a,a=0;
	if(b>=y) b-=y,y=0; else y-=b,b=0;
	if(c>=z) c-=z,z=0; else z-=c,c=0;
	int d=a/2+b/2+c/2; a/=2,b/=2,c/=2;
	printf("%s\n",d>=x+y+z?"Yes":"No");
}

int main() {
	run();
	return 0;
}