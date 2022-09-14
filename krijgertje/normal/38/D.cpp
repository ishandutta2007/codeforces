#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
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
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int n; scanf("%d",&n);
	vector<int> x(n),y(n),sz(n);
	REP(i,n) {
		int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int minx=min(x1,x2),maxx=max(x1,x2),miny=min(y1,y2),maxy=max(y1,y2);
		x[i]=minx,y[i]=miny,sz[i]=maxx-minx;
	}
	
	vector<ll> mx(n),my(n),w(n); // mx and my are 'double'
	REP(i,n) {
		mx[i]=sz[i]*sz[i]*sz[i]*(2*x[i]+sz[i]);
		my[i]=sz[i]*sz[i]*sz[i]*(2*y[i]+sz[i]);
		w[i]=sz[i]*sz[i]*sz[i];
		ll mxsum=mx[i],mysum=my[i],wsum=w[i];
		bool ok=true;
		for(int j=i-1;j>=0;--j) {
			if(mxsum<2*wsum*x[j]||mxsum>2*wsum*(x[j]+sz[j])) { ok=false; break; }
			if(mysum<2*wsum*y[j]||mysum>2*wsum*(y[j]+sz[j])) { ok=false; break; }
			mxsum+=mx[j],mysum+=my[j],wsum+=w[j];
		}
		if(!ok) { printf("%d\n",i); return; }
	}
	printf("%d\n",n);
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}