/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100000+10;

bool mark[MAXN],vin[MAXN];
int n,t;
int l[MAXN],r[MAXN],dp[MAXN];
vector <int> adj[MAXN];

struct event{
	int pos,h,type,index;
	event () {}
	event (int pos, int h, int type, int index) : pos(pos), h(h), type(type), index(index) {}
	bool operator < (const event &SEC) const {
		if (pos != SEC.pos)
			return pos < SEC.pos;
		return type < SEC.type;
	}
	
};

vector <event> sweep;
set <pii> edge,SET;

inline int dfs (int v){
	if (mark[v])
		return dp[v];
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		dp[v] = max(dp[v], min(min(r[tmp],r[v])-max(l[tmp],l[v]), dfs(tmp)));
	}
	if (adj[v].empty())
		dp[v] = r[v] - l[v];
	return dp[v];
}

int main(){
	cin >> n >> t;
	for (int i=0; i<n; i++){
		int hei,lo,hi; cin >> hei >> lo >> hi;
		sweep.push_back(event(lo, hei, 1, i));
		sweep.push_back(event(hi, hei,-1, i));
		l[i] = lo, r[i] = hi;
	}
	sort(sweep.begin(), sweep.end());
	set <pii> SET;
	for (int i=0; i<(int)sweep.size(); i++){
		event cur = sweep[i];
		if (cur.type == -1){
			SET.erase (pii(cur.h, cur.index));		
		}else{
			SET.insert(pii(cur.h, cur.index));
			set <pii> :: iterator it = SET.find(pii(cur.h, cur.index));
			set <pii> :: iterator prev = it; prev--; pii xprev = (it!=SET.begin()) ? (*prev) : (pii(-1,-1));
			set <pii> :: iterator next = it; next++; pii xnext = (next!=SET.end()) ? (*next) : (pii(-1,-1));
			if (it != SET.begin() && next != SET.end())
				edge.erase(pii(xprev.second, xnext.second));
			if (it != SET.begin())
				edge.insert(pii(xprev.second, cur.index));
			if (next != SET.end())
				edge.insert(pii(cur.index, xnext.second));
		}
	}
	for (set <pii> :: iterator it = edge.begin(); it != edge.end(); it++){
		adj[it->first].push_back(it->second);
		vin[it->second] = true;
	}
	int ans = 0;
	for (int i=0; i<n; i++) if (vin[i] == 0)
		ans = max(ans, dfs(i));
	cout << ans << endl;
	return 0;
}