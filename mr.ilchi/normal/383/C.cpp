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
typedef pair<int,int> pii;
typedef complex<double> point;

bool mark[1<<20];
int n,que,ttime;
int a[1<<20];
int lo[1<<20],hi[1<<20],hei[1<<20];
int all[1<<20][2];
vector <int> adj[1<<20];

inline void dfs (int v, int h){
	lo[v] = ttime++;
	hei[v] = h;
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
		dfs(adj[v][i], h+1);
	hi[v] = ttime-1;
}

inline void go (int root, int lo, int hi, int L, int R, int val, int f){
	if (hi<L || R<lo)
		return;
	if (L<=lo && hi<=R){
		all[root][f]+= val;
		all[root][1-f]-= val;
		return;
	}
	int mid = (lo + hi) / 2;
	go(root*2, lo, mid, L, R, val, f);
	go(root*2+1, mid+1,hi,L,R,val, f);
}

inline int get (int root, int lo, int hi, int pos, int f){
	if (lo == hi)
		return all[root][f];
	int mid = (lo + hi) / 2;
	if (pos <= mid)
		return all[root][f] + get(root*2, lo, mid, pos, f);
	else
		return all[root][f] + get(root*2+1, mid+1, hi, pos, f);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=0; i<n; i++)
		cin >> a[i];	
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	dfs(0, 0);
	for (int i=0; i<n; i++)
		go(1, 0, n-1, lo[i], lo[i], a[i], hei[i]%2);
	for (int i=0; i<que; i++){
		int type; cin >> type;
		if (type == 1){
			int x,val; cin >> x >> val;
			x--;
			go(1, 0, n-1, lo[x], hi[x], val, hei[x]%2);
		}else{
			int x; cin >> x;
			x--;
			cout << get(1, 0, n-1, lo[x], hei[x]%2) << endl;
		}
	}
	return 0;
}