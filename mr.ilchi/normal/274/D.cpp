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

const int MAXN = 1<<20;

bool mark[MAXN];
int n,m,cnt;
int perm[MAXN],a[MAXN],index[MAXN];
vector <int> Q;
vector <int> adj[MAXN];

inline bool cmp (const int &A, const int &B){
	return a[A]<a[B];
}

inline void dfs (int v){
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp])
			dfs(temp);
	}
	index[v] = (int)Q.size();
	Q.push_back(v);
}

int main(){
	scanf("%d%d", &n, &m);
	cnt = m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a[j];
			perm[j] = j;
		}
		sort(perm, perm+m, cmp);
		int last = -1;
		for (int j=0; j<m; j++) if (a[perm[j]]!=-1){
			int k = j;
			while (k<m && a[perm[j]]==a[perm[k]]){
				if (last != -1)
					adj[last].push_back(perm[k]);
				adj[perm[k]].push_back(cnt);
				k++;
			}
			j=k-1;
			last = cnt; cnt++;
		}
	}
	for (int i=0; i<cnt; i++) if (!mark[i])
		dfs(i);
	for (int i=0; i<cnt; i++)
		for (int j=0; j<(int)adj[i].size(); j++){
			int temp = adj[i][j];
			if (index[temp] > index[i]){
				cout << -1 << endl;
				return 0;
			}
		}
	for (int i=(int)Q.size()-1; i>=0; i--) if (Q[i]<m)
		cout << Q[i]+1 << ' ';
	cout << endl;
	return 0;
}