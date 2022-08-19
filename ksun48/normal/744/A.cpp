#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int par[110000];
int find(int a){
	if(a != par[a]) par[a] = find(par[a]);
	return par[a];
}
void join(int a, int b){
	par[find(a)] = find(b);
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) par[i] = i;
	int c[k];
	for(int i = 0; i < k; i++){
		cin >> c[i];
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		join(u,v);
	}
	int sz[n];
	int d[n];
	for(int i = 0; i < n; i++) d[i] = sz[i] = 0;
	for(int i = 0; i < n; i++){
		sz[find(i)]++;
	}
	for(int i = 0; i < k; i++){
		d[find(c[i]-1)] = 1;
	}
	vector<int> p;
	int j = 0;
	for(int i = 0; i < n; i++){
		if(d[i]){
			p.push_back(sz[i]);
		} else {
			j += sz[i];
		}
	}
	sort(p.begin(), p.end());
	p[p.size()-1] += j;
	int r = 0;
	for(int i = 0; i < p.size(); i++){
		r += p[i]*(p[i]-1)/2;
	}
	cout << r - m << endl;
}