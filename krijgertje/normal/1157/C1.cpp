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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=200000;

int n;
int a[MAXN];
char ans[MAXN+1]; int nans;



void solve() {
	nans=0; int l=0,r=n-1,last=-1;
	while(l<=r) {
		if(a[l]<=last) { while(l<=r&&a[r]>last) ans[nans++]='R',last=a[r],--r; break; }
		if(a[r]<=last) { while(l<=r&&a[l]>last) ans[nans++]='L',last=a[l],++l; break; }
		if(a[l]<a[r]) { ans[nans++]='L',last=a[l],++l; continue; }
		if(a[r]<a[l]) { ans[nans++]='R',last=a[r],--r; continue; }
		int nl=1; while(nl<r-l+1&&a[l+nl]>a[l+nl-1]) ++nl;
		int nr=1; while(nr<r-l+1&&a[r-nr]>a[r-nr+1]) ++nr;
		if(nl>=nr) REP(i,nl) ans[nans++]='L'; else REP(i,nr) ans[nans++]='R'; break;
	}
	ans[nans]='\0';
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nans);
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}