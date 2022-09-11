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

int alim,blim;

vector<int> a;
vector<int> b;

void solve() {
	int ans=0; while((ll)(ans+1)*(ans+2)/2<=alim+blim) ++ans;
	a.clear(); b.clear();
	int nxt=ans,arem=alim; while(true) { int cur=min(arem,nxt); if(cur==0) break; a.PB(cur); arem-=cur; nxt=cur-1; }
	sort(a.begin(),a.end());
	int at=0;
	FORE(i,1,ans) if(at<SZ(a)&&a[at]==i) ++at; else b.PB(i);
	int atot=0,btot=0; REPSZ(i,a) atot+=a[i]; REPSZ(i,b) btot+=b[i];
	//printf("ans=%d atot=%d btot=%d\n",ans,atot,btot);
}

void run() {
	scanf("%d%d",&alim,&blim);
	solve();
	printf("%d\n",SZ(a)); REPSZ(i,a) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
	printf("%d\n",SZ(b)); REPSZ(i,b) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}

int main() {
	run();
	return 0;
}