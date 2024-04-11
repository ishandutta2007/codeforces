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

const int MAXN=1000;
const int NSTATE=625;

int nstates;
vector<vector<int> > states;
map<int,int> mp;
int encode(int a,int b,int c,int d) { return a*5*5*5+b*5*5+c*5+d; }
void decode(int x,int &a,int &b,int &c,int &d) { a=states[x][0],b=states[x][1],c=states[x][2],d=states[x][3]; }


int n;
int cost[5];
char g[4][MAXN+1];

int dp[MAXN+1][NSTATE];

void run() {
	nstates=0; mp.clear(); states.clear(); REPE(a,4) REPE(b,4) REPE(c,4) REPE(d,4) { mp[encode(a,b,c,d)]=nstates++; vector<int> s(4); s[0]=a,s[1]=b,s[2]=c,s[3]=d; states.PB(s); } assert(nstates==NSTATE);
	scanf("%d",&n); FORE(i,1,4) scanf("%d",&cost[i]); REP(i,4) scanf("%s",g[i]);

	REPE(i,n) REP(j,NSTATE) dp[i][j]=INT_MAX; dp[0][mp[encode(0,0,0,0)]]=0;
	REP(i,n) REP(j,NSTATE) if(dp[i][j]!=INT_MAX) {
		int s[4]; decode(j,s[0],s[1],s[2],s[3]);
		//printf("%d: %d %d %d %d = %d\n",i,s[0],s[1],s[2],s[3],dp[i][j]);
		{
			int ns[4]; ns[0]=s[0],ns[1]=s[1],ns[2]=s[2],ns[3]=s[3]; int ni=i;
			bool ok=true; REP(k,4) if(ns[k]==0&&g[k][i]=='*') ok=false;
			if(ok) {
				REP(k,4) ns[k]=max(0,ns[k]-1); int ni=i+1,nj=mp[encode(ns[0],ns[1],ns[2],ns[3])];
				dp[ni][nj]=min(dp[ni][nj],dp[i][j]);
			}
		}
		FORE(sz,1,4) if(i+sz<=n) REPE(row,4-sz) {
			int ns[4]; ns[0]=s[0],ns[1]=s[1],ns[2]=s[2],ns[3]=s[3]; int ni=i;
			REP(k,sz) ns[row+k]=max(ns[row+k],sz);
			int nj=mp[encode(ns[0],ns[1],ns[2],ns[3])];
			//if(s[0]==0&&s[1]==1&&s[2]==1&&s[3]==1&&sz==1&&row==0) printf("here i=%d dp=%d -> ni=%d nj=%d (%d %d %d %d)\n",i,dp[i][j],ni,nj,ns[0],ns[1],ns[2],ns[3]);
			dp[ni][nj]=min(dp[ni][nj],dp[i][j]+cost[sz]);
		}
	}
	printf("%d\n",dp[n][mp[encode(0,0,0,0)]]);
}

int main() {
	run();
	return 0;
}