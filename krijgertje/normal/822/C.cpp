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
const int MAXV=200000;

int n,want;
int l[MAXN],r[MAXN],c[MAXN];

vector<int> s[MAXV],t[MAXV];

int mn[MAXV+1];


void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d%d%d",&l[i],&r[i],&c[i]),--l[i],--r[i];
	REP(i,MAXV) s[i].clear(),t[i].clear(),mn[i+1]=-1; REP(i,n) s[l[i]].PB(i),t[r[i]].PB(i);

	ll ret=-1;
	REP(i,MAXV) {
		REPSZ(j,s[i]) {
			int a=s[i][j];
			int have=r[a]-l[a]+1; if(have>=want) continue;
			int rem=want-have;
			if(mn[rem]!=-1) {
				ll cur=c[a]+mn[rem]; if(ret==-1||cur<ret) ret=cur;
			}
		}
		REPSZ(j,t[i]) {
			int a=t[i][j];
			int have=r[a]-l[a]+1; if(have>=want) continue;
			if(mn[have]==-1||c[a]<mn[have]) mn[have]=c[a];
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}