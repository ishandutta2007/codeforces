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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int a[3000]; // curidx->val
int s[3000]; // finidx->curidx
int t[3000]; // curidx->finidx
bool mycmp(const int &p,const int &q) { if(a[p]!=a[q]) return a[p]<a[q]; return p<q; }

int ret[3000][2],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) s[i]=i; sort(s,s+n,mycmp);
	REP(i,n) t[s[i]]=i;

	nret=0;
	REP(i,n) {
		if(s[i]==i) continue;
		int p=s[i],q=i;
		ret[nret][0]=p; ret[nret][1]=q; ++nret;
		swap(a[p],a[q]);
		swap(s[i],s[t[i]]);
		swap(t[i],t[p]);
	}
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d\n",ret[i][0],ret[i][1]);
}

int main() {
	run();
	return 0;
}