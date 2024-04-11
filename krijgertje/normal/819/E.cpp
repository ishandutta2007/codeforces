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

const int MAXN=300;

int n;
vector<vector<int> > ret;

void cyc(int a,int b,int c) { vector<int> v(3); v[0]=a,v[1]=b,v[2]=c; ret.PB(v); }
void cyc(int a,int b,int c,int d) { vector<int> v(4); v[0]=a,v[1]=b,v[2]=c,v[3]=d; ret.PB(v); }
void cutcyc(int a,int b,int c,int d) { cyc(a,b,c); cyc(a,c,d); }

void chk() {
	vector<vector<int> > cnt(n,vector<int>(n,0)); REPSZ(i,ret) REPSZ(j,ret[i]) { int a=ret[i][j]-1,b=ret[i][(j+1)%SZ(ret[i])]-1; if(a>b) swap(a,b); ++cnt[a][b]; }
	REP(i,n) REP(j,n) { int want=i<j?2:0; if(cnt[i][j]!=want) { printf("%d %d: have=%d want=%d\n",i+1,j+1,cnt[i][j],want); } }
}

void run() {
	scanf("%d",&n);
	ret.clear();
	int base=(n%2==1?3:4);
	if(base==3) {
		cyc(1,2,3);
		cyc(1,2,3);
	} else {
		cutcyc(1,3,2,4);
		cutcyc(3,2,4,1);
	}
	for(int i=base;i<n;i+=2) {
		int a=i+1,b=i+2;
		if(base==3) {
			cutcyc(a,1,b,2);
			cyc(a,2,b,3);
			cyc(a,3,b,1);
		}
		for(int j=(base==3?3:0);j<i;j+=2) {
			int c=j+1,d=j+2;
			if(j==0) cutcyc(a,c,b,d); else cyc(a,c,b,d);
			cyc(a,c,b,d);
		}
	}
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) { printf("%d",SZ(ret[i])); REPSZ(j,ret[i]) printf(" %d",ret[i][j]); puts(""); }
	//chk();
}

int main() {
	run();
	return 0;
}