
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

const int MAXN=200000;
const int MAXLEN=10;

int n;
char s[MAXN][MAXLEN+1];
bool mycmp(const int &a,const int &b) { int ret=strcmp(s[a],s[b]); return ret<0||ret==0&&a>b; }

int p[MAXN],np;


void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",s[i]);
	REP(i,n) p[i]=i; sort(p,p+n,mycmp);
	//REP(i,n) printf("%d: %s\n",p[i],s[p[i]]); puts("");
	np=0; REP(i,n) if(np==0||strcmp(s[p[np-1]],s[p[i]])!=0) p[np++]=p[i];
	sort(p,p+np); reverse(p,p+np); REP(i,np) printf("%s\n",s[p[i]]);
}

int main() {
	run();
	return 0;
}