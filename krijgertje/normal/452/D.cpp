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

int need;
int cnt[3],t[3];

void run() {
	scanf("%d",&need);
	REP(i,3) scanf("%d",&cnt[i]); REP(i,3) scanf("%d",&t[i]);
	int at=0,ret=0;
	priority_queue<pair<int,pair<int,int> > > q;
	while(need>0||!q.empty()) {
		int now=min(min(need,cnt[0]),min(cnt[1],cnt[2]));
		//printf("%d: %d %d %d %d [%d]\n",at,need,cnt[0],cnt[1],cnt[2],SZ(q));
		if(now>0) {
			cnt[0]-=now; cnt[1]-=now; cnt[2]-=now; need-=now;
			q.push(MP(-at-t[0],MP(0,now)));
			q.push(MP(-at-t[1],MP(1,now)));
			q.push(MP(-at-t[2],MP(2,now)));
			ret=at+t[0]+t[1]+t[2];
		}
		at=-q.top().first;
		while(!q.empty()&&-q.top().first==at) {
			cnt[q.top().second.first]+=q.top().second.second;
			q.pop();
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}