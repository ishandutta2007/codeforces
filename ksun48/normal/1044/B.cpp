#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > edges;

int found = -1;

int dfs(int v, int p, const vector<int>& in1){
	if(in1[v]){
		return v;
	}
	for(int a : edges[v]){
		if(a == p) continue;
		int x = dfs(a, v, in1);
		if(x != -1) return x;
	}
	return -1;
}
void solve(int t){
	int n;
	cin >> n;
	edges.clear();
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int k1;
	cin >> k1;
	vector<int> in1(n, 0);
	for(int i = 0; i < k1; i++){
		int x;
		fflush(stdout);
		cin >> x;
		x--; in1[x] = 1;
	}
	int k2;
	cin >> k2;
	vector<int> in2(n, 0);
	for(int i = 0; i < k2; i++){
		int x;
		cin >> x;
		x--; in2[x] = 1;
	}
	int bidx = -1;
	for(int i = 0; i < n; i++){
		if(in2[i]) bidx = i;
	}
	cout << "B" << " " << bidx + 1 << endl;
	fflush(stdout);
	int aidx = -1;
	cin >> aidx;
	assert(aidx != -1);
	aidx--; 
	if(in1[aidx]){
		cout << "C" << " " << aidx + 1 << endl;
		fflush(stdout);
		return;
	}
	int z = dfs(aidx, -1, in1);
	assert(z != -1);
	cout << "A" << " " << z + 1 << endl;
	fflush(stdout);
	int bz = -1;
	cin >> bz;
	assert(bz != -1);
	bz--;
	if(in2[bz]){
		cout << "C" << " " << z + 1 << endl;
		fflush(stdout);
		return;
	}
	cout << "C" << " " << -1 << endl;
	fflush(stdout);
	return;
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		fflush(stdout);
		solve(t);
	}
}