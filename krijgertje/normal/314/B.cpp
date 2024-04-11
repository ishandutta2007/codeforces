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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int alen,clen;
char a[101],c[101];
int b,d;

int nxt[30][100];
int gain[30][100];

void run(int casenr) {
	scanf("%d%d%s%s",&b,&d,a,c);
	alen=strlen(a); clen=strlen(c);

	REP(i,clen) {
		int at=i;
		REP(j,alen) if(a[j]==c[at%clen]) ++at;
		nxt[0][i]=at%clen;
		gain[0][i]=at/clen;
	}
	FOR(i,1,30) REP(j,clen) {
		nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		gain[i][j]=gain[i-1][j]+gain[i-1][nxt[i-1][j]];
	}

//	REP(i,10) REP(j,clen) printf("%d %d: %d [%d]\n",i,j,nxt[i][j],gain[i][j]);

	int at=0,cnt=0;
	REP(i,30) if(b&(1<<i)) {
		cnt+=gain[i][at];
		at=nxt[i][at];
	}
	int ret=cnt/d;

/*	{
		int at2=0,cnt2=0;
		REP(i,b) { cnt2+=gain[0][at2]; at2=nxt[0][at2]; }
		assert(cnt2==cnt);
	}

	{
		int at3=0;
		REP(i,b) REP(j,alen) if(a[j]==c[at3%clen]) ++at3;
		int cnt3=at3/clen;
		assert(cnt3==cnt);
	} */

	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}