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
const int MAXN=1000;

char s[MAXLEN+1]; int slen;
int n;
char v[MAXN][MAXLEN+1]; int vlen[MAXN];
int c[10];

int p[MAXLEN+2][MAXN]; // p[i][j] = the jth value that will get a carry in the ith position
int dp[MAXLEN+2][MAXN+1]; // dp[i][j] = maximum cost of digits in the first i positions when there are j numbers that get a value in the ith position
bool havecarry[MAXN];

inline int getdig(int idx,int pos) { int ret=pos>=vlen[idx]?0:v[idx][pos]-'0'; return ret; }
void run() {
	scanf("%s",s); slen=strlen(s); reverse(s,s+slen);
	scanf("%d",&n);
	REP(i,n) { scanf("%s",v[i]); vlen[i]=strlen(v[i]); reverse(v[i],v[i]+vlen[i]); }
	REP(i,10) scanf("%d",&c[i]);

	REP(i,n) p[0][i]=i;
	REPE(i,MAXLEN) {
		static pair<int,int> lst[MAXN];
		REP(j,n) lst[j]=MP(n*(9-getdig(p[i][j],i))+j,p[i][j]);
		sort(lst,lst+n);
		REP(j,n) p[i+1][j]=lst[j].second;
	}
	//FORE(i,1,5) { printf("%d:",i); REP(j,n) printf(" %d",p[i][j]); puts(""); }

	REPE(i,MAXLEN+1) REPE(j,MAXN) dp[i][j]=-1; dp[0][0]=0;
	REPE(i,MAXLEN) {
		REP(k,10) {
			if(i>=slen&&k!=0) continue;
			if(i<slen&&s[i]!='?'&&s[i]!='0'+k) continue;
			if(i==slen-1&&k==0) continue;
			int nj=0;
			REPE(j,n) havecarry[j]=false;
			int sum=0; REP(j,n) if(i<slen||i<vlen[j]) sum+=c[(getdig(j,i)+k)%10];
			REPE(j,n) {
				//if(i+1<=5) printf("i=%d k=%d j=%d -> sum=%d\n",i,k,j,sum);
				if(dp[i][j]!=-1) {
					while(nj<n&&getdig(p[i+1][nj],i)+k+havecarry[p[i+1][nj]]>=10) ++nj;
					//if(i+1<=5) printf("-> nj=%d\n",i,nj);
					if(dp[i][j]+sum>dp[i+1][nj]) dp[i+1][nj]=dp[i][j]+sum;
				}
				if(j<n) {
					havecarry[p[i][j]]=true; 
					sum+=c[(getdig(p[i][j],i)+k+1)%10]; 
					if(i<slen||i<vlen[p[i][j]]) sum-=c[(getdig(p[i][j],i)+k)%10];
				}
			}
		}
		//if(i+1<=5) { printf("%d:",i+1); REPE(j,n) if(dp[i+1][j]!=-1) printf( "%d=%d",j,dp[i+1][j]); puts(""); }
	}
	int ret=dp[MAXLEN+1][0]; printf("%d\n",ret);








}

int main() {
	run();
	return 0;
}