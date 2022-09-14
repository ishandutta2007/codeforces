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

int n;
char s[50001];


int last[26][50001];

int best[51][50001]; // best[i][j] == maximum value such that there exists a palindrome part of length i whose first part is <j and last part is >=best[i][j]
bool prv[51][50001];

void print(int i,int j, int k) {
//	printf("printing %d %d %d\n",i,j,k);
	int len=2*i+(k!=-1?1:0);
	char ans[101]; ans[len]='\0'; if(k!=-1) ans[i]=s[k];
	while(j!=0) {
		if(!prv[i][j]) { --j; continue; }
		--i,--j;
		ans[i]=ans[len-i-1]=s[j];
	}
	printf("%s\n",ans);
}

void run(int casenr) {
	scanf("%s",s); n=strlen(s);
//	printf("%s\n",s); //rquwmzexectvnbanemsmdufrg

	memset(last,-1,sizeof(last));
	REP(j,n) { int x=s[j]-'a'; REP(xx,26) last[xx][j+1]=last[xx][j]; last[x][j+1]=j; }

//	REP(j,n) { REP(x,26) printf("%2d",last[x][j]); puts(""); }

	memset(best,-1,sizeof(best));
	best[0][0]=n; prv[0][0]=true;
	REP(i,50) REP(j,n) if(best[i][j]!=-1) {
		// skip s[j]
		if(j+1<=best[i][j]&&best[i][j]>best[i][j+1]) { best[i][j+1]=best[i][j]; prv[i][j+1]=false; }
		// include s[j]
		int x=s[j]-'a';
		if(last[x][best[i][j]]!=-1&&last[x][best[i][j]]>=j+1&&last[x][best[i][j]]>best[i+1][j+1]) { best[i+1][j+1]=last[x][best[i][j]]; prv[i+1][j+1]=true; }
	}

	for(int i=50;i>=0;--i) {
		if(i!=50) REP(j,n) if(best[i][j]!=-1&&j<best[i][j]) { print(i,j,j); return; }
		REP(j,n) if(best[i][j]!=-1) { print(i,j,-1); return; }
	}
	assert(false);
//	REP(i,50) REP(j,n) if(best[i][j]!=-1) { printf("%d %d (%d,%c): ",i,j,best[i][j],prv[i][j]?'V':'.'); print(i,j); }	
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}