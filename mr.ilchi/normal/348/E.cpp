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

bool have[MAXN];
int n,m;
int max1[MAXN],max2[MAXN],lca[MAXN],par[MAXN],val[MAXN];
pii func[MAXN];
vector <int> adj[MAXN],wei[MAXN];

inline void dfs (int v, int p){
	par [v] = p;
	int maxcnt1= 0;
	int maxcnt2= 0;
	int maxpos1=-1;
	int maxpos2=-1;
	max1[v] = -1;
	max2[v] = -1;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (temp != p){
			dfs(temp, v);
			int w = wei[v][i];
			if (max1[temp] != -1){
				if (max1[v] < max1[temp] + w){
					if (max2[v] != max1[v]){
						max2[v] = max1[v]; 
						maxcnt2 = maxcnt1;
					}else
						maxcnt2+= maxcnt1;
					maxpos2 = maxpos1;
					max1[v] = max1[temp] + w;
					maxpos1 = temp;
					maxcnt1 = 0;
				}else if (max2[v] <= max1[temp] + w){
					if (max2[v] == max1[temp] + w)
						maxcnt2++;
					else
						maxcnt2=1;
					max2[v] = max1[temp] + w;
					maxpos2 = temp;
				}
				maxcnt1+= (max1[v] == (max1[temp] + w));
			}
		}
	}
	if (have[v] && max1[v] == -1)
		max1[v] = 0, maxpos1 = v;
	else if (have[v] && max2[v] == -1)
		max2[v] = 0, maxpos2 = v;
	if (max1[v] != -1){
		for (int i=0; i<(int)adj[v].size(); i++){
			int temp = adj[v][i];
			int w = wei[v][i];
			if (temp != par[v]){
				if ((max1[temp]==-1) || ((max1[temp] + w) != max1[v]))
					func[temp] = pii(max1[v] + w, (maxcnt1 == 1) ? (lca[maxpos1]) : (v));
				else{
					if (maxcnt1 > 2)
						func[temp] = pii(max1[v] + w, v);
					else if (maxcnt1 > 1)
						func[temp] = pii(max1[v] + w, lca[maxpos1 + maxpos2 - temp]);
					else
						func[temp] = pii((max2[v]==-1) ? (-1) : (max2[v] + w), (max2[v]==-1) ? (-1) : (maxcnt2==1) ? (lca[maxpos2]) : (v));
				}
			}
		}
	}
	lca[v] = (maxcnt1 != 1) ? (v) : (lca[maxpos1]);
}

inline void go (int v, int maxlen, int maxlca, int root){
	if (have[v]){
//		cout << v+1 << ' ' << maxlen << ' ' << maxlca+1 << ' ' << root+1 << endl;
		if (maxlen < max1[v]){
			val[lca[v]]++;
			if (par[v] != -1)
				val[par[v]]--;
		}else if (maxlen > max1[v]){
			if (root == maxlca){
				val[v]++;
				if (par[root] != -1)
					val[par[root]]--;
			}else{
				val[v]++;
				val[maxlca]++;
				val[root]--;
				if (par[root] != -1)
					val[par[root]]--;
			}
		}
	}
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		int w = wei[v][i];
		if (temp != par[v]){
			int cur = (maxlen == -1) ? (-1) : (maxlen+w);
			if (func[temp].first == cur){
				if (cur == -1)
					go(temp, -1, -1, -1);
				else
					go(temp, cur, v, v);
			}else if (func[temp].first > cur)
				go(temp, func[temp].first, func[temp].second, v);
			else
				go(temp, cur, maxlca, root);
		}
	}
}

inline void dfs2 (int v){
	for (int i=0; i<(int)adj[v].size(); i++) if (adj[v][i] != par[v]){
		dfs2(adj[v][i]);
		val[v]+= val[adj[v][i]];
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; i++){
		int temp; scanf("%d", &temp);
		temp--;
		have[temp] = true;
	}
	for (int i=0; i<n-1; i++){
		int e1,e2,w; scanf("%d%d%d", &e1, &e2, &w);
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
		wei[e1].push_back(w);
		wei[e2].push_back(w);
	}
	for (int i=0; i<n; i++)
		func[i] = pii(-1,-1);
	dfs(0,-1);
	go (0,-1,-1,-1);
	dfs2(0);
//	cerr << "MAX1 " << endl;
//	for (int i=0; i<n; i++)
//		cerr << i+1 << ' ' << max1[i] << ' ' << max2[i] << endl;
//	cerr << "\nFUNC" << endl;
//	for (int i=0; i<n; i++)
//		cerr << i+1 << ' ' << func[i].first << ' ' << func[i].second+1 << endl;
//	for (int i=0; i<n; i++) 
//		for (int j=0; j<(int)adj[i].size(); j++) if (adj[i][j] != par[i])
//			val[i]+= val[adj[i][j]];
	int maxi = 0, maxcnt = 0;
	for (int i=0; i<n; i++) if (!have[i]){
//		cerr << i+1 << ' ' << val[i] << endl;
		if (maxi < val[i])
			maxi = val[i], maxcnt = 0;
		maxcnt+= (maxi == val[i]);
	}
	printf("%d %d\n", maxi, maxcnt);
	return 0;
}