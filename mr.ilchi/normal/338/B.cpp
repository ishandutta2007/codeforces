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

bool mark[MAXN],col[MAXN];
int n,m,d,ans;
int far1[MAXN],far2[MAXN];
vector <int> adj[MAXN];

inline void dfs (int v){
	mark[v] = true;
	far1[v] = col[v] ? 0 : -1;
	far2[v] = -1;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp]){
			dfs(temp);
			if (far1[temp]!=-1){
				if (far1[v] < far1[temp]+1){
					swap(far1[v],far2[v]);
					far1[v] = far1[temp] + 1;
				}else
					far2[v] = max(far2[v], far1[temp]+1);
			}
		}
	}
}

inline void go (int v, int x){
	ans+= (max(far1[v], x)<=d);
	mark[v] = true;
	if (x!=-1) x++;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp]){
			if (far1[temp]!=-1 && far1[v] == far1[temp]+1)
				go(temp, max(x, (far2[v]==-1 ? -1 : (far2[v]+1))));
			else
				go(temp, max(x, (far1[v]==-1 ? -1 : (far1[v]+1))));
		}
	}
}

int main(){
	cin >> n >> m >> d;
	for (int i=0; i<m; i++){
		int temp; cin >> temp;
		col[temp-1] = true;
	}
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	dfs(0);
	memset(mark,false,sizeof mark);
	go (0, -1);
	cout << ans << endl;
	return 0;
}