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

int sz,n;
int x[MAXN],y[MAXN]; char dir[MAXN];

set<pair<int,int> > done;
int ret[MAXN];


void run() {
	scanf("%d%d",&sz,&n);

	REP(i,n) scanf("%d%d %c",&x[i],&y[i],&dir[i]);

	REP(i,n) {
		set<pair<int,int> >::iterator prvit=done.upper_bound(MP(x[i],INT_MAX));
		pair<int,int> prv=prvit==done.begin()?MP(-1,-1):*(--prvit);
		set<pair<int,int> >::iterator nxtit=done.lower_bound(MP(x[i],INT_MIN));
		pair<int,int> nxt=nxtit==done.end()?MP(-1,-1):*(nxtit);
		if(dir[i]=='U') {
			if(nxt.first==-1) ret[i]=sz+1-x[i];
			else if(dir[nxt.second]=='U'&&x[nxt.second]!=x[i]) ret[i]=ret[nxt.second]+x[nxt.second]-x[i];
			else ret[i]=x[nxt.second]-x[i];
		} else {
			if(prv.first==-1) ret[i]=x[i];
			else if(dir[prv.second]=='L'&&x[prv.second]!=x[i]) ret[i]=ret[prv.second]+x[i]-x[prv.second];
			else ret[i]=x[i]-x[prv.second];
		}
		if(prv.first!=x[i]&&nxt.first!=x[i]) done.insert(MP(x[i],i));
		printf("%d\n",ret[i]);
	}
}

int main() {
	run();
	return 0;
}