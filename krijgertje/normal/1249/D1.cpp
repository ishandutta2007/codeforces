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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=200000;

int n,lim;
int l[MAXN],r[MAXN];
vector<int> ans;

int state[MAXN];
pair<int,int> e[2*MAXN]; int ne;
priority_queue<pair<int,int>> pq;

void solve() {
	ne=0; REP(i,n) e[ne++]=MP(2*l[i]+0,i),e[ne++]=MP(2*r[i]+1,i);
	sort(e,e+ne);
	pq=priority_queue<pair<int,int>>();
	REP(i,n) state[i]=0;
	int qcnt=0;
	ans.clear();
	REP(i,ne) {
		int x=e[i].first/2,kind=e[i].first%2,idx=e[i].second;
		if(kind==0) {
			state[idx]=1;
			pq.push(MP(r[idx],-idx));
			++qcnt;
			while(qcnt>lim) {
				int at=-pq.top().second; pq.pop();
				if(state[at]==2) continue;
				assert(state[at]==1);
				state[at]=2; --qcnt; ans.PB(at);
			}
		} else {
			if(state[idx]==1) {
				state[idx]=2;
				--qcnt;
			}
		}
	}
	sort(ans.begin(),ans.end());
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}