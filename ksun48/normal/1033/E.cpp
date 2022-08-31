#include <bits/stdc++.h>
using namespace std;

int n;

int nq = 0;

map<vector<int>, int> q;
int query(vector<int> b1){
	if(b1.size() == 0) return 0;
	if(b1.size() == 1) return 0;
	sort(b1.begin(), b1.end());
	if(q.find(b1) == q.end()){
		assert(b1[0] >= 0 && b1.back() < n);
		for(int i = 0; i + 1 < b1.size(); i++){
			assert(b1[i] != b1[i+1]);
		}
		nq++;
		assert(nq < 19998);
		cout << "? " << b1.size();
		cout << endl;
		for(int i = 0; i < b1.size(); i++){
			cout << b1[i] + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
		int ans = 0;
		cin >> ans;
		q[b1] = ans;
	}
	return q[b1];
}

int get_b(vector<int> b1, vector<int> b2){
	if(b1.size() == 0 || b2.size() == 0) return 0;
	//returns number of edges in bipartition
	int a1 = query(b1);
	int a2 = query(b2);
	vector<int> both = b1;
	for(int x : b2) both.push_back(x);
	return query(both) - a1 - a2;
}

vector<vector<int> > edges;

pair<int,int> find_edge(vector<int> s1, vector<int> s2){
	assert(get_b(s1, s2) > 0);
	assert(s1.size() > 0 && s2.size() > 0);
	for(int q = 0; q < 2; q++){
		while(s1.size() > 1){
			vector<int> t[2];
			for(int i = 0; i < s1.size(); i++){
				t[i & 1].push_back(s1[i]);
			}
			int a = get_b(t[0], s2);
			if(a > 0){
				s1 = t[0];
			} else {
				s1 = t[1];
			}
		}
		swap(s1, s2);
	}
	assert(s1.size() == 1 && s2.size() == 1);
	return {s1[0], s2[0]};
}

vector<int> bipartition[2];

void dfs(int v, int p, int c){
	bipartition[c].push_back(v);
	for(int a : edges[v]){
		if(a == p) continue;
		dfs(a, v, 1 ^ c);
	}
}


vector<int> cycle;
int dfs2(int v, int p, int loc){
	int found = 0;
	if(loc == v) found = 1;
	for(int a : edges[v]){
		if(a == p) continue;
		if(dfs2(a, v, loc)) found = 1;
	}
	if(found){
		cycle.push_back(v);
	}
	return found;
}


int main(){
	cin >> n;
	edges.resize(n);
	vector<int> cc;
	cc.push_back(0);
	while(cc.size() < n){
		vector<int> s1 = cc;
		vector<int> s2;
		vector<int> freq(n, 1);
		for(int x : s1) freq[x] = 0;
		for(int i = 0; i < n; i++){
			if(freq[i]) s2.push_back(i);
		}

		pair<int,int> f = find_edge(s1, s2);
		edges[f.first].push_back(f.second);
		edges[f.second].push_back(f.first);
		cc.push_back(f.second);
	}
	// found a tree
	dfs(0, -1, 0);
	if(query(bipartition[0]) == 0 && query(bipartition[1]) == 0){
		cout << "Y " << bipartition[0].size() << endl;
		for(int a : bipartition[0]){
			cout << a + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
		return 0;
	}
	if(query(bipartition[0]) == 0){
		swap(bipartition[0], bipartition[1]);
	}
	assert(query(bipartition[0]) > 0);
	vector<int> bad = bipartition[0];
	while(bad.size() > 2){
		random_shuffle(bad.begin(), bad.end());
		vector<int> b[3];
		for(int i = 0; i < bad.size(); i++){
			b[i % 3].push_back(bad[i]);
			b[(i + 1) % 3].push_back(bad[i]);
		}
		assert(b[0].size() < bad.size());
		assert(b[1].size() < bad.size());
		assert(b[2].size() < bad.size());
		if(query(b[0]) > 0){
			bad = b[0];
		} else if(query(b[1]) > 0){
			bad = b[1];
		} else if(query(b[2]) > 0){
			bad = b[2];
		} else {
			assert(false);
		}
	}
	assert(bad.size() == 2);
	pair<int,int> f = {bad[0], bad[1]};
	dfs2(f.first, -1, f.second);
	assert((int)cycle.size() & 1);
	cout << "N " << cycle.size() << endl;
	for(int a : cycle){
		cout << a + 1 << " ";
	}
	cout << endl;
	fflush(stdout);
	return 0;
}