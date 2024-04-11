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

int n,N,L,W,codeN,codeM;
int fen[1<<20],mark[1<<20],sz[1<<20],num[1<<20];
vector <int> adj[1<<20], cost[1<<20], comp[1<<20];
vector <pii> store[1<<20];

inline void add (int pos, int key) { for (int i=pos+1; i<=N; i+=(i&(-i))) fen[i]+=key; }
inline int get (int pos) { int ret = 0; for (int i=pos+1; i>0; i-=(i&(-i))) ret+= fen[i]; return ret; }

inline int findCenter (int v){
	mark[v]=codeM, sz[v]=1;
	int maxi = 0;
	for (int i=0; i<(int)adj[v].size(); i++) if (mark[adj[v][i]]!=codeM && num[adj[v][i]]==codeN){
		int temp = findCenter(adj[v][i]);
		if (temp!=-1)
			return temp;
		maxi = max(maxi, sz[adj[v][i]]);
		sz[v]+= sz[adj[v][i]];
	}	
	maxi = max(maxi, n-sz[v]);
	if (maxi <= n/2)
		return v;
	return -1;
}

inline int divide (int v, int index, int len, int wei, bool root = false){
	mark[v] = codeM;
	if (!root){
		comp [index].push_back(v);
		store[index].push_back(pii(wei, len));
	}
	for (int i=0; i<(int)adj[v].size(); i++) if (mark[adj[v][i]]!=codeM && num[adj[v][i]]==codeN){
		if (root){
			comp[index].clear();
			store[index].clear();
			divide(adj[v][i], index++, len+1, wei+cost[v][i]);
		}else{
			divide(adj[v][i], index, len+1, wei+cost[v][i]);
		}
	}
	return index;
}

inline LL go (vector <int> Q){
	codeN++; codeM++;
	for (int i=0; i<(int)Q.size(); i++)
		num[Q[i]] = codeN;
	n = (int)Q.size();
	int root = findCenter(Q[0]);
	codeM++;
	int cntC = divide (root, 0, 0, 0, true);
	LL ret = 0;
	vector <pii> all;
	for (int i=0; i<cntC; i++){
		sort(store[i].begin(), store[i].end());
		int poi = -1;
		for (int j=0; j<(int)store[i].size(); j++){
			while (poi!=-1 && store[i][j].first + store[i][poi].first > W)
				add(store[i][poi--].second, -1);
			ret-= get(L-store[i][j].second);
			if (store[i][j].first * 2 <= W){
				add(store[i][j].second, 1);
				poi = j;
			}
			all.push_back(store[i][j]);
		}
		while (poi>=0)
			add(store[i][poi--].second, -1);
	}
	all.push_back(pii(0,0));
	sort(all.begin(), all.end());
	int poi = -1;
	for (int j=0; j<(int)all.size(); j++){
		while (poi!=-1 && all[j].first + all[poi].first > W)
			add(all[poi--].second, -1);
		ret+= get(L-all[j].second);
		if (all[j].first * 2 <= W){
			add(all[j].second, 1);
			poi = j;
		}
	}
	while (poi>=0)
		add(all[poi--].second, -1);
	vector < vector <int> > test;
	for (int i=0; i<cntC; i++)
		test.push_back(comp[i]);
	for (int i=0; i<cntC; i++)
		ret+= go(test[i]);
	return ret;
}

int main(){
	cin >> n >> L >> W;
	N = n;
	for (int i=1; i<n; i++){
		int p, wei;
		cin >> p >> wei;
		p--;
		adj[i].push_back(p);
		adj[p].push_back(i);
		cost[i].push_back(wei);
		cost[p].push_back(wei);
	}
	vector <int> Q;
	for (int i=0; i<n; i++)
		Q.push_back(i);
	cout << go(Q) << endl;
	return 0;
}