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

const int MAXLEN=100000;

int a00,a01,a10,a11;
char ret[MAXLEN+1];

int solve(ll a) { int ret=(1+(int)sqrt(1+8*a))/2; return (ll)ret*(ret-1)==2*a?ret:-1; }
void run() {
	scanf("%d%d%d%d",&a00,&a01,&a10,&a11);
	if(a00==0&&a01==0&&a10==0&&a11==0) { printf("0\n"); return; }
	int len=solve((ll)a00+a01+a10+a11),n0=solve(a00),n1=solve(a11); //printf("%d %d %d\n",len,n0,n1);
	if(a00==0&&a01==0&&a10==0) n0=0; if(a11==0&&a01==0&&a10==0) n1=0;
	if(len==-1||n0==-1||n1==-1||n0+n1!=len) { printf("Impossible\n"); return; }
	REP(i,len) {
		if(a01>=n1) { ret[i]='0'; a01-=n1; --n0; } else { ret[i]='1'; a10-=n0; --n1; }
	}
	assert(a10==0&&n0==0&&n1==0);
	ret[len]='\0'; printf("%s\n",ret);
}

int main() {
	//int n=10000; REP(i,n) ret[i]=rand()%2==0?'0':'1'; int a00=0,a01=0,a10=0,a11=0; REP(i,n) FOR(j,i+1,n) if(ret[i]=='0') if(ret[j]=='0') ++a00; else ++a01; else if(ret[j]=='0') ++a10; else ++a11; printf("%d %d %d %d\n",a00,a01,a10,a11);
	run();
	return 0;
}