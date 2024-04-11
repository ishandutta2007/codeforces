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
const int MAXV=5;

int n,k,nq;
int x[MAXN];
int v[MAXV],nv;


void run() {
	scanf("%d%d%d",&n,&k,&nq);
	REP(i,n) scanf("%d",&x[i]);
	REP(qi,nq) {
		int type,idx; scanf("%d%d",&type,&idx); --idx;
		if(type==1) {
			if(nv<k) {
				v[nv++]=idx;
			} else {
				int ridx=-1; REP(i,nv) if(x[v[i]]<x[idx]&&(ridx==-1||x[v[i]]<x[v[ridx]])) ridx=i; if(ridx!=-1) v[ridx]=idx;
			}
		}
		if(type==2) {
			bool ret=false; REP(i,nv) if(v[i]==idx) ret=true; printf("%s\n",ret?"YES":"NO");
		}
	}
}

int main() {
	run();
	return 0;
}