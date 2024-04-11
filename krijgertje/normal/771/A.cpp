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

const int MAXN=150000;

int n,m;
int uf[MAXN];

int find(int a) { if(uf[a]<0) return a; else return uf[a]=find(uf[a]); }
void unite(int a,int b) {
	a=find(a),b=find(b);
	if(a==b) return;
	if(-uf[a]<-uf[b]) swap(a,b);
	uf[a]+=uf[b]; uf[b]=a;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,n) uf[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		unite(a,b);
	}
	ll want=0;
	REP(i,n) if(uf[i]<0) { int cur=-uf[i]; want+=(ll)cur*(cur-1)/2; }
	printf("%s\n",want==m?"YES":"NO");
}

int main() {
	run();
	return 0;
}