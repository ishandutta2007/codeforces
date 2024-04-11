#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint n, m, R;
vector<llint> G[100005];
bool used[100005];
llint id[100005];
set<llint> S;
vector<llint> ivec;

llint nid;
vector<llint> vec;
bool dfs(llint v)
{
	//cout << v << endl;
	vec.push_back(v);
	id[v] = nid++;
	bool found = false;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		if(id[G[v][i]] != -1) continue;
		if(dfs(G[v][i])) return true;
		found = true;
		break;
	}
	
	if(!found){
		//cout << "!" << v << endl;
		vector<llint> idvec;
		for(int i = 0; i < G[v].size(); i++){
			if(used[G[v][i]]) continue;
			idvec.push_back(id[G[v][i]]);
		}
		sort(idvec.begin(), idvec.end());
		
		if(idvec.size() && nid - idvec.front() >= R){
			cout << 2 << endl;
			cout << nid - idvec.front() << endl;
			for(int i = idvec.front(); i < nid; i++) cout << vec[i] << " ";
			cout << endl;
			return true;
		}
		else{
			ivec.push_back(v);
			used[v] = true;
			S.erase(v);
			for(int i = 0; i < G[v].size(); i++){
				if(used[G[v][i]]) continue;
				used[G[v][i]] = true;
				S.erase(G[v][i]);
			}
		}
	}
	id[v] = -1;
	vec.pop_back();
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	rep(i, 0, m){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; ; i++){
		if(i*i >= n){
			R = i;
			break;
		}
	}
	
	Rep(i, 1, n){
		id[i] = -1;
		S.insert(i);
	}
	while(S.size()){
		llint v = *S.begin();
		nid = 0;
		vec.clear();
		if(dfs(v)) return 0;
	}
	
	cout << 1 << endl;
	rep(i, 0, R) cout << ivec[i] << " ";
	cout << endl;
	
	return 0;
}