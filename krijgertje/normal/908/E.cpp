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

const int MAXLEN=1000;
const int MOD=1000000007;

int len,n;
char s[MAXLEN+1];

int cnt;
char A[MAXLEN][MAXLEN+1];
int who[MAXLEN];
vector<int> pos[MAXLEN];
bool done[MAXLEN];


int C[MAXLEN+1][MAXLEN+1];
int bell[MAXLEN+1];


void run() {
	REPE(i,MAXLEN) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	bell[0]=1; FORE(i,1,MAXLEN) { bell[i]=0; REPE(j,i-1) bell[i]=(bell[i]+(ll)C[i-1][j]*bell[j])%MOD; }

	scanf("%d%d",&len,&n);
	cnt=0; REP(j,len) A[cnt][j]='1'; A[cnt][len]='\0'; ++cnt; REP(j,len) who[j]=0,pos[0].PB(j);
	REP(i,n) {
		scanf("%s",s);
		REP(j,cnt) done[j]=false;
		REP(j,len) if(s[j]=='1'&&!done[who[j]]) {
			done[who[j]]=true;
			int r=who[j]; bool all=true;
			REPSZ(k,pos[r]) { int c=pos[r][k]; if(s[c]!='1') all=false; }
			if(all) continue;
			REP(c,len) A[cnt][c]='0'; A[cnt][len]='\0';
			vector<int> npos; REPSZ(k,pos[r]) { int c=pos[r][k]; if(s[c]==s[pos[r][0]]) { npos.PB(c); continue; } A[r][c]='0'; A[cnt][c]='1'; who[c]=cnt; pos[cnt].PB(c); } pos[r]=npos; done[cnt]=true; ++cnt;
		}
	}
	//REP(i,cnt) printf("%s %d\n",A[i],SZ(pos[i]));
	int ret=1; REP(i,cnt) ret=(ll)ret*bell[SZ(pos[i])]%MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}