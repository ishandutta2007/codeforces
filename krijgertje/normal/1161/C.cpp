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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=50;

int n;
int a[MAXN];

bool solve() {
	sort(a,a+n);
	int low=a[0],lowcnt=0; REP(i,n) if(a[i]==low) ++lowcnt;
	return lowcnt<=n/2;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"Alice":"Bob");
}

const int N=8;
const int LIM=6;

vector<vector<int>> states;
map<vector<int>,int> mp;
vector<int> dp;

void genstates(vector<int> &state) {
	if(SZ(state)==N) { int id=SZ(states); states.PB(state); mp[state]=id; return; }
	FORE(i,SZ(state)==0?0:state[SZ(state)-1],LIM) {
		state.PB(i);
		genstates(state);
		state.pop_back();
	}
}

bool win(int at);
bool winmove(vector<int> &state,int idx,int rem) {
	if(idx==SZ(state)) { if(rem!=0) return false; vector<int> tmp=state; sort(tmp.begin(),tmp.end()); auto it=mp.find(tmp); assert(it!=mp.end()); int to=it->second; return !win(to); }
	if(winmove(state,idx+1,rem)) return true;
	if(rem==0) return false;
	int old=state[idx];
	for(state[idx]=0;state[idx]<old;++state[idx]) {
		if(winmove(state,idx+1,rem-1)) { state[idx]=old; return true; }
	}
	state[idx]=old; return false;
}

bool win(int at) {
	if(dp[at]!=-1) return dp[at]==1;
	//printf("calc win(%d)\n",at);
	dp[at]=winmove(states[at],0,N/2)?1:0;
	//printf("calc win(%d)=%d\n",at,dp[at]);
	return dp[at]==1;
}

void research() {
	states.clear();
	mp.clear();
	vector<int> state; genstates(state);
	printf("%d\n",SZ(states));
	dp=vector<int>(SZ(states),-1);
	REPSZ(i,states) {
		bool want=win(i);
		n=N; REP(j,N) a[j]=states[i][j];
		bool have=solve();
		if(!win(i)||have!=want) { printf("%s:",have!=want?want?"shouldwin":"shouldlose":"lose"); REPSZ(j,states[i]) printf( "%d",states[i][j]); puts(""); }
		assert(have==want);
	}
}

int main() {
	run();
	//research();
	return 0;
}