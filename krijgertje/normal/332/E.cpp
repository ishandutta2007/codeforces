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

bool ok[2000][200]; // ok[i][j] == for the given number of ones in key, is it ok to put the j-th one in position i
bool can[2001][201]; // can[i][j] == for the given number of ones in key, is it possible to find j ones for positions >= i


int havelen,wantlen,keylen;

char have[1000001];
char want[201];

bool any=false;
char best[2001];
char cur[2001];

void run(int casenr) {
	gets(have); gets(want);
	scanf("%d",&keylen); havelen=strlen(have); wantlen=strlen(want);

	FORE(cntone,1,min(keylen,wantlen)) {
		REP(i,keylen) REP(j,cntone) {
			int ii=i,jj=j; ok[i][j]=true;
//			printf("\tchecking  %d ones, putting %dth one in position %d\n",cntone,j,i);
			while(true) {
				if(ii>=havelen&&jj>=wantlen) break;
				if(ii>=havelen||jj>=wantlen||have[ii]!=want[jj]) { ok[i][j]=false; break; }
//				printf("\t\t%d vs %d\n",ii,jj);
				ii+=keylen;
				jj+=cntone;
			}
//			if(ok[i][j]) printf("\t%d ones, ok to put %dth one in position %d (ok[%d][%d])\n",cntone,j,i,i,j);
		}
		memset(can,false,sizeof(can));
		can[keylen][0]=true;
		for(int i=keylen-1;i>=0;--i) REPE(j,cntone) if(can[i+1][j]) {
//			printf("\t%d ones can[%d][%d]\n",cntone,i,j);
			can[i][j]=true;
			if(j+1<=cntone&&ok[i][cntone-j-1]) can[i][j+1]=true;
		}
		if(!can[0][cntone]) continue;

		{ int j=cntone; REP(i,keylen) if(can[i+1][j]) cur[i]='0'; else { cur[i]='1'; --j; } cur[keylen]='\0'; }

		if(!any||strcmp(cur,best)<0) { any=true; REPE(i,keylen) best[i]=cur[i]; }				
//		printf("can %d ones: %s\n",cntone,cur);
	}
	if(any) printf("%s",best); else printf("0\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}