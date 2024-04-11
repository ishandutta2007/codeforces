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

typedef struct Pol {
	vector<int> a;
} Pol;

int n;
vector<Pol> pols;

void print(const Pol &p) { printf("%d\n",SZ(p.a)-1); REPSZ(i,p.a) { if(i!=0) printf(" "); printf("%d",p.a[i]); } puts(""); }

int calc(Pol p,Pol q) {
	int ret=0; assert(SZ(p.a)>SZ(q.a));
	while(SZ(q.a)!=0) {
		int shift=SZ(p.a)-SZ(q.a); int times=q.a.back()*p.a.back();
		REPSZ(i,q.a) p.a[i+shift]-=times*q.a[i];
		while(SZ(p.a)>0&&p.a.back()==0) p.a.pop_back();
		REPSZ(i,p.a) assert(abs(p.a[i])<=1);
		swap(p,q); ++ret;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	Pol p0; p0.a.PB(1); pols.PB(p0);
	Pol p1; p1.a.PB(0); p1.a.PB(1); pols.PB(p1);
	REP(j,n-1) {
		Pol p=pols.back();
		Pol q=pols[SZ(pols)-2];
		p.a.insert(p.a.begin(),0);
		bool inv=false; REPSZ(i,q.a) if(abs(p.a[i]+q.a[i])>1) inv=true;
		//if(inv) REPSZ(i,p.a) p.a[i]=-p.a[i];
		REPSZ(i,q.a) p.a[i]+=(!inv?+1:-1)*q.a[i];
		pols.PB(p);
	}
	REPSZ(i,pols) REPSZ(j,pols[i].a) assert(abs(pols[i].a[j])<=1);
	//REPSZ(i,pols) { printf("%d:",i); REPSZ(j,pols[i].a) printf(" %d",pols[i].a[j]); puts(""); }
	print(pols.back()); print(pols[SZ(pols)-2]);

	//FORE(i,1,n) { int have=calc(pols[i],pols[i-1]); if(have!=i) printf("%d: have=%d\n",i,have); }


}

int main() {
	run();
	return 0;
}