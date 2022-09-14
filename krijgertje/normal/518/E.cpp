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

int n,step;
bool known[100000];
int x[100000];
char s[10];

int get(int cnt,int L,int H) {
	//printf("getting(%d,%d,%d)\n",cnt,L,H);
	if(cnt==0) return 0;
	assert(L+cnt-1<=H);
	int l=L>=0?L:H<=0?H:0,h=l;
	REP(i,cnt-1) if(l==L||(h<H&&abs(h+1)<=abs(l-1))) ++h; else --l;
	return l;
}

void run() {
	scanf("%d%d",&n,&step);
	REP(i,n) known[i]=false;
	REP(i,n) { scanf("%s",s); if(strcmp(s,"?")==0) continue; known[i]=true; sscanf(s,"%d",&x[i]); }

	bool ok=true;
	REP(offset,step) {
		int at=offset;
		if(at>=n) continue;
		if(at+step>=n) { if(!known[at]) x[at]=0; continue; }
		while(at+step<n) {
			int cnt=2,to=at+step; while(!known[to]&&to+step<n) to+=step,++cnt;
			//printf("%d..%d\n",at,to);
			if(known[at]&&known[to]) {
				if(x[at]+cnt-1>x[to]) {
					ok=false;
				} else {
					int first=get(cnt-2,x[at]+1,x[to]-1);
					for(int i=at+step,j=0;i<to;i+=step,++j) x[i]=first+j;
				}
			} else if(known[at]) {
				int first=get(cnt-1,x[at]+1,INT_MAX);
				for(int i=at+step,j=0;i<=to;i+=step,++j) x[i]=first+j;
			} else if(known[to]) {
				int first=get(cnt-1,INT_MIN,x[to]-1);
				for(int i=at,j=0;i<to;i+=step,++j) x[i]=first+j;
			} else {
				int first=get(cnt,INT_MIN,INT_MAX);
				for(int i=at,j=0;i<=to;i+=step,++j) x[i]=first+j;
			}
			at=to;
		}
	}
	if(!ok) { printf("Incorrect sequence\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",x[i]); } puts("");
}

int main() {
	run();
	return 0;
}