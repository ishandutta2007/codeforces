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

const int MAXN=2000;
typedef struct S { int score,two,one; S() {} S(int score,int two,int one):score(score),two(two),one(one) {} } S;

int n;
int a[MAXN];

S pref[MAXN+1];
S suff[MAXN+1];

S append(const S &x,int val) { S ret=x; if(val==2) ++ret.two; else ++ret.one; if(ret.one>=ret.two) ret.score+=ret.one,ret.one=ret.two=0; return ret; }
S combine(const S &x,const S &y) { S ret=x; ret.one+=y.score; if(ret.one>=ret.two) ret.score+=ret.one,ret.one=ret.two=0; ret.two+=y.two,ret.one+=y.one; return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REPE(i,n) { pref[i]=S(0,0,0); REP(j,i) pref[i]=append(pref[i],a[j]); }
	REPE(i,n) { suff[i]=S(0,0,0); FOR(j,i,n) suff[i]=append(suff[i],a[j]); }

	int ret=0;
	REP(r,n) {
		S cur=S(0,0,0);
		for(int l=r;l>=0;--l) {
			cur=append(cur,a[l]);
			S now=combine(combine(pref[l],cur),suff[r+1]);
			ret=max(ret,now.score+now.two);
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}