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
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100*1000 + 5;

bool mark[maxN];
int n;
ll jam[maxN] , par[maxN] , siz[maxN] , cost[maxN];
vector <int> adj[maxN] , wei[maxN] , child[maxN];

inline bool cmp (const int &a1 , const int &a2){
	
	return (ll)jam[a1] * (ll)siz[a2] < (ll)jam[a2] * (ll)siz[a1];
}

inline void solve (int v){
	
	mark[v] = true;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			child[v].push_back (tmp);
			par[tmp] = wei[v][i];
			solve (tmp);
			siz[v]+= siz[tmp];
			jam[v]+= 2 * par[tmp] + jam[tmp];
		}
	}

	siz[v]++;

	for (int i=0; i<(int)child[v].size(); i++)
		jam[child[v][i]]+= 2 * par[child[v][i]];

	sort (child[v].begin() , child[v].end() , cmp);

	ll sum=0;

	for (int i=0; i<(int)child[v].size(); i++){
		int tmp = child[v][i];
		cost[v]+= (sum + par[tmp]) * siz[tmp] + cost[tmp];
		sum+= jam[tmp];
	}
}

int main(){
	
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i=1; i<n; i++){
		int x,y,w; 
		cin >> x >> y >> w;
		adj[x].push_back (y);
		adj[y].push_back (x);
		wei[x].push_back (w);
		wei[y].push_back (w);
	}

	solve (1);

	ll tot=0;

	for (int i=0; i<(int)child[1].size(); i++)
		tot+= jam[child[1][i]];

	ll sum=0 , tedad=0 , res=-1;

	for (int i=0; i<(int)child[1].size(); i++){
		
		int tmp = child[1][i];

		ll p = cost[1] - siz[tmp] * (sum + par[tmp]) - cost[tmp];

		p-= jam[tmp] * (n-1-tedad-siz[tmp]);

		p+= cost[tmp] + (tot-jam[tmp] + par[tmp]) * siz[tmp];

		if (res==-1 || p<res)
			res = p;

		sum+= jam[tmp];
		tedad+= siz[tmp];
	}
	
	long double ans = (long double)res / ((long double)n-1);

	cout << fixed << setprecision (10) << ans << endl;

	return 0;
}