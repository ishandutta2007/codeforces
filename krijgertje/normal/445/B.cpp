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

int n,m;
int id[50];
int rnk[50];

int get(int x) { if(id[x]==x) return x; return id[x]=get(id[x]); }

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) id[i]=i,rnk[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		a=get(a),b=get(b); if(a==b) continue;
		if(rnk[a]<rnk[b]) swap(a,b);
		id[b]=a; if(rnk[a]==rnk[b]) ++rnk[a];
	}
	int times=n;
	REP(i,n) if(id[i]==i) --times;
	ll ret=1; REP(i,times) ret*=2;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}