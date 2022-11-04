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
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

const int maxN = 1000*1000 + 5;

bool mark[maxN];
int n,cnt,goal;
int match[maxN],par[maxN];
string name[maxN];
vector <int> adj[maxN];
map <string , int> mip;

inline void go (string cur , int now , int len , string &s , int ind){

	if (now==(int)s.size()){

		if ((int)cur.size() != len)
			return;

		if (mip.find(cur)!=mip.end()){
			adj[ind].push_back (mip[cur]);
			adj[mip[cur]].push_back (ind);
		}
		else{
			cnt++; mip[cur] = cnt;
			adj[ind].push_back (cnt);
			adj[cnt].push_back (ind);
			name[cnt] = cur;
		}
		return;
	}

	if (len == (int)cur.size()){
		go (cur , (int)s.size() , len , s , ind);
		return;
	}

	go (cur , now+1 , len , s , ind);
	go (cur + s[now] , now+1 , len , s, ind);
}

inline void dfs (int x){
	
	mark[x] = true;

	for (int i=0; i<(int)adj[x].size() && goal==-1; i++){
	
		int tmp = adj[x][i];

		if (mark[tmp])
			continue;

		mark[tmp] = true;

		par[tmp] = x;
		
		if (!match[tmp]){
			goal = tmp;
			return;
		}

		if (!mark[match[tmp]]){
			par[match[tmp]] = tmp;
			dfs (match[tmp]);
		}
	}
}

inline void matching(){

	while (true){

		goal = -1;

		memset (mark , false, sizeof mark);

		for (int i=1; i<=n; i++) if (!mark[i] && !match[i]){

			par[i] = -1;
			dfs (i);
			if (goal!=-1)
				break;
		}


		if (goal==-1)
			return;

		while (goal!=-1){
			int P = par[goal];
			match[P] = goal;
			match[goal] = P;

			goal = par[P];
		}
	}
}

int main(){

	freopen ("input.txt" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);

	cin >> n;

	cnt = n+1;

	for (int i=1; i<=n; i++){
		
		string s; cin >> s;

		for (int j=1; j<=4; j++) if (j<=(int)s.size())
			go ("",0,j,s,i);

		sort (adj[i].begin() , adj[i].end());

		adj[i].resize (unique(adj[i].begin(),adj[i].end())-adj[i].begin());
	}

	matching ();

	for (int i=1; i<=n; i++) if (!match[i]){
		cout << -1 << endl;
		return 0;
	}

	for (int i=1; i<=n; i++)
		cout << name[match[i]] << endl;

	return 0;
}