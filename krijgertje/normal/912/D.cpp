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

const int MAXH=100000;
const int MAXW=100000;

int h,w,r,cnt;

int hval[MAXH];
int wval[MAXW];

int at[MAXH];
priority_queue<pair<ll,int > > pq;


void run() {
	scanf("%d%d%d%d",&h,&w,&r,&cnt);

	REP(x,h) hval[x]=min(min(x+1,h-x),min(h-r+1,r));
	REP(y,w) wval[y]=min(min(y+1,w-y),min(w-r+1,r));
	//printf("hval:"); REP(x,h) printf(" %d",hval[x]); puts("");
	//printf("wval:"); REP(y,w) printf(" %d",wval[y]); puts("");
	sort(wval,wval+w); reverse(wval,wval+w);
	REP(x,h) at[x]=0;
	pq=priority_queue<pair<ll,int > >(); REP(x,h) pq.push(MP((ll)hval[x]*wval[at[x]],x));

	double num=0,den=(ll)(h-r+1)*(w-r+1);
	REP(i,cnt) {
		ll val=pq.top().first; int x=pq.top().second; pq.pop();
		//printf("%d (%d): %d*%d\n",x,at[x],hval[x],wval[at[x]]);
		num+=val;
		++at[x];
		if(at[x]<w)  pq.push(MP((ll)hval[x]*wval[at[x]],x));
	}
	printf("%.15lf\n",num/den);
}

int main() {
	run();
	return 0;
}