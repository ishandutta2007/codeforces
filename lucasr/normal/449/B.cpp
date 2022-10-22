#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define MAXN 100000

long long dist[MAXN];
bool wasByTrain[MAXN];

int main() {
	int n, m, k, a, b, cost;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int> > > adj(n);
	vector<pair<int, int> > trains(k);
	for (int i=0;i<m;i++) {
		scanf("%d %d %d", &a, &b, &cost);
		a--; b--;
		adj[a].push_back(make_pair(b, cost));
		adj[b].push_back(make_pair(a, cost));
	}
	for (int i=0;i<k;i++) {
		scanf("%d %d", &a, &cost);
		a--;
		trains.push_back(make_pair(a,cost));
	}
	memset(dist, 0x3f, sizeof(dist));
	memset(wasByTrain, 0, sizeof(wasByTrain));
	set<pair<long long, int> > bestDists;
	bestDists.insert(make_pair(0ll,0));
	dist[0] = 0;
	while (!bestDists.empty()) {
		pair<int, int> cu = *bestDists.begin();
		bestDists.erase(bestDists.begin());
		if (dist[cu.second] < cu.first) continue;
		int nodo = cu.second;
		for (int i=0;i<adj[nodo].size();i++) {
			int v=adj[nodo][i].first;
			long long c=adj[nodo][i].second;
			if (dist[v] >= dist[nodo] + c) {
				dist[v] = dist[nodo] + c;
				bestDists.insert(make_pair(dist[v], v));
				if (wasByTrain[v]) {
					wasByTrain[v]=false;
				}
			}
		}
		if (nodo == 0) {
			for (int i=0;i<trains.size();i++) {
				int v=trains[i].first;
				long long c=trains[i].second;
				if (dist[v] > dist[nodo] + c) {
					dist[v] = dist[nodo] + c;
					bestDists.insert(make_pair(dist[v], v));
					if (!wasByTrain[v]) {
						wasByTrain[v]=true;
					}
				}
			}
		}
	}
	int ans = k;
	for (int i=0;i<n;i++) if (wasByTrain[i]) ans--;
	printf("%d\n", ans);
	
	return 0;
}