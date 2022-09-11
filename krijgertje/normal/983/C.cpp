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

const int MAXN=2000;
const int MAXSTATE=715;
const int MAXFLOOR=8;

int nstate;
map<vector<int>,int> mp;
vector<vector<int> > states;

int out[MAXSTATE][MAXFLOOR+1];
int in[MAXSTATE][MAXFLOOR+1];

void genstates(vector<int> state) {
	sort(state.begin(),state.end()); if(mp.count(state)) return;
	mp[state]=nstate++; states.PB(state);
	if(SZ(state)==4) return;
	REPE(i,MAXFLOOR) { state.PB(i); genstates(state); state.pop_back(); }
}

int n;
int a[MAXN],b[MAXN];
int dp[MAXN+1][MAXFLOOR+1][MAXSTATE];

int q[(MAXN+1)*(MAXFLOOR+1)*MAXSTATE],qhead,qtail;

void enqueue(int i,int j,int k,int val) {
	if(dp[i][j][k]!=INT_MAX) return;
	dp[i][j][k]=val;
	q[qhead++]=(i*(MAXFLOOR+1)+j)*nstate+k;
}
bool dequeue(int &i,int &j,int &k) {
	if(qtail>=qhead) return false;
	int x=q[qtail++]; k=x%nstate; x/=nstate; j=x%(MAXFLOOR+1); x/=MAXFLOOR+1; i=x;
	return true;
}

void run() {
	nstate=0; genstates(vector<int>());
	REP(i,nstate) REPE(j,MAXFLOOR) { vector<int> cur=states[i]; bool found=false; REPSZ(k,cur) if(cur[k]==j) { cur.erase(cur.begin()+k); found=true; break; } out[i][j]=found?mp[cur]:-1; }
	REP(i,nstate) REPE(j,MAXFLOOR) { vector<int> cur=states[i]; bool ok=SZ(cur)<4; if(ok) { cur.PB(j); sort(cur.begin(),cur.end()); } in[i][j]=ok?mp[cur]:-1; }

	scanf("%d",&n); REP(i,n) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];

	REPE(i,n) REPE(j,MAXFLOOR) REP(k,nstate) dp[i][j][k]=INT_MAX; qhead=qtail=0;
	//printf("%dmb\n",sizeof(dp)/1024/1024);
	enqueue(0,0,0,0);
	while(true) {
		int i,j,k; if(!dequeue(i,j,k)) break;
		//printf("%d %d %d = %d\n",i,j,k,dp[i][j][k]);
		if(j-1>=0) enqueue(i,j-1,k,dp[i][j][k]+1);
		if(j+1<=MAXFLOOR) enqueue(i,j+1,k,dp[i][j][k]+1);
		if(out[k][j]!=-1) enqueue(i,j,out[k][j],dp[i][j][k]+1);
		if(i<n&&a[i]==j&&in[k][b[i]]!=-1) enqueue(i+1,j,in[k][b[i]],dp[i][j][k]+1);
	}
	int ret=INT_MAX; REPE(j,MAXFLOOR) ret=min(ret,dp[n][j][0]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}