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

int n,k,a,b,nq;
int tot[MAXN];
int bta[MAXN+1];
int btb[MAXN+1];
void bmod(int* bt,int idx,int by) { ++idx; while(idx<n) { bt[idx]+=by; idx+=idx&-idx; } }
int bget(int* bt,int idx) { int ret=0; while(idx>0) { ret+=bt[idx]; idx-=idx&-idx; } return ret; }

void run() {
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&nq);

	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int idx,cnt; scanf("%d%d",&idx,&cnt); --idx;
			int bya=min(a,tot[idx]+cnt)-min(a,tot[idx]); bmod(bta,n-idx-1,bya);
			int byb=min(b,tot[idx]+cnt)-min(b,tot[idx]); bmod(btb,idx,byb);
			tot[idx]+=cnt;
		}
		if(type==2) {
			int idx; scanf("%d",&idx); --idx;
			int ret=bget(bta,n-k-idx)+bget(btb,idx);
			printf("%d\n",ret);
		}
	}

}

int main() {
	run();
	return 0;
}