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
const int MAXQ=300000;

int n,nq;
int cnt[MAXN],upto[MAXN];
int nt[MAXQ],nnt;
int ret;

void run() {
	scanf("%d%d",&n,&nq);
	nnt=ret=0; int at=0; memset(cnt,0,sizeof(cnt)); memset(upto,0,sizeof(upto));
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int x; scanf("%d",&x); --x; nt[nnt++]=x; ++cnt[x]; ++ret;
		}
		if(type==2) {
			int x; scanf("%d",&x); --x; ret-=cnt[x]; cnt[x]=0; upto[x]=nnt;
		}
		if(type==3) {
			int t; scanf("%d",&t); 
			while(at<t) {
				int x=nt[at];
				if(at>=upto[x]) --ret,--cnt[x],upto[x]=at+1;
				++at;
			}
		}
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}