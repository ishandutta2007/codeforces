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

const int MOD=1000000007;

char s[5001]; int slen;

int minprints[5001][5002];
int ways[5001][5002]; // ways[i][j] == number of ways to make the sequence to print the first i characters and we can use a print of length j next

inline void update(int si,int sj,int ti,int tj,int extra) {
	if((ways[ti][tj]+=ways[si][sj])>=MOD) ways[ti][tj]-=MOD;
	if(minprints[ti][tj]==-1||minprints[si][sj]+extra<minprints[ti][tj]) minprints[ti][tj]=minprints[si][sj]+extra;
}

int leneq[5001][5001];

bool islowerequal(int a,int b,int len) {
	int x=leneq[a][b];
	return x>=len?true:s[a+x]<s[b+x];
}

void run() {
	scanf("%s",s); slen=strlen(s);

//	slen=5000; REP(i,slen) s[i]='1';

	memset(leneq,0,sizeof(leneq));
	for(int i=slen-1;i>=0;--i) for(int j=slen-1;j>=0;--j) if(s[i]==s[j]) leneq[i][j]=1+leneq[i+1][j+1];

	memset(minprints,-1,sizeof(minprints));
	memset(ways,0,sizeof(ways));
	ways[0][1]=1; minprints[0][1]=0;
	REP(i,slen) if(s[i]=='1') FORE(j,1,slen-i) if(minprints[i][j]!=-1) {
		update(i,j,i,j+1,0);
		bool ok=i+2*j>slen||islowerequal(i,i+j,j);
		update(i,j,i+j,j+(ok?0:1),1);
	}


	int totways=0;
	FORE(j,1,slen) if((totways+=ways[slen][j])>=MOD) totways-=MOD;
	int totminlen=INT_MAX;
	FORE(j,1,slen) if(minprints[slen][j]!=-1) {
		int curminlen=0;
		REP(i,j) curminlen=(curminlen*2+s[slen-j+i]-'0')%MOD;
		curminlen=(curminlen+minprints[slen][j])%MOD;
		if(curminlen<totminlen&&(totminlen==INT_MAX||j<=20)) totminlen=curminlen;
	}
	printf("%d\n%d\n",totways,totminlen);
}

int main() {
	run();
	return 0;
}