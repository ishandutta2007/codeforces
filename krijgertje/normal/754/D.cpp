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

const int MAXN=300000;
typedef struct C { int l,r,idx; } C;
bool operator<(const C &a,const C &b) { return a.l<b.l; }

int n,want;
C c[MAXN];
priority_queue<pair<int,int> > q;

int res[MAXN],nres;


void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d%d",&c[i].l,&c[i].r),c[i].idx=i;
	sort(c,c+n);
	ll ret=0;
	REP(x,2) {
		if(x==1&&ret==0) { nres=0; REP(i,want) res[nres++]=c[i].idx; continue; }
		q=priority_queue<pair<int,int> >();
		REP(i,n) {
			while(SZ(q)>0&&-q.top().first<c[i].l) q.pop();
			q.push(MP(-c[i].r,i));
			while(SZ(q)>want) q.pop();
			if(SZ(q)==want) {
				int cur=-q.top().first-c[i].l+1;
				if(x==0&&cur>ret) ret=cur;
				if(x==1&&cur==ret) { nres=0; while(SZ(q)>0) res[nres++]=c[q.top().second].idx,q.pop(); break; }
			}
		}
	}
	sort(res,res+nres);
	printf("%lld\n",ret);
	REP(i,nres) { if(i!=0) printf(" "); printf("%d",res[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}