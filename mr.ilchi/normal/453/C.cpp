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

const int MAXN = 100000 + 10;

bool mark[MAXN];
int n,e;
int f[MAXN];
vector <int> Q;
vector <int> adj[MAXN];

void dfs (int v){
	mark[v] = true;
	Q.push_back(v);
	f[v] = 1 - f[v];
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			dfs(tmp);
			Q.push_back(v);
			f[v] = 1 - f[v];
			if (f[tmp]){
				Q.push_back(tmp);
				Q.push_back(v);
				f[tmp] = 1 - f[tmp];
				f[v] = 1 - f[v];
			}
		}
	}
}

int main(){
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	for (int i=0; i<n; i++)
		cin >> f[i];
	if (count(f, f+n, 1) == 0){
		cout << 0 << endl;
	}else{
		for (int i=0; i<n; i++) if (f[i] == 1){
			dfs(i);
			if (f[i] == 1){
				Q.push_back(adj[i][0]);
				Q.push_back(i);
				Q.push_back(adj[i][0]);
				f[i] = 0;
			}
			break;
		}
		for (int i=0; i<n; i++) if (f[i]){
			cout << -1 << endl;
			return 0;
		}
		cout << Q.size() << endl;
		for (int i=0; i<Q.size(); i++)
			cout << Q[i]+1 << ' ';
		cout << endl;
	}
	return 0;
}