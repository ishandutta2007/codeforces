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

const int MAXN=36;

int want,n;
char a[MAXN][3],b[MAXN];
int cnt[6],ncnt[6];

void run() {
	scanf("%d%d",&want,&n);
	REP(i,n) scanf("%s %c",a[i],&b[i]);
	memset(cnt,0,sizeof(cnt)); cnt[0]=1;
	REP(i,want-1) {
		memset(ncnt,0,sizeof(ncnt));
		REP(j,n) ncnt[a[j][0]-'a']+=cnt[b[j]-'a'];
		REP(j,6) cnt[j]=ncnt[j];
	}
	int ret=0; REP(i,6) ret+=cnt[i]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}