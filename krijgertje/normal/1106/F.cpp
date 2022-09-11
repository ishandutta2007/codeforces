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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }


int discretelog(int x,int proot,int mod) { // find y such that proot^y=x (mod mod). Assumes mod is prime and proot is in fact a primitive root.
	int step=(int)ceil(sqrt(mod));
	map<int,int> mp;
	int b=1; REP(i,step) mp[b]=i,b=(ll)b*proot%mod;
	int a=x; REP(i,step) if(!mp.count(a)) a=(ll)a*b%mod; else return (mp[a]-i*step+mod-1)%(mod-1);
	assert(false); return -1;
}

vector<int> solvelinrec(const vector<int> &c,int n,int mod) {
	int dim=SZ(c); vector<int> ret;	if(n<dim) { ret=vector<int>(dim,0); ret[n]=1; return ret; }
	if(n%2==1) { ret=solvelinrec(c,n-1,mod); ret.insert(ret.begin(),0); } else { vector<int> tmp=solvelinrec(c,n/2,mod); ret=vector<int>(2*dim-1,0); REP(i,dim) REP(j,dim) ret[i+j]=(ret[i+j]+(ll)tmp[i]*tmp[j])%mod; }
	while(SZ(ret)>dim) { REP(i,dim) ret[SZ(ret)-i-2]=(ret[SZ(ret)-i-2]+(ll)c[i]*ret[SZ(ret)-1])%mod; ret.pop_back(); }
	return ret;
}

int egcd(int a,int b,int &x,int &y) { // a*x+b*y=g
	if(b==0) { x=1,y=0; return a; }
	int g=egcd(b,a%b,y,x); y-=(a/b)*x; return g;
}

int solvemodeq(int a,int b,int mod) { // find any 0<=x<mod satisfying a*x=b (modulo mod), or return -1 iff no solution
	a%=mod; if(a<0) a+=mod; b%=mod; if(b<0) b+=mod;
	int y,z,g=egcd(a,mod,y,z); // y*a+z*MOD=g
	if(b%g!=0) return -1; int x=(ll)(b/g)*y%mod; if(x<0) x+=mod; return x;
}

int pw(int x, int n, int mod) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%mod; if ((n >>= 1) == 0) return ret; x = (ll)x*x%mod; } }


const int MAXDIM=100;
const int MOD=998244353;
const int PROOT=3;

int dim;
vector<int> c;
int n,fn;

int solve() {
	int want=discretelog(fn,PROOT,MOD);
	vector<int> b=solvelinrec(c,n-1,MOD-1);
	int z=solvemodeq(b[dim-1],want,MOD-1);
	return z==-1?-1:pw(PROOT,z,MOD);
}

void run() {
	scanf("%d",&dim);
	c=vector<int>(dim); REP(i,dim) scanf("%d",&c[i]);
	scanf("%d%d",&n,&fn);
	printf("%d\n",solve());	
}

int main() {
	run();
	return 0;
}