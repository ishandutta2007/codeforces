#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPSZ(i, v) for (int i = 0; i < (int)(v.size()); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

const int INF = 1000000000;
const int MAXN = 5005;

long long sc[MAXN];
long long sk[MAXN];
long long sp[MAXN];

vector<int> qp;

typedef pair<int, int> pii;

void printMap(const map<long long, long long>& priceToCount) {
	for (map<long long, long long>::const_iterator ii = priceToCount.begin(); ii != priceToCount.end(); ii++) {
		cout << "[" << ii->first << ", " << ii->second << "]; ";
	}
	cout << endl;
}

bool findAnswer(int minTime, long long& currentPrice, long long& currentCount, map<long long, long long>& priceToCount, const long long r, const long long a) {
	REPSZ(ii, qp) {
		int i = qp[ii];
		currentPrice += sp[i] * sk[i];
		currentCount += sk[i];
		priceToCount[sp[i]] += sk[i];

		//cout << "adding shop: " << i << ", p = " << sp[i] << ", k = " << sk[i] << endl; 
		//cout << "  count = " << currentCount << ", cost " << currentPrice << endl;

		//printMap(priceToCount);

		while (currentCount > r) {
			map<long long, long long>::reverse_iterator rit = priceToCount.rbegin();
			long long countRemove = min(rit->second, currentCount - r);
			//cout << "remove key " << rit->first << endl;
			//cout << "removing shop: p = " << rit->first << ", k = " << countRemove << ", ";			

			currentCount -= countRemove;
			currentPrice -= countRemove * rit->first;

			if (countRemove == rit->second) {
				priceToCount.erase(rit->first);
			} else {
				priceToCount[rit->first] -= countRemove;
			}
			//cout << "count = " << currentCount << ", keys  = " << priceToCount.size() << endl;
		}

		//cout << "count = " << currentCount << ", cost " << currentPrice << endl;

		if (currentCount == r && currentPrice <= a) {
			printf("%d\n", minTime);
			return true;
		}
	}	
	return false;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int> > G(n);
	vector<vector<int> > gs(n);
	REP(i, m) {
		int a, b; scanf("%d %d ", &a, &b);
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int w; cin >> w;
	
	REP(i, w) {
		cin >> sc[i] >> sk[i] >> sp[i];
		sc[i]--;
		gs[sc[i]].push_back(i);
	}

	int Q; cin >> Q;
	REP(qw, Q) {
		qp.clear();

		// g - city, r - showels, c - total cost
		int g, r, a; scanf("%d %d %d ", &g, &r, &a);		
		g--;
		
		queue<int> q;
		vector<int> dist(n, INF);
		int l = 0;
		q.push(g);
		dist[g] = 0;

		long long currentPrice = 0;
		long long currentCount = 0;
		map<long long, long long> priceToCount;

		bool found = false;

		while (!q.empty()) {
			int v = q.front(); q.pop();			
			if (dist[v] > l) {
				found = findAnswer(l, currentPrice, currentCount, priceToCount, r, a);
				qp.clear();				
				l = dist[v];
			}
			if (found) break;

			REPSZ(i, gs[v]) qp.push_back(gs[v][i]);

			REPSZ(i, G[v]) {
				int nv = G[v][i];
				if (dist[v] + 1 < dist[nv]) {
					dist[nv] = dist[v] + 1;
					q.push(nv);
				}
			}
		}

		if (!found) { 
			found = findAnswer(l, currentPrice, currentCount, priceToCount, r, a);
			qp.clear();
		}

		if (!found) {
			printf("%d\n", -1);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	solve();
	return 0;
}