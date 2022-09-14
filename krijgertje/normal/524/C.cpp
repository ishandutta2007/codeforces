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

typedef struct X { int amount,cost,type; } X;
bool operator<(const X &p,const X &q) { if(p.amount!=q.amount) return p.amount<q.amount; return p.cost<q.cost; }

int n,maxeach;
X all[100001]; int nall;


void run() {
	scanf("%d%d",&n,&maxeach);
	nall=0; all[nall].amount=0,all[nall].cost=0,all[nall].type=-1,++nall; REP(i,n) { int cur; scanf("%d",&cur); FORE(j,1,maxeach) all[nall].amount=cur*j,all[nall].cost=j,all[nall].type=i,++nall; }
	sort(all,all+nall);
	
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int want; scanf("%d",&want);
		int ret=INT_MAX,l=0,h=nall-1;
		while(l<h) {
			int nl=l+1,l1=l,l2=-1; while(nl<nall&&all[l].amount==all[nl].amount) { if(all[nl].cost<all[l1].cost) l2=l1,l1=nl; else if(l2==-1||all[nl].cost<all[l2].cost) l2=nl; ++nl; }
			int nh=h-1,h1=h,h2=-1; while(nh>=0  &&all[h].amount==all[nh].amount) { if(all[nh].cost<all[h1].cost) h2=h1,h1=nh; else if(h2==-1||all[nh].cost<all[h2].cost) h2=nh; --nh; }
			int now=all[l].amount+all[h].amount;
			if(now>want) h=nh;
			else if(now<want) l=nl;
			else {
				//printf("want %d: %d (%d=%d,%d=%d) + %d (%d=%d,%d=%d)\n",want,all[l].amount,all[l1].type,all[l1].cost,l2==-1?-2:all[l2].type,l2==-1?INT_MAX:all[l2].cost,all[h].amount,all[h1].type,all[h1].cost,h2==-1?-2:all[h2].type,h2==-1?INT_MAX:all[h2].cost);
				int cur=all[l1].type!=all[h1].type?all[l1].cost+all[h1].cost:min(h2==-1?INT_MAX:all[l1].cost+all[h2].cost,l2==-1?INT_MAX:all[l2].cost+all[h1].cost);
				if(cur<ret&&cur<=maxeach) ret=cur;
				h=nh,l=nl;
			}
		}
		printf("%d\n",ret==INT_MAX?-1:ret);
	}

}

int main() {
	run();
	return 0;
}