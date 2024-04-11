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

const int MAXN=200000;
typedef struct X { int idx,val; } X;
bool operator<(const X &a,const X &b) { if(a.val!=b.val) return a.val<b.val; return a.idx<b.idx; }

int n,mult;
X x[MAXN];

void run() {
	scanf("%d%d",&n,&mult);
	REP(i,n) x[i].idx=i,scanf("%d",&x[i].val);
	sort(x,x+n);

	int a=0,b=0,c=0;
	ll ret=0;
	while(a<n) {
		int A=a; while(A<n&&x[a].val==x[A].val) ++A;
		if(mult==1||x[a].val==0) {
			ret+=(ll)(A-a)*(A-a-1)*(A-a-2)/6;
		} else {
			while(b<n&&x[b].val<(ll)mult*x[a].val) ++b;
			while(c<n&&x[c].val<(ll)mult*x[b].val) ++c;
			int B=b; while(B<n&&x[b].val==x[B].val) ++B;
			int C=c; while(C<n&&x[c].val==x[C].val) ++C;
			if(b<n&&x[b].val==(ll)mult*x[a].val&&c<n&&x[c].val==(ll)mult*x[b].val) {
				int ai=a,ci=c;
				//printf("%d %d %d -> %d..%d %d..%d %d..%d\n",x[a].val,x[b].val,x[c].val,a,A,b,B,c,C);
				FOR(bi,b,B) {
					while(ai<A&&x[ai].idx<x[bi].idx) ++ai;
					while(ci<C&&x[ci].idx<x[bi].idx) ++ci;
					//printf("%d (%d) -> %d*%d\n",x[bi].idx,x[bi].val,ai-a,C-ci);
					ret+=(ll)(ai-a)*(C-ci);
				}
			}
		}
		a=A;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}