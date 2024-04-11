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

bool mark[1<<20];
int n,e;
int ans[1<<20],ent[1<<20];
vector <int> adj[1<<20], ind[1<<20], cost[1<<20];
pii edge[1<<20];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2,w; cin >> e1 >> e2 >> w;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
		ind[e1].push_back(i);
		ind[e2].push_back(i);
		cost[e1].push_back(w);
		cost[e2].push_back(w);
		ent[e1]+= w;
		ent[e2]+= w;
		edge[i] = pii(e1,e2);
	}
	for (int i=1; i<n; i++) 
		ent[i]/=2;
	queue <int> Q;
	Q.push(0);
	mark[0] = true;
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<(int)adj[front].size(); i++){
			int temp = adj[front][i];
			if (mark[temp]) continue;
			ent[temp]-= cost[front][i];
			if (edge[ind[front][i]].first == front)
				ans[ind[front][i]] = 0;
			else
				ans[ind[front][i]] = 1;
			if (ent[temp] == 0 && temp<n-1){
				Q.push(temp);
				mark[temp] = true;
			}
		}
	}
	for (int i=0; i<e; i++)
		cout << ans[i] << endl;
	return 0;
}