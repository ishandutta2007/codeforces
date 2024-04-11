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

const int MAXN=100000;

int n;
int a[MAXN],b[MAXN];

int c[2*MAXN],nc;
int d[2*MAXN];
int e[2*MAXN];

int fw[1<<18];
void inc(int x) { ++x; while(x<(1<<18)) { fw[x]++; x+=x&-x; } }
int get(int x) { ++x; int ret=0; while(x>0)  { ret+=fw[x]; x-=x&-x;  } return ret; }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);

	nc=0; REP(i,n) c[nc++]=a[i],c[nc++]=b[i]; sort(c,c+nc); nc=unique(c,c+nc)-c;
	REP(i,n) { int l=0,h=nc; while(l+1<h) { int m=l+(h-l)/2; if(c[m]<=a[i]) l=m; else h=m; } assert(c[l]==a[i]); a[i]=l; }
	REP(i,n) { int l=0,h=nc; while(l+1<h) { int m=l+(h-l)/2; if(c[m]<=b[i]) l=m; else h=m; } assert(c[l]==b[i]); b[i]=l; }

	REP(i,nc) d[i]=i,e[i]=i;
	REP(i,n) { int aa=a[i],bb=b[i]; swap(d[aa],d[bb]); swap(e[d[aa]],e[d[bb]]); }
	//REP(i,nc) printf("%d=%d ",c[i],c[d[i]]); puts("");
	//REP(i,nc) printf("%d at %d, ",c[i],c[e[i]]); puts("");

	ll ret=0;
	REP(i,nc) {
		// ret+=# c[e[i]]<x<c[i] | x not in c
		if(e[i]<i) ret+=(c[i]-c[e[i]])-(i-e[i]);
		// ret+=# c[i]<x<c[e[i]] | x not in c
		if(i<e[i]) ret+=(c[e[i]]-c[i])-(e[i]-i);
		// ret+=# j<i | e[j]>e[i]
		ret+=i-get(e[i]);
		inc(e[i]);
	}

	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}