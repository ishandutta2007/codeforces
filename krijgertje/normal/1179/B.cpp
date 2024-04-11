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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int h,w;
vector<pair<int,int>> ans;

void solve() {
	ans.clear();
	ans.PB(MP(0,0));
	int toprow=0,botrow=h-1;
	while(toprow<botrow) {
		assert(ans.back()==MP(toprow,0));
		REP(i,w) {
			ans.PB(MP(botrow,w-i-1));
			if(i!=w-1) ans.PB(MP(toprow,i+1)); else if(toprow+1<botrow) ans.PB(MP(toprow+1,0));
		}
		++toprow,--botrow;
	}
	if(toprow==botrow) {
		REP(i,w-1) if(i%2==0) ans.PB(MP(toprow,w-i/2-1)); else ans.PB(MP(toprow,i/2+1));
	}
}

void verify() {
	vector<vector<bool>> been(h,vector<bool>(w,false));
	vector<vector<bool>> seen(2*h-1,vector<bool>(2*w-1,false));
	REPSZ(i,ans) {
		int x=ans[i].first,y=ans[i].second;
		assert(0<=x&&x<h); assert(0<=y&&y<w); assert(!been[x][y]); been[x][y]=true;
		if(i-1>=0) {
			int px=ans[i-1].first,py=ans[i-1].second,dx=x-px,dy=y-py; assert(-(h-1)<=dx&&dx<=+(h-1)); assert(-(w-1)<=dy&&dy<=+(w-1));
			assert(!seen[dx+h-1][dy+w-1]); seen[dx+h-1][dy+w-1]=true;
		}
	}
	REP(x,h) REP(y,w) assert(been[x][y]);
}

void run() {
	scanf("%d%d",&h,&w);
	solve();
	verify();
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

void stress() {
	for(h=1;h<=100;++h) for(w=1;w<=100;++w) {
		solve();
		verify();
	}
}

int main() {
	run();
	//stress();
	return 0;
}