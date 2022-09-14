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

int nvid,nserv;
int t[500000],len[500000]; ll ret[500000];
priority_queue<ll> q;

void run() {
	scanf("%d%d",&nvid,&nserv);
	REP(i,nvid) scanf("%d%d",&t[i],&len[i]);

	REP(i,nvid) {
		while(!q.empty()&&-q.top()<=t[i]) q.pop();
		if(SZ(q)<nserv) {
			ret[i]=t[i]+len[i];
			q.push(-ret[i]);
		} else {
			ret[i]=-q.top()+len[i];
			q.pop(); q.push(-ret[i]);
		}
	}
	REP(i,nvid) cout<<ret[i]<<endl;
}

int main() {
	run();
	return 0;
}