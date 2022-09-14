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

const int MAXN=16;

int n;
int mod[MAXN],rem[MAXN];

// x*a+y*b=g
int egcd(int a,int b,int &x,int &y) {
	if(b==0) { x=1,y=0; return a; }
	int g=egcd(b,a%b,x,y); swap(x,y); y-=x*(a/b); return g;
}
int mymod(int x,int mod) { x%=mod; if(x<0) x+=mod; return x; }
bool combine(int &n1,int &a1,int n2,int a2) {
	// x=a1 mod n1, x=a2 mod n2
	int m1,m2,g=egcd(n1,n2,m1,m2);
	if(a1%g!=a2%g) return false;
	int n3=n1/g*n2,a3=mymod(a1+m1*(n1/g)*(a2-a1),n3);
	//printf("x=%d (mod %d), x=%d (mod %d) -> x=%d (mod %d)\n",a1,n1,a2,n2,a3,n3);
	n1=n3,a1=a3; return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&mod[i]); REP(i,n) scanf("%d",&rem[i]);
	ll den=20922789888000LL,num=0;
	REP(i,1<<n) {
		int cmod=1,crem=0,cnt=0; bool ok=true;
		REP(j,n) if(i&(1<<j)) { ++cnt; if(!combine(cmod,crem,mod[j],rem[j])) ok=false; }
		if(!ok) continue;
		//printf("%2x -> mod %d = %d\n",i,cmod,crem);
		if(cnt%2==0) num+=den/cmod; else num-=den/cmod;
	}
	printf("%.9lf\n",1.0*(den-num)/den);

}

int main() {
	run();
	return 0;
}