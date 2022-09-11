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

const int MAXN=100000;
const int MAXVAL=1000000;

int n,opp;
int c[MAXN];
int cnt[MAXVAL];
bool dead[MAXVAL];
vector<int> who[MAXN+1];


void run() {
	scanf("%d%d",&n,&opp); --opp; REP(i,n) scanf("%d",&c[i]),--c[i];
	memset(cnt,0,sizeof(cnt));
	REP(i,MAXVAL) if(i!=opp) who[cnt[i]].PB(i),dead[i]=false; else dead[i]=true;
	REP(i,n) {
		if(c[i]==opp) {
			//printf("cnt[opp]=%d (%d)\n",cnt[opp],SZ(who[cnt[opp]]));
			REPSZ(j,who[cnt[opp]]) {
				int x=who[cnt[opp]][j];
				if(dead[x]||cnt[x]!=cnt[opp]) continue;
				dead[x]=true;
			}
			++cnt[opp];
		} else {
			++cnt[c[i]]; who[cnt[c[i]]].PB(c[i]);
		}
	}
	REP(i,MAXVAL) if(!dead[i]) { printf("%d\n",i+1); return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}