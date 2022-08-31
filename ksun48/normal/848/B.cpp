#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> level[210000];
vector<int> ansx;
vector<int> ansy;
int main(){
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	vector<int> g, p, t;
	for(int i = 0; i < n; i++){
		ansx.push_back(-1); ansy.push_back(-1);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g.push_back(a);
		p.push_back(b);
		t.push_back(c);
		level[100000 + p[i] - t[i]].push_back(i);
	}
	for(int r = 0; r < 210000; r++){
		vector<pair<int,int> > a;
		vector<int> b;
		for(int j = 0; j < level[r].size(); j++){
			int id = level[r][j];
			int c;
			int d;
			if(g[id] == 2){
				c = -p[id];
				d = h - p[id];
			} else {
				c = p[id];
				d = p[id] - w;
			}
			a.push_back(make_pair(c,id));
			b.push_back(d);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int j = 0; j < b.size(); j++){
			int d = b[j];
			int nx, ny;
			if(d < 0){
				nx = d+w;
				ny = h;
			} else {
				nx = w;
				ny = h-d;
			}
			ansx[a[j].second] = nx;
			ansy[a[j].second] = ny;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d %d\n", ansx[i], ansy[i]);
	}
}