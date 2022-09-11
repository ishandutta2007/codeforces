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

const ll MAXVAL=10004205361450475LL;
const int MAXK=10000;
const int MAXQ=5;

ll cnt[MAXQ+1][MAXK+1]; // cnt[i][j] is number of options we can distinguish with i queries when value is known to be at least j

ll cur[MAXK];

void solve(int i,int j,ll lo) {
	cur[0]=cnt[i-1][j]+lo;
	FOR(k,1,j) cur[k]=min(MAXVAL,cur[k-1]+cnt[i-1][(int)min((ll)MAXK,cur[k-1]+1)]+1);
	printf("%d",j); REP(k,j) printf(" %lld",cur[k]); puts(""); fflush(stdout);
	int ans; scanf("%d",&ans);
	if(ans<0) return;
	if(ans==0) solve(i-1,j,lo); else solve(i-1,(int)min((ll)MAXK,cur[ans-1]+1),cur[ans-1]+1);
}

void run() {
	memset(cnt,0,sizeof(cnt));
	FORE(j,1,MAXK) cnt[1][j]=j;
	FORE(i,2,MAXQ) FORE(j,1,MAXK) {
		cur[0]=cnt[i-1][j]+j;
		FOR(k,1,j) cur[k]=min(MAXVAL,cur[k-1]+cnt[i-1][(int)min((ll)MAXK,cur[k-1]+1)]+1);
		cnt[i][j]=min(MAXVAL,cur[j-1]+cnt[i-1][(int)min((ll)MAXK,cur[j-1]+1)])-(j-1);
		//if(i==3&&j==1) { printf("%d,%d:",i,j); REP(k,j) printf(" %lld",cur[k]); printf(" -> %lld\n",cnt[i][j]); }
	}
	//FORE(i,1,MAXQ) printf("cnt[%d][%d]=%lld\n",i,1,cnt[i][1]);

	solve(5,1,1);
}

int main() {
	run();
	return 0;
}