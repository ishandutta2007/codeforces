/*
 * in the name of god
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
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 100 * 1000 + 10;

bool mark[maxN];
int n,e,n0,n1,k;
int ans[maxN];
set <pii> sit;
vector <int> Q[2];
vector <int> adj[maxN];

void dfs (int v, bool col){
	mark[v] = true;
	Q[col].push_back(v);
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			dfs (tmp,!col);
	}		
}

void go (vector <int> Q){
	int past=0;
	for (int i=0; i<(int)Q.size(); i++) if (ans[Q[i]]==0){
		ans[Q[i]] = k; past++;
		if (past==3){
			k--; past=0;
		}
	}
}

int main(){

	cin >> n >> e;

	k = n/3;

	for (int i=1; i<=e; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		sit.insert(pii(x,y));
		sit.insert(pii(y,x));
	}

	for (int i=1; i<=n; i++) if (!mark[i])
		dfs (i,0);

	n0 = (int)Q[0].size();
	n1 = (int)Q[1].size();

	if (n0%3!=0){
		if (n0%3==2){
			swap(Q[0],Q[1]);
			swap(n0,n1);
		}
		bool f = false;
		for (int i=0; i<(int)Q[0].size(); i++){
			int v = Q[0][i];
			if ((int)adj[v].size()+2>n1)
				continue;
			f = true;
			ans[v] = k;
			int need = 2;
			for (int j=0; j<(int)Q[1].size() && need; j++) if (sit.find(pii(v,Q[1][j]))==sit.end()){
				ans[Q[1][j]] = k;
				need--;
			}
			k--;
			break;
		}
		if (!f){
			int Count=2;
			for (int i=0; i<(int)Q[1].size() && Count; i++){
				int v= Q[1][i];
				if (adj[v].size()+2>n0)
					continue;
				Count--;
				ans[v] = k;
				int need = 2;
				for (int j=0; j<(int)Q[0].size() && need; j++) if (sit.find(pii(v,Q[0][j]))==sit.end()){
					ans[Q[0][j]] = k;
					need--;
				}
				k--;
			}
			if (Count==0)
				f = true;
		}

		if (!f){
			cout << "NO" << endl;
			return 0;
		}
	}

	go(Q[0]); go(Q[1]);
	
	cout << "YES" << endl;
	for (int i=1; i<=n; i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}