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

const int MAXSTATION=5000;
const int MAXCANDY=20000;

int nstation,ncandy;
int a[MAXCANDY],b[MAXCANDY];
ll ans[MAXSTATION];

vector<int> c[MAXSTATION];
vector<int> d[MAXSTATION];

void solve() {
	REP(i,nstation) c[i].clear();
	REP(i,ncandy) { int from=a[i],to=b[i],dst=(to-from+nstation)%nstation; c[from].PB(dst); }
	REP(i,nstation) sort(c[i].begin(),c[i].end());
	//REP(i,nstation) { printf("c%d:",i); REPSZ(j,c[i]) printf(" %d",c[i][j]); puts(""); }

	REP(i,nstation) {
		REP(j,nstation) d[j]=c[(i+j)%nstation];
		int k=-1; REP(j,nstation) if(SZ(d[j])>=2&&(k==-1||SZ(d[j])>=SZ(d[k]))) k=j;
		if(k==-1) {
			ans[i]=0;
			REP(j,nstation) if(SZ(d[j])!=0) { assert(SZ(d[j])==1); ans[i]=max(ans[i],(ll)j+d[j][0]); }
		} else {
			ll extra=0;
			FORE(j,1,nstation) { int at=(k+j)%nstation; int rem=SZ(d[at]); if(at<=k) rem-=SZ(d[k])-1; else rem-=SZ(d[k])-2; if(rem>0) { assert(rem==1); extra=max(extra,(ll)j+d[at][0]); }  }
			ans[i]=k+(ll)nstation*(SZ(d[k])-2)+extra;
		}
	}
}



void run() {
	scanf("%d%d",&nstation,&ncandy);
	REP(i,ncandy) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	solve();
	REP(i,nstation) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}