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
const LL CONST = 314000000LL;
const LL inf = (1LL<<60);

bool mark[MAXN],INF[MAXN],bad[MAXN];
int m,n,cntComp;
LL cnt[MAXN],func[MAXN],deg[MAXN],comp[MAXN],type[MAXN],len[MAXN];
LL mini[MAXN],maxi[MAXN];
vector <int> topol;
vector <int> adj[MAXN],bak[MAXN],Q[MAXN];

struct cmp{
	inline bool operator () (const int &A, const int &B){
		return (mini[A] != mini[B]) ? (mini[A] < mini[B]) : (A<B); 
	}
};

inline void dfs (int v){
	if (mini[v] == inf)
		return;
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]] && mini[adj[v][i]]!=inf)
		dfs(adj[v][i]);
	topol.push_back(v);
}	

inline void DFS (int v){
	if (mini[v] == inf)
		return;
	mark[v] = true;
	comp[v] = cntComp;
	for (int i=0; i<(int)bak[v].size(); i++) if (!mark[bak[v][i]] && mini[bak[v][i]]!=inf)
		DFS(bak[v][i]);
}

inline bool cmp2 (const int &A, const int &B){
	return comp[type[A]] > comp[type[B]];
}

int main(){
	cin >> m >> n;
	for (int i=0; i<m; i++){
		cin >> type[i] >> len[i];
		type[i]--;
		for (int j=0; j<len[i]; j++){
			int temp; cin >> temp; 
			if (temp == -1)
				deg[i]++, func[i]++;
			else{
				temp--;
				Q[i].push_back(temp);
				bak[temp].push_back(i);
				cnt[i]++;
			}
		}
	}
	for (int i=0; i<n; i++)
		mini[i] = inf;
	set <int, cmp> SET;
	for (int i=0; i<m; i++) if (cnt[i] == 0){
		if (deg[i] < mini[type[i]]){
			SET.erase (type[i]);
			mini[type[i]] = deg[i]; 
			SET.insert(type[i]);
		}
	}
	while (!SET.empty()){
		int begin = *SET.begin(); SET.erase(SET.begin());
		for (int i=0; i<(int)bak[begin].size(); i++){
			int temp = bak[begin][i];
			cnt[temp]--;
			deg[temp] = min(CONST, deg[temp] + mini[begin]);
			if (cnt[temp] == 0){
				if (deg[temp] < mini[type[temp]]){
					SET.erase (type[temp]);
					mini[type[temp]] = deg[temp];
					SET.insert(type[temp]);
				}
			}
		}
	}
	for (int i=0; i<n; i++)
		adj[i].clear(), bak[i].clear();
	for (int i=0; i<m; i++) if (mini[type[i]] != inf){
		bad[i] = false;
		for (int j=0; j<(int)Q[i].size(); j++) if (mini[Q[i][j]] == inf)
			bad[i] = true;
		if (!bad[i]){
			for (int j=0; j<(int)Q[i].size(); j++){
				adj[type[i]].push_back(Q[i][j]);
				bak[Q[i][j]].push_back(type[i]);
			}
		}
	}
	for (int i=0; i<n; i++) if (!mark[i])
		dfs(i);
	memset(mark,false,sizeof mark);
	for (int i=(int)topol.size()-1; i>=0; i--) if (!mark[topol[i]]){
		cntComp++;
		DFS(topol[i]);
	}
	vector <int> perm;
	for (int i=0; i<m; i++)
		perm.push_back(i);
	sort(perm.begin(), perm.end(), cmp2);
	for (int o=0; o<m; o++) if (!bad[perm[o]]){
		int index = perm[o];
		LL sum = min(CONST, func[index]); 
		for (int j=0; j<(int)Q[index].size(); j++){
			int temp = Q[index][j];
			if (comp[temp] == comp[type[index]])
				INF[comp[type[index]]] = true;
			else if (INF[comp[temp]])
				INF[comp[type[index]]] = true;
			else
				sum = min(CONST, sum + maxi[temp]);
		}
		maxi[type[index]] = max(maxi[type[index]], sum);
	}	
	for (int i=0; i<n; i++){
		if (mini[i] == inf){
			cout << -1 << ' ' << -1 << endl;
			continue;
		}
		cout << min(CONST, mini[i]) << ' ' ;
		if (INF[comp[i]])
			cout << -2 << endl;
		else
			cout << min(CONST, maxi[i]) << endl;
	}
	return 0; 
}