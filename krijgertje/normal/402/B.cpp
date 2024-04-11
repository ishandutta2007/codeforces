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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,k;
int a[1000];
int b[1000];

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) b[i]=a[i]-i*k;
	sort(b,b+n);
	int best=-1,bestcnt=0;
	for(int i=0;i<n;) {
		int j=i+1; while(j<n&&b[i]==b[j]) ++j;
		int cnt=j-i; if(b[i]>0&&(best==-1||cnt>bestcnt)) best=b[i],bestcnt=cnt;
		i=j;
	}
	printf("%d\n",n-bestcnt);
	REP(i,n) if(a[i]-i*k!=best) printf("%c %d %d\n",a[i]-i*k<best?'+':'-',i+1,abs(a[i]-i*k-best));

}

int main() {
	run();
	return 0;
}