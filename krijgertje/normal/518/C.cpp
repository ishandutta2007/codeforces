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

int n,nq,sz;
int app[100000];
int pos[100000];

void run() {
	scanf("%d%d%d",&n,&nq,&sz);
	REP(i,n) { scanf("%d",&app[i]); --app[i]; }
	REP(i,n) pos[app[i]]=i;
	ll ret=0;
	REP(qi,nq) {
		int x; scanf("%d",&x); --x;
		ret+=(pos[x]/sz)+1;
		if(pos[x]==0) continue;
		int y=app[pos[x]-1];
		swap(app[pos[x]],app[pos[x]-1]);
		swap(pos[x],pos[y]);
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}