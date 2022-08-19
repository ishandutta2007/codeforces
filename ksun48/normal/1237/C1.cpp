#include <bits/stdc++.h>
using namespace std;

vector<int> x, y, z;
map<int, set<int> > c;
map<int, set<int> > xc, yc, zc;
map<pair<int,int>, set<int> > xyc, yzc, zxc;

void add(int i){
	c[0].insert(i);
	xc[x[i]].insert(i);
	yc[y[i]].insert(i);
	zc[z[i]].insert(i);
	xyc[{x[i], y[i]}].insert(i);
	yzc[{y[i], z[i]}].insert(i);
	zxc[{z[i], x[i]}].insert(i);
}

void del(int i){
	c[0].erase(i);
	xc[x[i]].erase(i);
	yc[y[i]].erase(i);
	zc[z[i]].erase(i);
	xyc[{x[i], y[i]}].erase(i);
	yzc[{y[i], z[i]}].erase(i);
	zxc[{z[i], x[i]}].erase(i);
}

void pr(int i, int j){
	cout << i + 1 << ' ' << j + 1 << '\n';
}

template<class T> void remove_pairs(T a){
	auto b = a;
	for(auto r : b){
		vector<pair<vector<int>, int> > f;
		for(auto i : r.second){
			f.push_back({{x[i], y[i], z[i]}, i});
		}
		sort(f.begin(), f.end());
		for(int a = 0; a+1 < (int)f.size(); a += 2){
			pr(f[a].second, f[a+1].second);
			del(f[a].second);
			del(f[a+1].second);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	x.resize(n), y.resize(n), z.resize(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> z[i];
	}
	for(int i = 0; i < n; i++){
		add(i);
	}
	remove_pairs(xyc);
	remove_pairs(yzc);
	remove_pairs(zxc);
	remove_pairs(xc);
	remove_pairs(yc);
	remove_pairs(zc);
	remove_pairs(c);
}